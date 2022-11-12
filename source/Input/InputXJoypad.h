/*****************************************************************//**
 * @file   InputXJoypad.h
 * @brief  XInput�W���C�p�b�h�̓��͏����N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
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
    constexpr int AllButtonNumber = 16;  //!< �{�^������
    constexpr bool StickLeft = true;     //!< ���X�e�B�b�N
    constexpr bool StickRight = false;   //!< �E�X�e�B�b�N
    /**
     * @class  InputXJoypad
     * @brief  XInput�W���C�p�b�h�̓��͏����N���X
     */
    class InputXJoypad : public InputBase {
    public:
      /**
       * @brief  �R���X�g���N�^
       */
      InputXJoypad();
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
      /**
       * @brief  �f�b�h�]�[���Œ�l�̎擾
       * @return �f�b�h�]�[���Œ�l
       */
      inline short GetDeadZoneMin() const {
        return _deadZone.first;
      }
      /**
       * @brief  �f�b�h�]�[���ő�l�̎擾
       * @return �f�b�h�]�[���ő�l
       */
      inline short GetDeadZoneMax() const {
        return _deadZone.second;
      }

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
      //!< �e��{�^���̃g���K���
      std::array<bool, AllButtonNumber> _trigger;
      //!< �e��X�e�B�b�N�̃f�b�h�]�[�����
      std::pair<short, short> _deadZone;
    };
  } // namespace Input
} // namespace AppFrame