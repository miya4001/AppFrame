/*****************************************************************//**
 * @file   ModeServer.cpp
 * @brief  �e�탂�[�h���Ǘ�����T�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "ModeServer.h"
#include <stdexcept>
#include "ModeBase.h"
#include "Fade/ModeFadeIn.h"
#include "Fade/ModeFadeOut.h"

namespace {
  constexpr auto FadeIn = "FadeIn";    //!< �t�F�[�h�C���o�^�p�L�[
  constexpr auto FadeOut = "FadeOut";  //!< �t�F�[�h�A�E�g�o�^�p�L�[
} // namespace

namespace AppFrame {
  namespace Mode {
    ModeServer::ModeServer(Application::ApplicationBase& app) {
      // �f�[�^�x�[�X�̏�����
      _modeRegistry.clear();
      // ���X�g�̏�����
      _modeList.clear();
      // �t�F�[�h�C���̓o�^
      AddMode(FadeIn, std::make_shared<Fade::ModeFadeIn>(app));
      // �t�F�[�h�A�E�g�̓o�^
      AddMode(FadeOut, std::make_shared<Fade::ModeFadeOut>(app));
    }

    ModeServer::~ModeServer() {

    }

    void ModeServer::Process() {
      // ���X�g����̏ꍇ���f
      if (_modeList.empty()) {
        return;  // ���o�^
      }
      // ���X�g�̖����̃��[�h�̍X�V
      _modeList.back()->Process();
    }

    void ModeServer::Draw() const {
      // ���X�g���̃��[�h�̕`��
      for (auto&& mode : _modeList) {
        mode->Draw();
      }
    }

    void ModeServer::AddMode(std::string_view key, std::shared_ptr<ModeBase> mode) {
      // �L�[���o�^�ς݂̏ꍇ
      if (ContainsMode(key)) {
        // �d�����Ă���Ώۂ��폜
        _modeRegistry.erase(key.data());
      }
      // ���[�h�̏�����
      mode->Init();
      // �f�[�^�x�[�X�ɓo�^����
      _modeRegistry.emplace(key.data(), mode);
    }

    void ModeServer::PushBack(std::string_view key) {
      // ���[�h�̎擾
      auto mode = FetchMode(key);
      // ���[�h�̎擾�Ɏ��s�����ꍇ�G���[
      if (mode == nullptr) {
#ifdef _DEBUG
        throw std::logic_error("ModeServer:���[�h�̎擾�Ɏ��s���܂���\n");
#endif
        return;  // �L�[���s��
      }
      // ���X�g�̖����ɒǉ�
      _modeList.push_back(mode);
    }

    void ModeServer::PopBuck() {
      // ���X�g����̏ꍇ���f
      if (_modeList.empty()) {
        return;  // ���o�^
      }
      // ���[�h�I������
      _modeList.back()->Exit();
      // �����̃��[�h���폜
      _modeList.pop_back();
    }

    void ModeServer::TransionToMode(std::string_view key) {
      // ���[�h�����Ԃɒǉ�
      InsertBeforeBack(key);
      InsertBeforeBack(FadeIn);
      PushBack(FadeOut);
    }

    bool ModeServer::ContainsMode(std::string_view key) {
      return _modeRegistry.contains(key.data());
    }

    void ModeServer::InsertBeforeBack(std::string_view key) {
      // ���[�h�̎擾
      auto mode = FetchMode(key);
      // ���[�h�̎擾�Ɏ��s�����ꍇ�G���[
      if (mode == nullptr) {
#ifdef _DEBUG
        throw std::logic_error("ModeServer:���[�h�̎擾�Ɏ��s���܂���\n");
#endif
        return;  // �L�[���s��
      }
      // ���X�g����̏ꍇ
      if (_modeList.empty()) {
        // ���X�g�̖����ɒǉ�
        _modeList.push_back(mode);
        return;
      }
      // ���X�g�̖����̒��O�ɒǉ�
      _modeList.insert(std::prev(_modeList.end()), mode);
    }

    std::shared_ptr<ModeBase> ModeServer::FetchMode(std::string_view key, const bool enter) {
      // �L�[�����o�^�̏ꍇnullptr
      if (!_modeRegistry.contains(key.data())) {
        return nullptr;
      }
      // �L�[�ɑΉ��������[�h�̎擾
      auto mode = _modeRegistry.at(key.data());
      // ���[�h�J�n�������s���ꍇ���s
      if (enter) {
        mode->Enter();
      }
      return mode;
    }
  } // namespace Mode
} // namespace AppFrame