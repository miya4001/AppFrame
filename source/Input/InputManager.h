/*****************************************************************//**
 * @file   InputManager.h
 * @brief  �S�Ă̓��͂̈ꊇ�Ǘ��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include "InputXJoypad.h"

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

    private:
      //!< �A�v���P�[�V�����̎Q��
      Application::ApplicationBase& _app;
      //!< XInput�W���C�p�b�h�̓��͏����̎Q��
      InputXJoypad _xJoypad;
    };
  } // namespace Input
} // namespace AppFrame