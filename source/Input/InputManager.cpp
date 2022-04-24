/*****************************************************************//**
 * @file   InputManager.cpp
 * @brief  �S�Ă̓��͂̈ꊇ�Ǘ��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "InputManager.h"
#include "../Application/ApplicationBase.h"

namespace AppFrame {
  namespace Input {
    InputManager::InputManager(Application::ApplicationBase& app) : _app(app) {

    }

    InputManager::~InputManager() {

    }

    void InputManager::Process() {
      // XInput�W���C�p�b�h�̍X�V
      _xJoypad.Process();
    }
  } // namespace Input
} // namespace AppFrame