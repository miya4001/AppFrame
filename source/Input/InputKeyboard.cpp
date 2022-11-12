/*****************************************************************//**
 * @file   InputKeyboard.cpp
 * @brief  �L�[�{�[�h�̓��͏����N���X
 * 
 * @author �{�V�s��
 * @date   November 2022
 *********************************************************************/
#include "InputKeyboard.h"
#include "../Math/Utility.h"

namespace AppFrame {
  namespace Input {
    InputKeyboard::InputKeyboard() {
      Init();
    }

    bool InputKeyboard::Init() {
      // ���͏��̐ݒ�
      _press.fill(0);
      _trigger = _press;
      return true;
    }

    void InputKeyboard::Process() {
      // �O�t���[���̃L�[�{�[�h���͏��
      auto old = _press;
      // ������Ԃ��i�[����z��
      char keyboard[AllKeyNumber];
      // ���͏�Ԃ̎擾�ɐ���������
      if (GetHitKeyStateAll(keyboard) == InputError) {
        return; // �擾���s
      }
      // �e���Ԃ̍X�V
      for (auto num = 0; auto&& key : _press) {
        // �������̍X�V
        key = keyboard[num];
        // �g���K���̍X�V
        _trigger[num] = _press[num] ^ old[num] & _press[num];
        // �ԍ��𑝂₷
        ++num;
      }
    }

    bool InputKeyboard::GetKey(const int key, const bool type) const {
      // �͈͓�����
      bool isRange = AppFrame::Math::Utility::IsRange(key, 0, AllKeyNumber - 1);
      // �͈͓��Ɏ��܂��Ă��Ȃ��ꍇ
      if (!isRange) {
        return false;  // �L�[���s��
      }
      // �t���O�ɉ����ĕԂ��l��؂�ւ���
      if (type == InputPress) {
        // ��������Ԃ�
        return _press[key];
      } else {
        // �g���K����Ԃ�
        return _trigger[key];
      }
    }

    bool InputKeyboard::GetAnyKey() const {
      // ���炩�̃L�[�{�[�h���͂����邩
      for (auto key : _press) {
        if (key == 1) {
          return true;  // ���͂���
        }
      }
      return false;  // ���͂Ȃ�
    }
  } // namespace Input
} // namespace AppFrame