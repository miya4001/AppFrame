/*****************************************************************//**
 * @file   InputXJoypad.h
 * @brief  XInput�W���C�p�b�h�̓��͏����N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#pragma once
#include <DxLib.h>
#include <array>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  ����
   */
  namespace Input {
    constexpr int ButtonNum = 16;         //!< �{�^������
    constexpr bool InputPress = true;     //!< �������
    constexpr bool InputTrigger = false;  //!< �g���K���
    constexpr bool StickLeft = true;      //!< ���X�e�B�b�N
    constexpr bool StickRight = false;    //!< �E�X�e�B�b�N
    /**
     * @class  InputXJoypad
     * @brief  XInput�W���C�p�b�h�̓��͏����N���X
     */
    class InputXJoypad {
    public:
      /**
       * @brief  �R���X�g���N�^
       */
      InputXJoypad();
      /**
       * @brief  �f�X�g���N�^
       */
      ~InputXJoypad();
      /**
       * @brief  �X�V
       */
      void Process();
      /**
       * @brief  �{�^���̓��͏�Ԃ̎擾
       * @param  key �Ή�����L�[�ԍ�(0�`15)
       *             DX���C�u������XINPUT�{�^�����͒�`
       * @param  type �擾������̎��
       *              InputPress:�������
       *              InputTrigger:�g���K���
       * @return true:���͂���
       *         false:���͂Ȃ�
       */
      bool GetButton(const int key, const bool type) const;
      /**
       * @brief  ���炩�̃{�^���̓��͂����邩�̔���
       * @return true:���͂���
       *         false:���͂Ȃ�
       */
      bool GetAnyButton() const;
      /**
       * @brief  �A�i���O�X�e�B�b�N�̓��͏�Ԃ̎擾
       * @param  stick �擾����X�e�B�b�N�̍��E
       *               StickLeft:���X�e�B�b�N
       *               StickRight:�E�X�e�B�b�N
       * @return first:�����̓��͏��
       *         second:�c���̓��͏��
       */
      std::pair<int, int> GetStick(const bool stick) const;

    private:
      /**
       * @brief  �A�i���O�X�e�B�b�N�̍X�V
       */
      void AnalogStickUpdate();
      /**
       * @brief  �f�b�h�]�[������
       * @param  stick �X�e�B�b�N���͏��̎Q��
       */
      void DeadZone(short& stick);
      /**
       * @brief  �g���K���̐���
       * @param  press �ΏۃL�[�̉������
       * @param  old �O�t���[���̑ΏۃL�[�̉������
       * @return �ΏۃL�[�̃g���K���
       */
      inline int Trigger(const int press, const int old) {
        return press ^ old & press;
      }

      //!< ���͏��(��������)
      XINPUT_STATE _press;
      //!< �e��{�^���̉������
      std::array<bool, ButtonNum> _triggerButtons;
      //!< �e��X�e�B�b�N�̃f�b�h�]�[�����
      std::pair<short, short> _deadZone;
    };
  } // namespace Input
} // namespace AppFrame