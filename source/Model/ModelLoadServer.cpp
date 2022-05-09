/*****************************************************************//**
 * @file   ModelLoadServer.cpp
 * @brief  モデルを読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#include "ModelLoadServer.h"
#include <DxLib.h>
#include <stdexcept>

namespace AppFrame {
  namespace Model {
    ModelLoadServer::ModelLoadServer() {
      // レジストリの初期化
      _modelRegistry.clear();
    }

    ModelLoadServer::~ModelLoadServer() {

    }

    void ModelLoadServer::Release() {
      // レジストリが空の場合中断
      if (_modelRegistry.empty()) {
        return;
      }
      // モデルハンドルの全開放
      for (auto [key, handle] : _modelRegistry) {
        // メモリ上からモデルハンドルの削除
        MV1DeleteModel(handle);
      }
      // レジストリの解放
      _modelRegistry.clear();
    }

    void ModelLoadServer::LoadModels(const LoadModelMap model) {
      // コンテナからデータの読み込み
      for (auto [key, path] : model) {
        // モデルの読み込み
        LoadModel(key, path);
      }
    }

    int ModelLoadServer::GetModelHandle(const std::string_view key) const {
      // キーが有効でない場合-1
      if (!_modelRegistry.contains(key.data())) {
        return -1;
      }
      // モデルハンドルを返す
      return _modelRegistry.at(key.data());
    }

    void ModelLoadServer::LoadModel(const std::string_view key, const std::string_view path) {
      // キーが登録済みの場合
      if (_modelRegistry.contains(key.data())) {
        // 重複しているモデルハンドルの取得
        int duplicate = GetModelHandle(key);
        // メモリ上からモデルハンドルの削除
        MV1DeleteModel(duplicate);
        // 重複しているデータを削除
        _modelRegistry.erase(key.data());
      }
      // モデルの読み込み
      int handle = MV1LoadModel(path.data());
      // モデルの読み込みに失敗した場合エラー
      if (handle == -1) {
#ifdef _DEBUG
        throw std::logic_error("ModelLoadServer:モデルの読み込みに失敗しました\n");
#endif
        return;  // パスが不正
      }
      // レジストリに登録する
      _modelRegistry.emplace(key.data(), handle);
    }
  }
  } // namespace Model
} // namespace AppFrame