/*****************************************************************//**
 * @file   ModeServer.cpp
 * @brief  �e�탂�[�h���Ǘ�����T�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "ModeServer.h"
#include <stdexcept>
#include "../Application/ApplicationBase.h"
#include "../Input/InputManager.h"
#include "../Input/InputKeyboard.h"
#include "ModeBase.h"
#include "Fade/ModeFadeIn.h"
#include "Fade/ModeFadeOut.h"

namespace {
  constexpr auto FadeIn = "FadeIn";    //!< �t�F�[�h�C���o�^�p�L�[
  constexpr auto FadeOut = "FadeOut";  //!< �t�F�[�h�A�E�g�o�^�p�L�[
} // namespace

namespace AppFrame {
  namespace Mode {
    ModeServer::ModeServer(Application::ApplicationBase& app) : _app(app) {
      // �f�[�^�x�[�X�̏�����
      _modeRegistry.clear();
      // ���X�g�̏�����
      _modeList.clear();
      // �t�F�[�h�C���̓o�^
      AddMode(FadeIn, std::make_shared<Fade::ModeFadeIn>(_app));
      // �t�F�[�h�A�E�g�̓o�^
      AddMode(FadeOut, std::make_shared<Fade::ModeFadeOut>(_app));
    }

    ModeServer::~ModeServer() {

    }

    void ModeServer::Release() {
      // ���X�g���̃��[�h�̏I��
      for (auto&& mode : _modeList) {
        mode->Exit();
      }
      // �f�[�^�x�[�X�̉��
      _modeRegistry.clear();
      // ���X�g�̉��
      _modeList.clear();
    }

    void ModeServer::Process() {
      // �L�[�{�[�h�̓��͏����̎擾
      auto&& keyboard = _app.GetInputManager().GetKeyboard();
      // Escape�L�[��������Ă���ꍇ���f
      if (keyboard.GetKey(KEY_INPUT_ESCAPE, Input::InputPress)) {
        // �A�v���P�[�V�����̏I���v��
        _app.RequestTerminate();
        return;
      }
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

    void ModeServer::AddMode(const std::string_view key, const std::shared_ptr<ModeBase> mode) {
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

    void ModeServer::PushBack(const std::string_view key) {
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

    void ModeServer::TransionToMode(const std::string_view key) {
      // ���[�h�����Ԃɒǉ�
      InsertBeforeBack(key);
      InsertBeforeBack(FadeIn);
      PushBack(FadeOut);
    }

    bool ModeServer::ContainsMode(const std::string_view key) {
      return _modeRegistry.contains(key.data());
    }

    void ModeServer::InsertBeforeBack(const std::string_view key) {
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

    std::shared_ptr<ModeBase> ModeServer::FetchMode(const std::string_view key, const bool enter) {
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