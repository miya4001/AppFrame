/*****************************************************************//**
 * @file   ModeFadeIn.h
 * @brief  ���[�h�J�ڃt�F�[�h�C���N���X
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
       * @class  ModeFadeIn
       * @brief  ���[�h�J�ڃt�F�[�h�C���N���X
       */
      class ModeFadeIn : public ModeFadeBase {
      public:
        /**
         * @brief  �R���X�g���N�^
         * @param  app �A�v���P�[�V�����̎Q��
         */
        ModeFadeIn(Application::ApplicationBase& app);
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