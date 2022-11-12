/*****************************************************************//**
 * @file   InputKeyboard.h
 * @brief  �L�[�{�[�h�̓��͏����N���X
 * 
 * @author �{�V�s��
 * @date   November 2022
 *********************************************************************/
#pragma once
#include "InputBase.h"

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
 * @brief  ����
 */
  namespace Input {
    /**
     * @class  InputKeyboard
     * @brief  �L�[�{�[�h�̓��͏����N���X
     */
    class InputKeyboard : public InputBase {
    public:
      /**
       * @brief  �R���X�g���N�^
       */
      InputKeyboard();
      /**
       * @brief  ������
       * @return true:����������
       *         false:���������s
       */
      bool Init() override;
      /**
       * @brief  �X�V
       */
      void Process() override;

    private:

    };
  } // namespace Input
} // namespace AppFrame