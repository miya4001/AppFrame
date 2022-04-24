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

namespace {
  constexpr int Error = -1;  //!< �G���[
} // namespace

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
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

    void ApplicationBase::Input() {

    }

    void ApplicationBase::Process() {

    }

    void ApplicationBase::Draw() {
      // ��ʂ��N���A
      ClearDrawScreen();
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
      SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
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
  } // namespace Application
} // namespace AppFrame