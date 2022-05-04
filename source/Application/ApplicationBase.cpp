/*****************************************************************//**
 * @file   ApplicationBase.cpp
 * @brief  �A�v���P�[�V�����̊��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "ApplicationBase.h"
#include <DxLib.h>
#include <EffekseerForDXLib.h>
#include <stdexcept>
#include "../Input/InputManager.h"
#include "../Graphic/GraphicLoadServer.h"
#include "../Mode/ModeServer.h"

namespace {
  constexpr int Error = -1;  //!< �G���[
} // namespace

namespace AppFrame {
  namespace Application {
    ApplicationBase::ApplicationBase() {
      // ��ʃ��[�h�؂�ւ�
#ifdef _DEBUG
      _windowMode = true;   //�E�B���h�E
#else
      _windowMode = false;  // �t���X�N���[��
#endif
    }

    ApplicationBase::~ApplicationBase() {

    }

    bool ApplicationBase::Init() {
      // DX���C�u�����̏�����
      if (!DxLibInit()) {
        return false;  // ���������s
      }
      //Effekseer�̏�����
      if (!EffekseerInit()) {
        return false;  // ���������s
      }
      // �C���v�b�g�}�l�[�W���[�̐���
      _inputManager = std::make_unique<Input::InputManager>(*this);
      // �摜�ǂݍ��݃T�[�o�̐���
      _graphicLoadServer = std::make_unique<Graphic::GraphicLoadServer>();
      // ���[�h�T�[�o�̐���
      _modeServer = std::make_unique<Mode::ModeServer>(*this);
      return true;  // ����������
    }

    void ApplicationBase::Run() {
      // ���C�����[�v
      while (ProcessMessage() != Error) {
        // �A�v���P�[�V�������I������ꍇ
        if (_appState == AppState::Quit) {
          break;  // ���[�v�𔲂���
        }
#ifdef _DEBUG
        try {
          Input();    // ����
          Process();  // �X�V
          Draw();     // �`��
        }
        catch (std::logic_error error) {
          // ��O�������A�o�͂��s��
          OutputDebugString(error.what());
        }
#else
        Input();    // ����
        Process();  // �X�V
        Draw();     // �`��
#endif
      }
    }

    void ApplicationBase::Terminate() {
      // �e����
      Release();
      // Effekseer�̏I��
      Effkseer_End();
      // DX���C�u�����̏I��
      DxLib_End();
    }

    void ApplicationBase::RequestTerminate() {
      // �A�v���P�[�V�������I����Ԃł͂Ȃ��ꍇ
      if (_appState != AppState::Quit) {
        _appState = AppState::Quit;  // �I��
      }
    }

    void ApplicationBase::Release() {
      // �摜�ǂݍ��݃T�[�o�̉��
      _graphicLoadServer->Release();
      // ���[�h�T�[�o�̉��
      _modeServer->Release();
    }

    void ApplicationBase::Input() {
      // �C���v�b�g�}�l�[�W���[�̍X�V
      _inputManager->Process();
    }

    void ApplicationBase::Process() {
      // ���[�h�T�[�o�̍X�V
      _modeServer->Process();
    }

    void ApplicationBase::Draw() {
      // ��ʂ��N���A
      ClearDrawScreen();
      // ���[�h�T�[�o�̕`��
      _modeServer->Draw();
      // ����ʂ̓��e��\��ʂɔ��f
      ScreenFlip();
    }

    bool ApplicationBase::DxLibInit() {
      // ���O�t�@�C���̏o�͐ݒ�
      SetOutApplicationLogValidFlag(_windowMode);
      // ��ʃ��[�h�̕ύX
      SetGraphMode(ScreenWidth, ScreenHeight, ColorBit);
      ChangeWindowMode(_windowMode);
      // DX���C�u�����̏�����
      if (DxLib_Init() == Error) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:DX���C�u�����̏������Ɏ��s���܂���\n");
#endif
        return false;  // ���������s
      }
      // ���ʕ`��̐ݒ�
      SetDrawScreen(DX_SCREEN_BACK);
      // �w�i�F�̐ݒ�
      SetBackgroundColor(0, 0, 255);
      // Z�o�b�t�@�̐ݒ�
      SetUseZBuffer3D(true);    // �g�p����
      SetWriteZBuffer3D(true);  // �������݂��s��
      return true;  // ����������
    }

    bool ApplicationBase::EffekseerInit() {
      // DirectX11���g�p
      SetUseDirect3DVersion(DX_DIRECT3D_11);
      // Effekseer�̏�����
      if (Effekseer_Init(Particle) == Error) {
#ifdef _DEBUG
        throw std::logic_error("ApplicationBase:Effekseer�̏������Ɏ��s���܂���\n");
#endif
        return false;  // ���������s
      }
      // �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h��
      SetChangeScreenModeGraphicsSystemResetFlag(false);
      // DX���C�u�����̃f�o�C�X���X�g�������̃R�[���o�b�N��ݒ�
      Effekseer_SetGraphicsDeviceLostCallbackFunctions();
      return true;  // ����������
    }

    bool ApplicationBase::IsSetApplication() {
      // �A�v���P�[�V����������
      if (!_isSetApp) {
        if (_application == nullptr) {
          _isSetApp = true;
          return true;  // ��������
        }
      }
      return false;  // �������Ȃ�
    }

    Input::InputManager& ApplicationBase::GetInputManager() {
      return *_inputManager;
    }

    Graphic::GraphicLoadServer& ApplicationBase::GetGraphicLoadServer() {
      return *_graphicLoadServer;
    }

    Mode::ModeServer& ApplicationBase::GetModeServer() {
      return *_modeServer;
    }
  } // namespace Application
} // namespace AppFrame