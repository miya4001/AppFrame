/*****************************************************************//**
 * @file   ModelLoadServer.cpp
 * @brief  ���f����ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#include "ModelLoadServer.h"
#include <DxLib.h>
#include <stdexcept>

namespace AppFrame {
  namespace Model {
    ModelLoadServer::ModelLoadServer() {
      // ���W�X�g���̏�����
      _modelRegistry.clear();
    }

    ModelLoadServer::~ModelLoadServer() {

    }

    void ModelLoadServer::Release() {
      // ���W�X�g������̏ꍇ���f
      if (_modelRegistry.empty()) {
        return;
      }
      // ���f���n���h���̑S�J��
      for (auto [key, handle] : _modelRegistry) {
        // �������ォ�烂�f���n���h���̍폜
        MV1DeleteModel(handle);
      }
      // ���W�X�g���̉��
      _modelRegistry.clear();
    }

    void ModelLoadServer::LoadModels(const LoadModelMap model) {
      // �R���e�i����f�[�^�̓ǂݍ���
      for (auto [key, path] : model) {
        // ���f���̓ǂݍ���
        LoadModel(key, path);
      }
    }

    int ModelLoadServer::GetModelHandle(const std::string_view key) const {
      // �L�[���L���łȂ��ꍇ-1
      if (!_modelRegistry.contains(key.data())) {
        return -1;
      }
      // ���f���n���h����Ԃ�
      return _modelRegistry.at(key.data());
    }

    void ModelLoadServer::LoadModel(const std::string_view key, const std::string_view path) {
      // �L�[���o�^�ς݂̏ꍇ
      if (_modelRegistry.contains(key.data())) {
        // �d�����Ă��郂�f���n���h���̎擾
        int duplicate = GetModelHandle(key);
        // �������ォ�烂�f���n���h���̍폜
        MV1DeleteModel(duplicate);
        // �d�����Ă���f�[�^���폜
        _modelRegistry.erase(key.data());
      }
      // ���f���̓ǂݍ���
      int handle = MV1LoadModel(path.data());
      // ���f���̓ǂݍ��݂Ɏ��s�����ꍇ�G���[
      if (handle == -1) {
#ifdef _DEBUG
        throw std::logic_error("ModelLoadServer:���f���̓ǂݍ��݂Ɏ��s���܂���\n");
#endif
        return;  // �p�X���s��
      }
      // ���W�X�g���ɓo�^����
      _modelRegistry.emplace(key.data(), handle);
    }
  }
  } // namespace Model
} // namespace AppFrame