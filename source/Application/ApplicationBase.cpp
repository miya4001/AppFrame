/*****************************************************************//**
 * @file   ApplicationBase.cpp
 * @brief  アプリケーションの基底クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "ApplicationBase.h"
#include <DxLib.h>
#include <EffekseerForDXLib.h>
#include <stdexcept>
#include "../Input/InputManager.h"
#include "../Graphic/GraphicLoadServer.h"
#include "../Mode/ModeServer.h"

namespace {
  constexpr int Error = -1;  //!< エラー
} // namespace

namespace AppFrame {
  namespace Application {
    ApplicationBase::ApplicationBase() {
      // 画面モード切り替え
#ifdef _DEBUG
      _windowMode = true;   //ウィンドウ
#else
      _windowMode = false;  // フルスクリーン
#endif
    }

    ApplicationBase::~ApplicationBase() {

    }

    bool ApplicationBase::Init() {
      // DXライブラリの初期化
      if (!DxLibInit()) {
        return false;  // 初期化失敗
      }
      //Effekseerの初期化
      if (!EffekseerInit()) {
        return false;  // 初期化失敗
      }
      // インプットマネージャーの生成
      _inputManager = std::make_unique<Input::InputManager>(*this);
      // 画像読み込みサーバの生成
      _graphicLoadServer = std::make_unique<Graphic::GraphicLoadServer>();
      // モードサーバの生成
      _modeServer = std::make_unique<Mode::ModeServer>(*this);
      return true;  // 初期化成功
    }

    void ApplicationBase::Run() {
      // メインループ
      while (ProcessMessage() != Error) {
        // アプリケーションを終了する場合
        if (_appState == AppState::Quit) {
          break;  // ループを抜ける
        }
#ifdef _DEBUG
        try {
          Input();    // 入力
          Process();  // 更新
          Draw();     // 描画
        }
        catch (std::logic_error error) {
          // 例外発生時、出力を行う
          OutputDebugString(error.what());
        }
#else
        Input();    // 入力
        Process();  // 更新
        Draw();     // 描画
#endif
      }
    }

    void ApplicationBase::Terminate() {
      // 各種解放
      Release();
      // Effekseerの終了
      Effkseer_End();
      // DXライブラリの終了
      DxLib_End();
    }

    void ApplicationBase::RequestTerminate() {
      // アプリケーションが終了状態ではない場合
      if (_appState != AppState::Quit) {
        _appState = AppState::Quit;  // 終了
      }
    }

    void ApplicationBase::Release() {
      // 画像読み込みサーバの解放
      _graphicLoadServer->Release();
      // モードサーバの解放
      _modeServer->Release();
    }

    void ApplicationBase::Input() {
      // インプットマネージャーの更新
      _inputManager->Process();
    }

    void ApplicationBase::Process() {
      // モードサーバの更新
      _modeServer->Process();
    }

    void ApplicationBase::Draw() {
      // 画面をクリア
      ClearDrawScreen();
      // モードサーバの描画
      _modeServer->Draw();
      // 裏画面の内容を表画面に反映
      ScreenFlip();
    }

    bool ApplicationBase::DxLibInit() {
      // ログファイルの出力設定
      SetOutApplicationLogValidFlag(_windowMode);
      // 画面モードの変更
      SetGraphMode(ScreenWidth, ScreenHeight, ColorBit);
      ChangeWindowMode(_windowMode);
      // DXライブラリの初期化
      if (DxLib_Init() == Error) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:DXライブラリの初期化に失敗しました\n");
#endif
        return false;  // 初期化失敗
      }
      // 裏面描画の設定
      SetDrawScreen(DX_SCREEN_BACK);
      // 背景色の設定
      SetBackgroundColor(0, 0, 255);
      // Zバッファの設定
      SetUseZBuffer3D(true);    // 使用する
      SetWriteZBuffer3D(true);  // 書き込みを行う
      return true;  // 初期化成功
    }

    bool ApplicationBase::EffekseerInit() {
      // DirectX11を使用
      SetUseDirect3DVersion(DX_DIRECT3D_11);
      // Effekseerの初期化
      if (Effekseer_Init(Particle) == Error) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:Effekseerの初期化に失敗しました\n");
#endif
        return false;  // 初期化失敗
      }
      // フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ
      SetChangeScreenModeGraphicsSystemResetFlag(false);
      // DXライブラリのデバイスロストした時のコールバックを設定
      Effekseer_SetGraphicsDeviceLostCallbackFunctions();
      return true;  // 初期化成功
    }

    bool ApplicationBase::IsSetApplication() {
      // アプリケーション未生成
      if (!_isSetApp) {
        if (_application == nullptr) {
          _isSetApp = true;
          return true;  // 生成する
        }
      }
      return false;  // 生成しない
    }

    Input::InputManager& ApplicationBase::GetInputManager() {
      return *_inputManager;
    }

    Graphic::GraphicLoadServer& ApplicationBase::GetGraphicLoadServer() {
      return *_graphicLoadServer;
    }

    Mode::ModeServer& ApplicationBase::GetModeServer() {
      return *_modeServer;
    }
  } // namespace Application
} // namespace AppFrame