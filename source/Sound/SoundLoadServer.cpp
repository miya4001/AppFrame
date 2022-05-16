/*****************************************************************//**
 * @file   SoundLoadServer.cpp
 * @brief  ������ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#include "SoundLoadServer.h"
#include <DxLib.h>

namespace AppFrame {
  namespace Sound {
    SoundLoadServer::SoundLoadServer() {
      // ���W�X�g���̏�����
      _soundRegistry.clear();
    }

    SoundLoadServer::~SoundLoadServer() {

    }

    void SoundLoadServer::Release() {
      // ���W�X�g������̏ꍇ���f
      if (_soundRegistry.empty()) {
        return;
      }
      // �����n���h���̑S�J��
      for (auto [key, handle] : _soundRegistry) {
        // �������ォ�特���n���h���̍폜
        DeleteSoundMem(handle);
      }
      // ���W�X�g���̉��
      _soundRegistry.clear();
    }

    void SoundLoadServer::LoadSounds(const LoadSoundMap sound) {
      // �R���e�i����f�[�^�̓ǂݍ���
      for (auto [key, path] : sound) {
        // �����̓ǂݍ���
        LoadSound(key, path);
      }
    }

    int SoundLoadServer::GetSoundHandle(const std::string_view key) const {
      // �L�[���L���łȂ��ꍇ-1
      if (!_soundRegistry.contains(key.data())) {
        return -1;
      }
      // �����n���h����Ԃ�
      return _soundRegistry.at(key.data());
    }

    void SoundLoadServer::LoadSound(const std::string_view key, const std::string_view path) {
      // �L�[���o�^�ς݂̏ꍇ
      if (_soundRegistry.contains(key.data())) {
        // �d�����Ă��鉹���n���h���̎擾
        int duplicate = GetSoundHandle(key);
        // �������ォ�特���n���h���̍폜
        DeleteSoundMem(duplicate);
        // �d�����Ă���f�[�^���폜
        _soundRegistry.erase(key.data());
      }
      // �����̓ǂݍ���
      int handle = LoadSoundMem(path.data());
      // �����̓ǂݍ��݂Ɏ��s�����ꍇ�G���[
      if (handle == -1) {
#ifdef _DEBUG
        throw ("SoundLoadServer:�����̓ǂݍ��݂Ɏ��s���܂���\n");
#endif
        return;  // �p�X���s��
      }
      // ���W�X�g���ɓo�^����
      _soundRegistry.emplace(key.data(), handle);
    }
  } // namespace Sound
} // namespace AppFrame