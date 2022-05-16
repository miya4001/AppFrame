/*****************************************************************//**
 * @file   SoundLoadServer.cpp
 * @brief  音源を読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#include "SoundLoadServer.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Sound {
    SoundLoadServer::SoundLoadServer() {
      // レジストリの初期化
      _soundRegistry.clear();
    }

    SoundLoadServer::~SoundLoadServer() {

    }

    void SoundLoadServer::Release() {
      // レジストリが空の場合中断
      if (_soundRegistry.empty()) {
        return;
      }
      // 音源ハンドルの全開放
      for (auto [key, handle] : _soundRegistry) {
        // メモリ上から音源ハンドルの削除
        DeleteSoundMem(handle);
      }
      // レジストリの解放
      _soundRegistry.clear();
    }

    void SoundLoadServer::LoadSounds(const LoadSoundMap sound) {
      // コンテナからデータの読み込み
      for (auto [key, path] : sound) {
        // 音源の読み込み
        LoadSound(key, path);
      }
    }

    int SoundLoadServer::GetSoundHandle(const std::string_view key) const {
      // キーが有効でない場合-1
      if (!_soundRegistry.contains(key.data())) {
        return -1;
      }
      // 音源ハンドルを返す
      return _soundRegistry.at(key.data());
    }

    void SoundLoadServer::LoadSound(const std::string_view key, const std::string_view path) {
      // キーが登録済みの場合
      if (_soundRegistry.contains(key.data())) {
        // 重複している音源ハンドルの取得
        int duplicate = GetSoundHandle(key);
        // メモリ上から音源ハンドルの削除
        DeleteSoundMem(duplicate);
        // 重複しているデータを削除
        _soundRegistry.erase(key.data());
      }
      // 音源の読み込み
      int handle = LoadSoundMem(path.data());
      // 音源の読み込みに失敗した場合エラー
      if (handle == -1) {
#ifdef _DEBUG
        throw ("SoundLoadServer:音源の読み込みに失敗しました\n");
#endif
        return;  // パスが不正
      }
      // レジストリに登録する
      _soundRegistry.emplace(key.data(), handle);
    }
  } // namespace Sound
} // namespace AppFrame