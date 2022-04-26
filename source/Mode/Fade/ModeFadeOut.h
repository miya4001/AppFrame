/*****************************************************************//**
 * @file   ModeFadeOut.h
 * @brief  ���[�h�J�ڃt�F�[�h�A�E�g�N���X
 *
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#pragma once
#include "ModeFadeBase.h"

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  ���[�h
   */
  namespace Mode {
    /**
     * @brief  �t�F�[�h
     */
    namespace Fade {
      /**
       * @class  ModeFadeOut
       * @brief  ���[�h�J�ڃt�F�[�h�A�E�g�N���X
       */
      class ModeFadeOut : public ModeFadeBase {
      public:
        /**
         * @brief  �R���X�g���N�^
         * @param  app �A�v���P�[�V�����̎Q��
         */
        ModeFadeOut(Application::ApplicationBase& app);
        /**
         * @brief  ���[�h�J�n
         */
        void Enter() override;

      private:
        /**
         * @brief  �A���t�@�l�̌v�Z
         */
        void AlphaCalculation() override;
        /**
         * @brief  �t�F�[�h�̏I������
         * @return true:�t�F�[�h�I��
         *         false:�t�F�[�h�p��
         */
        bool IsFadeFinish() override;
      };
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame