/*****************************************************************//**
 * @file   SoundComponent.h
 * @brief  �����R���|�[�l���g
 * 
 * @author �{�V�s��
 * @date   October 2022
 *********************************************************************/
#pragma once
#include <string_view>

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
  namespace Sound {
    constexpr int DefaultVolume = 100;  //!< �f�t�H���g�Đ�����
    /**
     * @class  SoundComponent
     * @brief  �����R���|�[�l���g
     */
    class SoundComponent {
    public:
      /**
       * @brief  �R���X�g���N�^
       * @param  app �A�v���P�[�V�����̎Q��
       */
      SoundComponent(Application::ApplicationBase& app);
      /**
       * @brief  �f�X�g���N�^
       */
      ~SoundComponent();
      /**
       * @brief  �����̃o�b�N�O���E���h�Đ�
       * @param  key �����ɕR�Â���ꂽ������
       * @param  volume �Đ�����(�f�t�H���g��100)
       */
      void PlayBackGround(const std::string_view key, const int volume = DefaultVolume);
      /**
       * @brief  �����̃��[�v�Đ�
       * @param  key �����ɕR�Â���ꂽ������
       * @param  volume �Đ�����(�f�t�H���g��100)
       */
      void PlayLoop(const std::string_view key, const int volume = DefaultVolume);
      /**
       * @brief  �����̍Đ���~
       * @param  key �����ɕR�Â���ꂽ������
       */
      void StopSound(const std::string_view key);
      /**
       * @brief  �����̍Đ�����
       * @param  key �����ɕR�Â���ꂽ������
       * @return true:�Đ���
       *         false:�Đ�����Ă��Ȃ�
       */
      bool CheckSound(const std::string_view key);

    private:
      /**
       * @brief  �����̍Đ�
       * @param  key �����ɕR�Â���ꂽ������
       * @param  type �Đ��^�C�v
       */
      void Play(const std::string_view key, const int type);
      /**
       * @brief  �����̉��ʂ̐ݒ�
       * @param  key �����ɕR�Â���ꂽ������
       * @param  volume �Đ�����(0~255)
       */
      void SetVolume(const std::string_view key, const int volume);
      /**
       * @brief  �����n���h���̎擾
       * @param  key �����ɕR�Â���ꂽ������
       * @return �����n���h����Ԃ�
       *         �擾�Ɏ��s�����ꍇ-1
       */
      int GetSoundHandle(const std::string_view key);

      //!< �A�v���P�[�V�����̎Q��
      Application::ApplicationBase& _app;
    };
  } // namespace Sound
} // namespace AppFrame