/*****************************************************************//**
 * @file   InputManager.cpp
 * @brief  全ての入力の一括管理クラス
 * 
 * @author 宮澤耀生
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
      // XInputジョイパッドの更新
      _xJoypad.Process();
    }
  } // namespace Input
} // namespace AppFrame