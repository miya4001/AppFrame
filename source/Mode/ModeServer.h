/*****************************************************************//**
 * @file   ModeServer.h
 * @brief  �e�탂�[�h���Ǘ�����T�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#pragma once
#include <memory>
#include <unordered_map>

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
  } // namespace InputManager
  /**
   * @brief  ���[�h
   */
  namespace Mode {
    class ModeBase;
    /**
     * @class  ModeServer
     * @brief  �e�탂�[�h���Ǘ�����T�[�o�N���X
     */
    class ModeServer {
    public:
      /**
       * @brief  �R���X�g���N�^
       * @param  app �A�v���P�[�V�����̎Q��
       */
      ModeServer(Application::ApplicationBase& app);
      /**
       * @brief  �f�X�g���N�^
       */
      ~ModeServer();
      /**
       * @brief  �X�V
       */
      virtual void Process();
      /**
       * @brief  �`��
       */
      virtual void Draw() const;
      /**
       * @brief  �f�[�^�x�[�X�Ƀ��[�h��o�^
       * @param  key �o�^�Ɏg�p���镶����
       * @param  mode �o�^���郂�[�h�̃V�F�A�[�h�|�C���^
       */
      void AddMode(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  �w�肵�����[�h�����X�g�̖����ɒǉ�
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       */
      void PushBack(std::string_view key);
      /**
       * @brief  ���X�g�̖����ɓo�^����Ă��郂�[�h���폜
       */
      void PopBuck();
      /**
       * @brief  ���[�h�J��
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       */
      void TransionToMode(std::string_view key);
      /**
       * @brief  ���[�h�o�^����
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       * @return true:�o�^�ς�
       *         false:���o�^
       */
      bool ContainsMode(std::string_view key);

    private:
      /**
       * @brief  �w�肵�����[�h�����X�g�̖����̒��O�ɒǉ�
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       */
      void InsertBeforeBack(std::string_view key);
      /**
       * @brief  �f�[�^�x�[�X����w�肵�����[�h���擾
       * @param  key �Ώۃ��[�h�ɕR�Â���ꂽ������
       * @param  enter ���[�h�J�n�������s��������
       * @return �w�肵�����[�h��Ԃ�
       *         �L�[���L���łȂ��ꍇnullptr��Ԃ�
       */
      std::shared_ptr<ModeBase> FetchMode(std::string_view key, const bool enter = true);

      //!< ���[�h�f�[�^�x�[�X(�o�^�p)
      std::unordered_map<std::string, std::shared_ptr<ModeBase>> _modeRegistry;
      //!< ���[�h���X�g(�����p)
      std::list<std::shared_ptr<ModeBase>> _modeList;
    };
  } // namespace Mode
} // namespace AppFrame