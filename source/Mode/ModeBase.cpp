/*****************************************************************//**
 * @file   ModeBase.cpp
 * @brief  ÉÇÅ[ÉhÇÃäÓíÍÉNÉâÉX
 * 
 * @author ã{‡Vósê∂
 * @date   April 2022
 *********************************************************************/
#include "ModeBase.h"

namespace AppFrame {
  namespace Mode {
    ModeBase::ModeBase(Application::ApplicationBase& app) : _app(app) {

    }

    ModeBase::~ModeBase() {

    }

    bool ModeBase::Init() {
      return true;
    }

    void ModeBase::Enter() {

    }

    void ModeBase::Exit() {

    }

    void ModeBase::Input(Input::InputManager& input) {

    }

    void ModeBase::Process() {

    }

    void ModeBase::Draw() const {

    }

    Application::ApplicationBase& ModeBase::GetApplication() {
      return _app;
    }

    void ModeBase::LoadResource() {

    }

    void ModeBase::ChangeMode() {

    }
  } // namespace Mode
} // namespace AppFrame