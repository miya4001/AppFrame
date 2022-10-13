/*****************************************************************//**
 * @file   SoundComponent.cpp
 * @brief  �����R���|�[�l���g
 * 
 * @author �{�V�s��
 * @date   October 2022
 *********************************************************************/
#include "SoundComponent.h"
#include <DxLib.h>
#include <algorithm>
#include "../Application/ApplicationBase.h"
#include "SoundLoadServer.h"

namespace {
  constexpr int VolumeMin = 0;    //!< �ŏ�����
  constexpr int VolumeMax = 255;  //!< �ő剹��
}

namespace AppFrame {
  namespace Sound {
    SoundComponent::SoundComponent(Application::ApplicationBase& app) : _app(app) {

    }

    SoundComponent::~SoundComponent() {

    }

    void SoundComponent::PlayBackGround(const std::string_view key, const int volume) {
      // �����̍Đ�
      Play(key, DX_PLAYTYPE_BACK);
      // �����̉��ʂ̐ݒ�
      SetVolume(key, volume);
    }

    void SoundComponent::PlayLoop(const std::string_view key, const int volume) {
      // �����̍Đ�
      Play(key, DX_PLAYTYPE_LOOP);
      // �����̉��ʂ̐ݒ�
      SetVolume(key, volume);
    }

    void SoundComponent::StopSound(const std::string_view key) {
      // �����n���h���̎擾
      int handle = GetSoundHandle(key);
      // �������Đ�����Ă��Ȃ��ꍇ���f
      if (!CheckSound(key)) {
        return;
      }
      // �����̍Đ���~
      StopSoundMem(handle);
    }

    bool SoundComponent::CheckSound(const std::string_view key) {
      // �����n���h���̎擾
      int handle = GetSoundHandle(key);
      // �����̍Đ�����
      bool flag = CheckSoundMem(handle) == 1;
      return flag;
    }

    void SoundComponent::Play(const std::string_view key, const int type) {
      // �����n���h���̎擾
      int handle = GetSoundHandle(key);
      // �����̍Đ�
      int play = PlaySoundMem(handle, type, true);
      // �����̍Đ��Ɏ��s�����ꍇ�G���[
      if (play == -1) {
#ifdef _DEBUG
        throw ("SoundComponent:�����̍Đ��Ɏ��s���܂���\n");
#endif
      }
    }

    void SoundComponent::SetVolume(const std::string_view key, const int volume) {
      // �����n���h���̎擾
      int handle = GetSoundHandle(key);
      // ���ʂ̃N�����v����
      int clampVolume = std::clamp(volume, VolumeMin, VolumeMax);
      // �����̉��ʂ̐ݒ�
      ChangeVolumeSoundMem(clampVolume, handle);
    }

    int SoundComponent::GetSoundHandle(const std::string_view key) {
      // �w�肵�������n���h���̎擾
      return _app.GetSoundLoadServer().GetSoundHandle(key);
    }
  } // namespace Sound
} // namespace AppFrame