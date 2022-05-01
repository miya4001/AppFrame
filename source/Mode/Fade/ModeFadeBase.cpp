/*****************************************************************//**
 * @file   ModeFadeBase.cpp
 * @brief  ���[�h�J�ڃt�F�[�h�̊��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "ModeFadeBase.h"
#include <DxLib.h>
#include "../../Application/ApplicationBase.h"
#include "../ModeServer.h"

namespace AppFrame {
  namespace Mode {
    namespace Fade {
      ModeFadeBase::ModeFadeBase(Application::ApplicationBase& app) : ModeBase(app) {

      }

      bool ModeFadeBase::Init() {
        return true;
      }

      void ModeFadeBase::Enter() {

      }

      void ModeFadeBase::Process() {
        // �A���t�@�l�̌v�Z
        AlphaCalculation();
        // �t�F�[�h�̏I������
        if (IsFadeFinish()) {
          // ���g���폜����
          _app.GetModeServer().PopBuck();
        }
      }

      void ModeFadeBase::Draw() const {
        // �A���t�@�u�����h���[�h
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(_alpha));
        //�t�F�[�h�{�b�N�X�̕`��
        DrawBox(0, 0, ScreenWidth, ScreenHeight, GetColor(0, 0, 0), true);
        //�m�[�}���u�����h���[�h
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
      }

      void ModeFadeBase::AlphaCalculation() {

      }

      bool ModeFadeBase::IsFadeFinish() const {
        return true;
      }
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame