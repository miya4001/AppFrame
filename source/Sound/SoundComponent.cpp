/*****************************************************************//**
 * @file   SoundComponent.cpp
 * @brief  音源コンポーネント
 * 
 * @author 宮澤耀生
 * @date   October 2022
 *********************************************************************/
#include "SoundComponent.h"
#include <DxLib.h>
#include <algorithm>
#include "../Application/ApplicationBase.h"
#include "SoundLoadServer.h"

namespace {
  constexpr int VolumeMin = 0;    //!< 最小音量
  constexpr int VolumeMax = 255;  //!< 最大音量
}

namespace AppFrame {
  namespace Sound {
    SoundComponent::SoundComponent(Application::ApplicationBase& app) : _app(app) {

    }

    SoundComponent::~SoundComponent() {

    }

    void SoundComponent::PlayBackGround(const std::string_view key, const int volume) {
      // 音源の再生
      Play(key, DX_PLAYTYPE_BACK);
      // 音源の音量の設定
      SetVolume(key, volume);
    }

    void SoundComponent::PlayLoop(const std::string_view key, const int volume) {
      // 音源の再生
      Play(key, DX_PLAYTYPE_LOOP);
      // 音源の音量の設定
      SetVolume(key, volume);
    }

    void SoundComponent::StopSound(const std::string_view key) {
      // 音源ハンドルの取得
      int handle = GetSoundHandle(key);
      // 音源が再生されていない場合中断
      if (!CheckSound(key)) {
        return;
      }
      // 音源の再生停止
      StopSoundMem(handle);
    }

    bool SoundComponent::CheckSound(const std::string_view key) {
      // 音源ハンドルの取得
      int handle = GetSoundHandle(key);
      // 音源の再生判定
      bool flag = CheckSoundMem(handle) == 1;
      return flag;
    }

    void SoundComponent::Play(const std::string_view key, const int type) {
      // 音源ハンドルの取得
      int handle = GetSoundHandle(key);
      // 音源の再生
      int play = PlaySoundMem(handle, type, true);
      // 音源の再生に失敗した場合エラー
      if (play == -1) {
#ifdef _DEBUG
        throw ("SoundComponent:音源の再生に失敗しました\n");
#endif
      }
    }

    void SoundComponent::SetVolume(const std::string_view key, const int volume) {
      // 音源ハンドルの取得
      int handle = GetSoundHandle(key);
      // 音量のクランプ処理
      int clampVolume = std::clamp(volume, VolumeMin, VolumeMax);
      // 音源の音量の設定
      ChangeVolumeSoundMem(clampVolume, handle);
    }

    int SoundComponent::GetSoundHandle(const std::string_view key) {
      // 指定した音源ハンドルの取得
      return _app.GetSoundLoadServer().GetSoundHandle(key);
    }
  } // namespace Sound
} // namespace AppFrame