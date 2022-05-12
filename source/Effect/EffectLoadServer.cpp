/*****************************************************************//**
 * @file   EffectLoadServer.cpp
 * @brief  エフェクトを読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#include "EffectLoadServer.h"
#include <EffekseerForDXLib.h>
#include <stdexcept>

namespace AppFrame {
  namespace Effect {
    EffectLoadServer::EffectLoadServer() {
      // レジストリの初期化
      _effectRegistry.clear();
    }

    EffectLoadServer::~EffectLoadServer() {

    }

    void EffectLoadServer::Release() {
      // レジストリが空の場合中断
      if (_effectRegistry.empty()) {
        return;
      }
      // エフェクトハンドルの全開放
      for (auto [key, handle] : _effectRegistry) {
        // メモリ上からエフェクトハンドルの削除
        DeleteEffekseerEffect(handle);
      }
      // レジストリの解放
      _effectRegistry.clear();
    }

    void EffectLoadServer::LoadEffects(const LoadEffectMap effect) {
      // コンテナからデータの読み込み
      for (auto [key, path, magni] : effect) {
        // エフェクトの読み込み
        LoadEffect(key, path, magni);
      }
    }

    int EffectLoadServer::GetEffectHandle(const std::string_view key) const {
      // キーが有効でない場合-1
      if (!_effectRegistry.contains(key.data())) {
        return -1;
      }
      // エフェクトハンドルを返す
      return _effectRegistry.at(key.data());
    }

    void EffectLoadServer::LoadEffect(const std::string_view key, const std::string_view path, const float magni) {
      // キーが登録済みの場合
      if (_effectRegistry.contains(key.data())) {
        // 重複しているエフェクトハンドルの取得
        int duplicate = GetEffectHandle(key);
        // メモリ上からエフェクトハンドルの削除
        DeleteEffekseerEffect(duplicate);
        // 重複しているデータを削除
        _effectRegistry.erase(key.data());
      }
      // エフェクトの読み込み
      int handle = LoadEffekseerEffect(path.data(), magni);
      // エフェクトの読み込みに失敗した場合エラー
      if (handle == -1) {
#ifdef _DEBUG
        throw std::logic_error("EffectLoadServer:エフェクトの読み込みに失敗しました\n");
#endif
        return;  // パスが不正
      }
      // レジストリに登録する
      _effectRegistry.emplace(key.data(), handle);
    }
  } // namespace Effect
} // namespace AppFrame