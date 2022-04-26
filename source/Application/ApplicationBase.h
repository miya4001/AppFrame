/*****************************************************************//**
 * @file   ApplicationBase.h
 * @brief  �A�v���P�[�V�����̊��N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#pragma once
#include <memory>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  constexpr int ScreenWidth = 1920;   //!< ��ʉ𑜓x(��)
  constexpr int ScreenHeight = 1080;  //!< ��ʉ𑜓x(�c)
  constexpr int ColorBit = 32;        //!< �r�b�g�J���[
  constexpr int Particle = 8000;      //!< �p�[�e�B�N����
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
    class ModeServer;
  } // namespace Mode
  /**
   * @brief  �A�v���P�[�V����
   */
  namespace Application {
    /**
     * @class  ApplicationBase
     * @brief  �A�v���P�[�V�����̊��N���X
     */
    class ApplicationBase {
    public:
      /**
       * @brief  �A�v���P�[�V�����̏��
       */
      enum class AppState {
        Play,    //!< ���s��
        Paused,  //!< �ꎞ��~
        Quit     //!< �I��
      };
      /**
       * @brief  �R���X�g���N�^
       */
      ApplicationBase();
      /**
       * @brief  �f�X�g���N�^
       */
      virtual ~ApplicationBase();
      /**
       * @brief  �A�v���P�[�V�����̏�����
       * @return true:����������
       *         false:���������s
       */
      virtual bool Init();
      /**
       * @brief  �A�v���P�[�V�����̎��s
       */
      virtual void Run();
      /**
       * @brief  �A�v���P�[�V�����̏I��
       */
      virtual void Terminate();
      /**
       * @brief  �A�v���P�[�V�����̏I���v��
       */
      virtual void RequestTerminate();
      /**
       * @brief  �A�v���P�[�V�����̎Q�Ƃ��擾
       * @return �A�v���P�[�V�����̎Q��
       */
      static std::shared_ptr<ApplicationBase> GetApplication() {
        return _application;
      }
      /**
       * @brief  �C���v�b�g�}�l�[�W���[�̎擾
       * @return �C���v�b�g�}�l�[�W���[�̎Q��
       */
      Input::InputManager& GetInputManager();
      /**
       * @brief  ���[�h�T�[�o�[�̎擾
       * @return ���[�h�T�[�o�[�̎Q��
       */
      Mode::ModeServer& GetModeServer();

    protected:
      /**
       * @brief  ����
       */
      virtual void Input();
      /**
       * @brief  �X�V
       */
      virtual void Process();
      /**
       * @brief  �`��
       */
      virtual void Draw();
      /**
       * @brief  Dx���C�u�����̏�����
       * @return true:����������
       *         false:���������s
       */
      virtual bool DxLibInit();
      /**
       * @brief  Effekseer�̏�����
       * @return true:����������
       *         false:���������s
       */
      virtual bool EffekseerInit();
      /**
       * @brief  �A�v���P�[�V�����𐶐����邩�̔���
       * @return true:��������
       *         false:�������Ȃ�
       */
      static bool IsSetApplication();

      static inline bool _windowMode{ false };  //!< ��ʃ��[�h
      static inline bool _isSetApp{ false };    //!< �����t���O

      //!< �A�v���P�[�V�����̏��
      AppState _appState{ AppState::Paused };
      //!< �A�v���P�[�V�����̎���
      static inline std::shared_ptr<ApplicationBase> _application{ nullptr };
      //!< �C���v�b�g�}�l�[�W���[
      std::unique_ptr<Input::InputManager> _input{ nullptr };
      //!< ���[�h�T�[�o�[
      std::unique_ptr<Mode::ModeServer> _modeServer{ nullptr };
    };
  } // namespace Application
} // namespace AppFrame