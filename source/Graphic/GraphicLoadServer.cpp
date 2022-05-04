/*****************************************************************//**
 * @file   GraphicLoadServer.cpp
 * @brief  �摜��ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#include "GraphicLoadServer.h"
#include <DxLib.h>
#include <stdexcept>

namespace AppFrame {
  namespace Graphic {
    GraphicLoadServer::GraphicLoadServer() {
      // ���W�X�g���̏�����
      _graphicRegistry.clear();
    }

    GraphicLoadServer::~GraphicLoadServer() {

    }

    void GraphicLoadServer::Release() {
      // ���W�X�g������̏ꍇ���f
      if (_graphicRegistry.empty()) {
        return;
      }
      // �摜�n���h���̑S�J��
      for (auto [key, handle] : _graphicRegistry) {
        // �������ォ��摜�n���h���̍폜
        DeleteGraph(handle);
      }
      // ���W�X�g���̉��
      _graphicRegistry.clear();
    }

    void GraphicLoadServer::LoadGraphics(const LoadGraphicMap graphic) {
      // �R���e�i����f�[�^�̓ǂݍ���
      for (auto [key, path] : graphic) {
        // �摜�̓ǂݍ���
        LoadGraphic(key, path);
      }
    }

    int GraphicLoadServer::GetGraphicHandle(const std::string_view key) const {
      // �L�[���L���łȂ��ꍇ-1
      if (_graphicRegistry.contains(key.data())) {
        return -1;
      }
      // �摜�n���h����Ԃ�
      return _graphicRegistry.at(key.data());
    }

    void GraphicLoadServer::LoadGraphic(const std::string_view key, const std::string_view path) {
      // �L�[���o�^�ς݂̏ꍇ
      if (_graphicRegistry.contains(key.data())) {
        // �d�����Ă���摜�n���h���̎擾
        int duplicate = GetGraphicHandle(key);
        // �������ォ��摜�n���h���̍폜
        DeleteGraph(duplicate);
        // �d�����Ă���f�[�^���폜
        _graphicRegistry.erase(key.data());
      }
      // �摜�̓ǂݍ���
      int handle = LoadGraph(path.data());
      // �摜�̓ǂݍ��݂Ɏ��s�����ꍇ�G���[
      if (handle == -1) {
#ifdef _DEBUG
        throw std::logic_error("GraphicLoadServer:�摜�̓ǂݍ��݂Ɏ��s���܂���\n");
#endif
        return;  // �p�X���s��
      }
      // ���W�X�g���ɓo�^����
      _graphicRegistry.emplace(key.data(), handle);
    }
  } // namespace Graphic
} // namespace AppFrame