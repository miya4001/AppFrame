/*****************************************************************//**
 * @file   ModeFadeIn.cpp
 * @brief  ���[�h�J�ڃt�F�[�h�C���N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "ModeFadeIn.h"

namespace AppFrame {
  namespace Mode {
    namespace Fade {
      ModeFadeIn::ModeFadeIn(Application::ApplicationBase& app) : ModeFadeBase(app) {

      }

      void ModeFadeIn::Enter() {
        // �A���t�@�l�̏�����
        _alpha = AlphaMax;
      }

      void ModeFadeIn::AlphaCalculation() {
        // �A���t�@�l�̌��Z
        _alpha -= AlphaSpeed;
      }

      bool ModeFadeIn::IsFadeFinish() {
        // �A���t�@�l�͉����ȉ���
        return _alpha <= AlphaMin;
      }
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame