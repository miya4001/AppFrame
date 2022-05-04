/*****************************************************************//**
 * @file   GraphicLoadServer.cpp
 * @brief  画像を読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#include "GraphicLoadServer.h"
#include <DxLib.h>
#include <stdexcept>

namespace AppFrame {
  namespace Graphic {
    GraphicLoadServer::GraphicLoadServer() {
      // レジストリの初期化
      _graphicRegistry.clear();
    }

    GraphicLoadServer::~GraphicLoadServer() {

    }

    void GraphicLoadServer::Release() {
      // レジストリが空の場合中断
      if (_graphicRegistry.empty()) {
        return;
      }
      // 画像ハンドルの全開放
      for (auto [key, handle] : _graphicRegistry) {
        // メモリ上から画像ハンドルの削除
        DeleteGraph(handle);
      }
      // レジストリの解放
      _graphicRegistry.clear();
    }

    void GraphicLoadServer::LoadGraphics(const LoadGraphicMap graphic) {
      // コンテナからデータの読み込み
      for (auto [key, path] : graphic) {
        // 画像の読み込み
        LoadGraphic(key, path);
      }
    }

    int GraphicLoadServer::GetGraphicHandle(const std::string_view key) const {
      // キーが有効でない場合-1
      if (_graphicRegistry.contains(key.data())) {
        return -1;
      }
      // 画像ハンドルを返す
      return _graphicRegistry.at(key.data());
    }

    void GraphicLoadServer::LoadGraphic(const std::string_view key, const std::string_view path) {
      // キーが登録済みの場合
      if (_graphicRegistry.contains(key.data())) {
        // 重複している画像ハンドルの取得
        int duplicate = GetGraphicHandle(key);
        // メモリ上から画像ハンドルの削除
        DeleteGraph(duplicate);
        // 重複しているデータを削除
        _graphicRegistry.erase(key.data());
      }
      // 画像の読み込み
      int handle = LoadGraph(path.data());
      // 画像の読み込みに失敗した場合エラー
      if (handle == -1) {
#ifdef _DEBUG
        throw std::logic_error("GraphicLoadServer:画像の読み込みに失敗しました\n");
#endif
        return;  // パスが不正
      }
      // レジストリに登録する
      _graphicRegistry.emplace(key.data(), handle);
    }
  } // namespace Graphic
} // namespace AppFrame