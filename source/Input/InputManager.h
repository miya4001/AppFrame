/*****************************************************************//**
 * @file   InputManager.h
 * @brief  �S�Ă̓��͂̈ꊇ�Ǘ��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "InputXJoypad.h"
#include "InputKeyboard.h"

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  �A�v���P�[�V����
   */
  namespace Application {
    class ApplicationBase;
  } // namespace Application
  /**
   * @brief  ����
   */
  namespace Input {
    /**
     * @class  InputManager
     * @brief  �S�Ă̓��͂̈ꊇ�Ǘ��N���X
     */
    class InputManager {
    public:
      /**
       * @brief  �R���X�g���N�^
       * @param  app �A�v���P�[�V�����̎Q��
       */
      InputManager(Application::ApplicationBase& app);
      /**
       * @brief  �f�X�g���N�^
       */
      ~InputManager();
      /**
       * @brief  �X�V
       */
      void Process();
      /**
       * @brief  XInput�W���C�p�b�h�̓��͏����̎擾
       * @return Xinput�W���C�p�b�h�̓��͏����̎Q��
       */
      inline InputXJoypad& GetXJoypad() {
        return _xJoypad;
      }
      /**
       * @brief  �L�[�{�[�h�̓��͏����̎擾
       * @return �L�[�{�[�h�̓��͏����̎Q��
       */
      inline InputKeyboard& GetKeyboard() {
        return _keyboard;
      }

    private:
      //!< �A�v���P�[�V�����̎Q��
      Application::ApplicationBase& _app;
      //!< XInput�W���C�p�b�h�̓��͏���
      InputXJoypad _xJoypad;
      //!< �L�[�{�[�h�̓��͏���
      InputKeyboard _keyboard;
    };
  } // namespace Input
} // namespace AppFrame