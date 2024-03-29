/*****************************************************************//**
 * @file   ModeServer.cpp
 * @brief  各種モードを管理するサーバクラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "ModeServer.h"
#include <stdexcept>
#include "../Application/ApplicationBase.h"
#include "../Input/InputManager.h"
#include "../Input/InputKeyboard.h"
#include "ModeBase.h"
#include "Fade/ModeFadeIn.h"
#include "Fade/ModeFadeOut.h"

namespace {
  constexpr auto FadeIn = "FadeIn";    //!< フェードイン登録用キー
  constexpr auto FadeOut = "FadeOut";  //!< フェードアウト登録用キー
} // namespace

namespace AppFrame {
  namespace Mode {
    ModeServer::ModeServer(Application::ApplicationBase& app) : _app(app) {
      // データベースの初期化
      _modeRegistry.clear();
      // リストの初期化
      _modeList.clear();
      // フェードインの登録
      AddMode(FadeIn, std::make_shared<Fade::ModeFadeIn>(_app));
      // フェードアウトの登録
      AddMode(FadeOut, std::make_shared<Fade::ModeFadeOut>(_app));
    }

    ModeServer::~ModeServer() {

    }

    void ModeServer::Release() {
      // リスト内のモードの終了
      for (auto&& mode : _modeList) {
        mode->Exit();
      }
      // データベースの解放
      _modeRegistry.clear();
      // リストの解放
      _modeList.clear();
    }

    void ModeServer::Process() {
      // キーボードの入力処理の取得
      auto&& keyboard = _app.GetInputManager().GetKeyboard();
      // Escapeキーが押されている場合中断
      if (keyboard.GetKey(KEY_INPUT_ESCAPE, Input::InputPress)) {
        // アプリケーションの終了要請
        _app.RequestTerminate();
        return;
      }
      // リストが空の場合中断
      if (_modeList.empty()) {
        return;  // 未登録
      }
      // リストの末尾のモードの更新
      _modeList.back()->Process();
    }

    void ModeServer::Draw() const {
      // リスト内のモードの描画
      for (auto&& mode : _modeList) {
        mode->Draw();
      }
    }

    void ModeServer::AddMode(const std::string_view key, const std::shared_ptr<ModeBase> mode) {
      // キーが登録済みの場合
      if (ContainsMode(key)) {
        // 重複している対象を削除
        _modeRegistry.erase(key.data());
      }
      // モードの初期化
      mode->Init();
      // データベースに登録する
      _modeRegistry.emplace(key.data(), mode);
    }

    void ModeServer::PushBack(const std::string_view key) {
      // モードの取得
      auto mode = FetchMode(key);
      // モードの取得に失敗した場合エラー
      if (mode == nullptr) {
#ifdef _DEBUG
        throw std::logic_error("ModeServer:モードの取得に失敗しました\n");
#endif
        return;  // キーが不正
      }
      // リストの末尾に追加
      _modeList.push_back(mode);
    }

    void ModeServer::PopBuck() {
      // リストが空の場合中断
      if (_modeList.empty()) {
        return;  // 未登録
      }
      // モード終了処理
      _modeList.back()->Exit();
      // 末尾のモードを削除
      _modeList.pop_back();
    }

    void ModeServer::TransionToMode(const std::string_view key) {
      // モードを順番に追加
      InsertBeforeBack(key);
      InsertBeforeBack(FadeIn);
      PushBack(FadeOut);
    }

    bool ModeServer::ContainsMode(const std::string_view key) {
      return _modeRegistry.contains(key.data());
    }

    void ModeServer::InsertBeforeBack(const std::string_view key) {
      // モードの取得
      auto mode = FetchMode(key);
      // モードの取得に失敗した場合エラー
      if (mode == nullptr) {
#ifdef _DEBUG
        throw std::logic_error("ModeServer:モードの取得に失敗しました\n");
#endif
        return;  // キーが不正
      }
      // リストが空の場合
      if (_modeList.empty()) {
        // リストの末尾に追加
        _modeList.push_back(mode);
        return;
      }
      // リストの末尾の直前に追加
      _modeList.insert(std::prev(_modeList.end()), mode);
    }

    std::shared_ptr<ModeBase> ModeServer::FetchMode(const std::string_view key, const bool enter) {
      // キーが未登録の場合nullptr
      if (!_modeRegistry.contains(key.data())) {
        return nullptr;
      }
      // キーに対応したモードの取得
      auto mode = _modeRegistry.at(key.data());
      // モード開始処理を行う場合実行
      if (enter) {
        mode->Enter();
      }
      return mode;
    }
  } // namespace Mode
} // namespace AppFrame