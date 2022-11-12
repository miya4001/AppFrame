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
    constexpr int AllKeyNumber = 256;  //!< �L�[����
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
      /**
       * @brief  
       * @param  key �Ή�����L�[�ԍ�
       *         DX���C�u�����̃L�[�{�[�h���͒�`
       * @param  type �擾������̎��
       *              InputPress:�������
       *              InputTrigger:�g���K���
       * @return true:���͂���
       *         false:���͂Ȃ�
       */
      bool GetKey(const int key, const bool type) const;
      /**
       * @brief  ���炩�̃L�[�{�[�h�̓��͂����邩�̔���
       * @return true:���͂���
       *         false:���͂Ȃ�
       */
      bool GetAnyKey() const;

    private:
      //!< �������
      std::array<char, AllKeyNumber> _press;
      //!< �g���K���
      std::array<char, AllKeyNumber> _trigger;
    };
  } // namespace Input
} // namespace AppFrame