/*****************************************************************//**
 * @file   EffectLoadServer.cpp
 * @brief  �G�t�F�N�g��ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#include "EffectLoadServer.h"
#include <EffekseerForDXLib.h>
#include <stdexcept>

namespace AppFrame {
  namespace Effect {
    EffectLoadServer::EffectLoadServer() {
      // ���W�X�g���̏�����
      _effectRegistry.clear();
    }

    EffectLoadServer::~EffectLoadServer() {

    }

    void EffectLoadServer::Release() {
      // ���W�X�g������̏ꍇ���f
      if (_effectRegistry.empty()) {
        return;
      }
      // �G�t�F�N�g�n���h���̑S�J��
      for (auto [key, handle] : _effectRegistry) {
        // �������ォ��G�t�F�N�g�n���h���̍폜
        DeleteEffekseerEffect(handle);
      }
      // ���W�X�g���̉��
      _effectRegistry.clear();
    }

    void EffectLoadServer::LoadEffects(const LoadEffectMap effect) {
      // �R���e�i����f�[�^�̓ǂݍ���
      for (auto [key, path, magni] : effect) {
        // �G�t�F�N�g�̓ǂݍ���
        LoadEffect(key, path, magni);
      }
    }

    int EffectLoadServer::GetEffectHandle(const std::string_view key) const {
      // �L�[���L���łȂ��ꍇ-1
      if (!_effectRegistry.contains(key.data())) {
        return -1;
      }
      // �G�t�F�N�g�n���h����Ԃ�
      return _effectRegistry.at(key.data());
    }

    void EffectLoadServer::LoadEffect(const std::string_view key, const std::string_view path, const float magni) {
      // �L�[���o�^�ς݂̏ꍇ
      if (_effectRegistry.contains(key.data())) {
        // �d�����Ă���G�t�F�N�g�n���h���̎擾
        int duplicate = GetEffectHandle(key);
        // �������ォ��G�t�F�N�g�n���h���̍폜
        DeleteEffekseerEffect(duplicate);
        // �d�����Ă���f�[�^���폜
        _effectRegistry.erase(key.data());
      }
      // �G�t�F�N�g�̓ǂݍ���
      int handle = LoadEffekseerEffect(path.data(), magni);
      // �G�t�F�N�g�̓ǂݍ��݂Ɏ��s�����ꍇ�G���[
      if (handle == -1) {
#ifdef _DEBUG
        throw std::logic_error("EffectLoadServer:�G�t�F�N�g�̓ǂݍ��݂Ɏ��s���܂���\n");
#endif
        return;  // �p�X���s��
      }
      // ���W�X�g���ɓo�^����
      _effectRegistry.emplace(key.data(), handle);
    }
  } // namespace Effect
} // namespace AppFrame