/*****************************************************************//**
 * @file   ModeFadeBase.h
 * @brief  ���[�h�J�ڃt�F�[�h�̊��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#pragma once
#include "../ModeBase.h"

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
      constexpr float AlphaMax = 255.0f;  //!< �A���t�@�l�̏��
      constexpr float AlphaMin = 0.0f;    //!< �A���t�@�l�̉���
      constexpr float FadeTime = 60.0f;   //!< �t�F�[�h����(�t���[��)
      constexpr float AlphaSpeed = (AlphaMax / FadeTime);  //!< �A���t�@�l�̕ω���
      /**
       * @class  ModeFadeBase
       * @brief  ���[�h�J�ڃt�F�[�h�̊��N���X
       */
      class ModeFadeBase : public ModeBase {
      public:
        /**
         * @brief  �R���X�g���N�^
         * @param  app �A�v���P�[�V�����̎Q��
         */
        ModeFadeBase(Application::ApplicationBase& app);
        /**
         * @brief  ������
         * @return true:����������
         *         false:���������s
         */
        bool Init() override;
        /**
         * @brief  ���[�h�J�n
         */
        virtual void Enter() override;
        /**
         * @brief  �X�V
         */
        virtual void Process() override;
        /**
         * @brief  �`��
         */
        void Draw() const override;

      protected:
        /**
         * @brief  �A���t�@�l�̌v�Z
         */
        virtual void AlphaCalculation();
        /**
         * @brief  �t�F�[�h�̏I������
         * @return true:�t�F�[�h�I��
         *         false:�t�F�[�h�p��
         */
        virtual bool IsFadeFinish() const;

        float _alpha{ 0 };  //!< �A���t�@�l
      };
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame