/*****************************************************************//**
 * @file   ModeBase.h
 * @brief  ���[�h�̊��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#pragma once

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
    class InputManager;
  } // namespace Input
  /**
   * @brief  ���[�h
   */
  namespace Mode {
    /**
     * @class  ModeBase
     * @brief  ���[�h�̊��N���X
     */
    class ModeBase {
    public:
      /**
       * @brief  �R���X�g���N�^
       * @param  app �A�v���P�[�V�����̎Q��
       */
      ModeBase(Application::ApplicationBase& app);
      /**
       * @brief  �f�X�g���N�^
       */
      virtual ~ModeBase();
      /**
       * @brief  ������
       * @return true:����������
       *         false:���������s
       */
      virtual bool Init();
      /**
       * @brief  ���[�h�J�n
       */
      virtual void Enter();
      /**
       * @brief  ���[�h�I��
       */
      virtual void Exit();
      /**
       * @brief  ����
       * @param  input �C���v�b�g�}�l�[�W���[�̎Q��
       */
      virtual void Input(Input::InputManager& input);
      /**
       * @brief  �X�V
       */
      virtual void Process();
      /**
       * @brief  �`��
       */
      virtual void Draw() const;
      /**
       * @brief  �A�v���P�[�V�����̎擾
       * @return �A�v���P�[�V�����̎Q��
       */
      virtual Application::ApplicationBase& GetApplication();

    protected:
      /**
       * @brief  ���\�[�X�ǂݍ���
       */
      virtual void LoadResource();
      /**
       * @brief  ���[�h�؂�ւ�
       */
      virtual void ChangeMode();

      int _modeCount{ 0 };    //!< �{���[�h���o�ߎ���(�t���[��)
      bool _isLoad{ false };  //!< ���\�[�X�ǂݍ��݃t���O
      //!< �A�v���P�[�V�����̎Q��
      Application::ApplicationBase& _app;
    };
  } // namespace Mode
} // namespace AppFrame