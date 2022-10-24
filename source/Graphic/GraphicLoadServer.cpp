/*****************************************************************//**
 * @file   GraphicLoadServer.cpp
 * @brief  �摜��ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#include "GraphicLoadServer.h"
#include <DxLib.h>
#include "DivGraphData.h"

namespace AppFrame {
  namespace Graphic {
    GraphicLoadServer::GraphicLoadServer() {
      // ���W�X�g���̏�����
      _graphicRegistry.clear();
      _divGraphicRegistry.clear();
    }

    GraphicLoadServer::~GraphicLoadServer() {

    }

    void GraphicLoadServer::Release() {
      // �摜���W�X�g������łȂ��ꍇ
      if (!_graphicRegistry.empty()) {
        // �摜�n���h���̑S���
        for (auto&& [key, handle] : _graphicRegistry) {
          // �������ォ��摜�n���h���̍폜
          DeleteGraph(handle);
        }
        // �摜���W�X�g���̉��
        _graphicRegistry.clear();
      }
      // �����摜���W�X�g������łȂ��ꍇ
      if (!_divGraphicRegistry.empty()) {
        // �����摜�n���h���̑S���
        for (auto&& [key, handles] : _divGraphicRegistry) {
          // �����摜�n���h���̍폜
          DeleteDivGraphics(handles);
        }
        // �����摜���W�X�g���̉��
        _divGraphicRegistry.clear();
      }
    }

    void GraphicLoadServer::LoadGraphics(const LoadGraphicMap graphic) {
      // �R���e�i����f�[�^�̓ǂݍ���
      for (auto&& [key, path] : graphic) {
        // �摜�̓ǂݍ���
        LoadGraphic(key, path);
      }
    }

    void GraphicLoadServer::LoadDivGraphics(const LoadDivGraphicMap divGraph) {
      // �R���e�i����f�[�^�̓ǂݍ���
      for (auto&& [key, data] : divGraph) {
        // �����摜�̓ǂݍ���
        LoadDivGraphic(key, data);
      }
    }

    int GraphicLoadServer::GetGraphicHandle(const std::string_view key) const {
      // �L�[���L���łȂ��ꍇ-1
      if (!_graphicRegistry.contains(key.data())) {
#ifdef _DEBUG
        throw ("GraphicLoadServer:�摜�L�[���s���ł�\n");
#endif
        return -1;
      }
      // �摜�n���h����Ԃ�
      return _graphicRegistry.at(key.data());
    }

    std::vector<int> GraphicLoadServer::GetDivGraphicHandles(const std::string_view key) const {
      // �L�[���L���łȂ��ꍇ-1
      if (!_divGraphicRegistry.contains(key.data())) {
#ifdef _DEBUG
        throw ("GraphicLoadServer:�����摜�L�[���s���ł�\n");
#endif
        // �n���h�����i�[����R���e�i
        std::vector<int> handles{};
        // ��̃R���e�i��Ԃ�
        return handles;
      }
      // �摜�n���h����Ԃ�
      return _divGraphicRegistry.at(key.data());
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
        throw ("GraphicLoadServer:�摜�̓ǂݍ��݂Ɏ��s���܂���\n");
#endif
        return;  // �p�X���s��
      }
      // �摜���W�X�g���ɓo�^����
      _graphicRegistry.emplace(key.data(), handle);
    }

    void GraphicLoadServer::LoadDivGraphic(const std::string_view key, const DivGraphData divGraph) {
      // �L�[���o�^�ς݂̏ꍇ
      if (_divGraphicRegistry.contains(key.data())) {
        // �d�����Ă��镪���摜�n���h���̎擾
        auto duplicate = GetDivGraphicHandles(key);
        // �����摜�n���h���̍폜
        DeleteDivGraphics(duplicate);
        // �d�����Ă���f�[�^���폜
        _divGraphicRegistry.erase(key.data());
      }
      // �摜���̎擾
      auto path = divGraph.GetFilePath();
      auto [allNum, xNum, yNum] = divGraph.GetNumber();
      auto [xSize, ySize] = divGraph.GetSize();
      // �摜�n���h�����i�[����R���e�i��p��
      std::vector<int> handles{};
      handles.resize(allNum);
      // �����摜�̓ǂݍ���
      int load = LoadDivGraph(path.data(), allNum, xNum, yNum, xSize, ySize, handles.data());
      // �����摜�̓ǂݍ��݂Ɏ��s�����ꍇ�G���[
      if (load == -1) {
#ifdef _DEBUG
        throw ("GraphicLoadServer:�����摜�̓ǂݍ��݂Ɏ��s���܂���\n");
#endif
        return;  // �p�X���s��
      }
      // �����摜���W�X�g���ɓo�^����
      _divGraphicRegistry.emplace(key.data(), handles);
    }

    void GraphicLoadServer::DeleteDivGraphics(const std::vector<int> handles) {
      // �����摜�n���h���̑S�폜
      for (auto handle : handles) {
        // �������ォ��摜�n���h���̍폜
        DeleteGraph(handle);
      }
    }
  } // namespace Graphic
} // namespace AppFrame