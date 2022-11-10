/*****************************************************************//**
 * @file   InputXJoypad.cpp
 * @brief  XInput�W���C�p�b�h�̓��͏����N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "InputXJoypad.h"
#include <DxLib.h>
#include <algorithm>
#include "../Math/Utility.h"

namespace {
  constexpr int DeadZoneMin = 3000;    //!< �f�b�h�]�[��������Βl
  constexpr int DeadZoneMax = 30000;   //!< �f�b�h�]�[�������Βl
  constexpr int Error = -1;            //!< �G���[
  constexpr int ButtonNumberMin = 0;   //!< �{�^���ԍ�����
  constexpr int ButtonNumberMax = 15;  //!< �{�^���ԍ����

} // namespace

namespace AppFrame {
  namespace Input {
    InputXJoypad::InputXJoypad() {
      _press = XINPUT_STATE();
      _triggerButtons.fill(false);
      // �f�b�h�]�[���ݒ�
      _deadZone = std::make_pair(DeadZoneMin, DeadZoneMax);
    }

    InputXJoypad::~InputXJoypad() {

    }

    void InputXJoypad::Process() {
      // �O�t���[���̃{�^�����͏��
      auto old = _press;
      // ���͏�Ԃ̎擾�Ɏ��s�����ꍇ�G���[
      if (GetJoypadXInputState(DX_INPUT_PAD1, &_press) == Error) {
        return;  // �擾���s
      }
      // �A�i���O�X�e�B�b�N�̍X�V
      AnalogStickUpdate();
      // �{�^���̃g���K���̍X�V
      for (auto no = 0; auto && button : _triggerButtons) {
        // ���͏�Ԃ��r���ăg���K�����Z�o
        button = Trigger(_press.Buttons[no], old.Buttons[no]);
        no++;
      }
    }

    bool InputXJoypad::GetButton(const int key, const bool type) const {
      // �͈͓�����
      bool isRange = AppFrame::Math::Utility::IsRange(key, ButtonNumberMin, ButtonNumberMax);
      // �͈͓��Ɏ��܂��Ă��Ȃ��ꍇ
      if (!isRange) {
        return false;  // �L�[���s��
      }
      // �t���O�ɉ����ĕԂ��l��؂�ւ���
      if (type == InputPress) {
        // ��������Ԃ�
        return _press.Buttons[key];
      } else {
        // �g���K����Ԃ�
        return _triggerButtons[key];
      }
    }

    bool InputXJoypad::GetAnyButton() const {
      // ���炩�̃{�^�����͂����邩
      for (auto button : _press.Buttons) {
        if (button == 1) {
          return true;  // ���͂���
        }
      }
      return false;  // ���͂Ȃ�
    }

    std::pair<int, int> InputXJoypad::GetStick(const bool stick) const {
      int x, y;  // �c���̓��͏��
      // ���E�ǂ���̓��͏�Ԃ��擾���邩
      if (stick == StickLeft) {
        // ���X�e�B�b�N�̓��͏��
        x = static_cast<int>(_press.ThumbLX);
        y = static_cast<int>(_press.ThumbLY);
        return std::make_pair(x, y);
      } else {
        // �E�X�e�B�b�N�̓��͏��
        x = static_cast<int>(_press.ThumbRX);
        y = static_cast<int>(_press.ThumbRY);
        return std::make_pair(x, y);
      }
    }

    void InputXJoypad::AnalogStickUpdate() {
      // �e��X�e�B�b�N���Ƀf�b�h�]�[������
      DeadZone(_press.ThumbLX);
      DeadZone(_press.ThumbLY);
      DeadZone(_press.ThumbRX);
      DeadZone(_press.ThumbRY);
    }

    void InputXJoypad::DeadZone(short& stick) {
      // �����ǂ��炩����
      bool isPositive = 0 <= stick;
      short p = isPositive ? 1 : -1;
      short min = _deadZone.first * p;
      short max = _deadZone.second * p;
      // �����ɉ����ď���
      if (isPositive) {
        // ���������������ꍇ0�Ƃ���
        if (stick < min) {
          stick = 0;
          return;
        }
        // �N�����v����
        stick = std::clamp(stick, min, max);
        return;
      } else {
        // ���������傫���ꍇ0�Ƃ���
        if (min < stick) {
          stick = 0;
          return;
        }
        // �N�����v����
        stick = std::clamp(stick, max, min);
        return;
      }
    }
  } // namespace Input
} // namespace AppFrame