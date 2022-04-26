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
      /**
       * @class  ModeFade
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
         * @brief  �f�X�g���N�^
         */
        ~ModeFadeBase() override;
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
        virtual void Draw() const override;

      protected:
        /**
         * @brief  �t�F�[�h�̏I������
         * @return true:�t�F�[�h�I��
         *         false:�t�F�[�h�p��
         */
        virtual bool IsFadeFinish();

        int _alpha{ 0 };  //!< �A���t�@�l
      };
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame