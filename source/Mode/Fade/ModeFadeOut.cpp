/*****************************************************************//**
 * @file   ModeFadeOut.cpp
 * @brief  ���[�h�J�ڃt�F�[�h�A�E�g�N���X
 *
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "ModeFadeOut.h"
#include "../../Application/ApplicationBase.h"
#include "../ModeServer.h"

namespace AppFrame {
  namespace Mode {
    namespace Fade {
      ModeFadeOut::ModeFadeOut(Application::ApplicationBase& app) : ModeFadeBase(app) {

      }

      void ModeFadeOut::Enter() {
        // �A���t�@�l�̏�����
        _alpha = AlphaMin;
      }

      void ModeFadeOut::Process() {
        // �A���t�@�l�̌v�Z
        AlphaCalculation();
        // �t�F�[�h�̏I������
        if (IsFadeFinish()) {
          // ���g���폜����
          _app.GetModeServer().PopBuck();
          // ���g�̒��O�̃��[�h���폜����
          _app.GetModeServer().PopBuck();
        }
      }

      void ModeFadeOut::AlphaCalculation() {
        // �A���t�@�l�̉��Z
        _alpha += AlphaSpeed;
      }

      bool ModeFadeOut::IsFadeFinish() {
        // �A���t�@�l�͏���ȏォ
        return AlphaMax <= _alpha;
      }
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame