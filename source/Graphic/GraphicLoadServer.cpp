/*****************************************************************//**
 * @file   GraphicLoadServer.cpp
 * @brief  画像を読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#include "GraphicLoadServer.h"
#include <DxLib.h>
#include "DivGraphData.h"

namespace AppFrame {
  namespace Graphic {
    GraphicLoadServer::GraphicLoadServer() {
      // レジストリの初期化
      _graphicRegistry.clear();
      _divGraphicRegistry.clear();
    }

    GraphicLoadServer::~GraphicLoadServer() {

    }

    void GraphicLoadServer::Release() {
      // 画像レジストリが空でない場合
      if (!_graphicRegistry.empty()) {
        // 画像ハンドルの全解放
        for (auto&& [key, handle] : _graphicRegistry) {
          // メモリ上から画像ハンドルの削除
          DeleteGraph(handle);
        }
        // 画像レジストリの解放
        _graphicRegistry.clear();
      }
      // 分割画像レジストリが空でない場合
      if (!_divGraphicRegistry.empty()) {
        // 分割画像ハンドルの全解放
        for (auto&& [key, handles] : _divGraphicRegistry) {
          // 分割画像ハンドルの削除
          DeleteDivGraphics(handles);
        }
        // 分割画像レジストリの解放
        _divGraphicRegistry.clear();
      }
    }

    void GraphicLoadServer::LoadGraphics(const LoadGraphicMap graphic) {
      // コンテナからデータの読み込み
      for (auto&& [key, path] : graphic) {
        // 画像の読み込み
        LoadGraphic(key, path);
      }
    }

    void GraphicLoadServer::LoadDivGraphics(const LoadDivGraphicMap divGraph) {
      // コンテナからデータの読み込み
      for (auto&& [key, data] : divGraph) {
        // 分割画像の読み込み
        LoadDivGraphic(key, data);
      }
    }

    int GraphicLoadServer::GetGraphicHandle(const std::string_view key) const {
      // キーが有効でない場合-1
      if (!_graphicRegistry.contains(key.data())) {
#ifdef _DEBUG
        throw ("GraphicLoadServer:画像キーが不正です\n");
#endif
        return -1;
      }
      // 画像ハンドルを返す
      return _graphicRegistry.at(key.data());
    }

    std::vector<int> GraphicLoadServer::GetDivGraphicHandles(const std::string_view key) const {
      // キーが有効でない場合-1
      if (!_divGraphicRegistry.contains(key.data())) {
#ifdef _DEBUG
        throw ("GraphicLoadServer:分割画像キーが不正です\n");
#endif
        // ハンドルを格納するコンテナ
        std::vector<int> handles{};
        // 空のコンテナを返す
        return handles;
      }
      // 画像ハンドルを返す
      return _divGraphicRegistry.at(key.data());
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
        throw ("GraphicLoadServer:画像の読み込みに失敗しました\n");
#endif
        return;  // パスが不正
      }
      // 画像レジストリに登録する
      _graphicRegistry.emplace(key.data(), handle);
    }

    void GraphicLoadServer::LoadDivGraphic(const std::string_view key, const DivGraphData divGraph) {
      // キーが登録済みの場合
      if (_divGraphicRegistry.contains(key.data())) {
        // 重複している分割画像ハンドルの取得
        auto duplicate = GetDivGraphicHandles(key);
        // 分割画像ハンドルの削除
        DeleteDivGraphics(duplicate);
        // 重複しているデータを削除
        _divGraphicRegistry.erase(key.data());
      }
      // 画像情報の取得
      auto path = divGraph.GetFilePath();
      auto [allNum, xNum, yNum] = divGraph.GetNumber();
      auto [xSize, ySize] = divGraph.GetSize();
      // 画像ハンドルを格納するコンテナを用意
      std::vector<int> handles{};
      handles.resize(allNum);
      // 分割画像の読み込み
      int load = LoadDivGraph(path.data(), allNum, xNum, yNum, xSize, ySize, handles.data());
      // 分割画像の読み込みに失敗した場合エラー
      if (load == -1) {
#ifdef _DEBUG
        throw ("GraphicLoadServer:分割画像の読み込みに失敗しました\n");
#endif
        return;  // パスが不正
      }
      // 分割画像レジストリに登録する
      _divGraphicRegistry.emplace(key.data(), handles);
    }

    void GraphicLoadServer::DeleteDivGraphics(const std::vector<int> handles) {
      // 分割画像ハンドルの全削除
      for (auto handle : handles) {
        // メモリ上から画像ハンドルの削除
        DeleteGraph(handle);
      }
    }
  } // namespace Graphic
} // namespace AppFrame