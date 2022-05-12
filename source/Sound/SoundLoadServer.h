/*****************************************************************//**
 * @file   SoundLoadServer.h
 * @brief  ������ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <unordered_map>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame{
  /**
   * @brief  ����
   */
  namespace Sound {
    /**
     * @class  SoundLoadServer
     * @brief  ������ǂݍ��ރT�[�o�N���X
     */
    class SoundLoadServer {
    public:
      /**
       * @brief  ���������i�[���铮�I�z��
       * @param  �����t�@�C���ɕR�Â��镶����
       * @param  �����t�@�C���̃p�X
       */
      using LoadSoundMap = std::vector<std::pair<std::string_view, std::string_view>>;
      /**
       * @brief  �R���X�g���N�^
       */
      SoundLoadServer();
      /**
       * @brief  �f�X�g���N�^
       */
      ~SoundLoadServer();
      /**
       * @brief  ���
       */
      void Release();
      /**
       * @brief  �����̈ꊇ�ǂݍ���
       * @param  sound ���������i�[���铮�I�z��
       */
      void LoadSounds(const LoadSoundMap sound);
      /**
       * @brief  �w�肵�������n���h���̎擾
       * @param  key �Ώۂ̉����ɕR�Â���ꂽ������
       * @return �����n���h����Ԃ�
       *         �L�[���L���łȂ��ꍇ-1
       */
      int GetSoundHandle(const std::string_view key) const;

    private:
      /**
       * @brief  �����̓ǂݍ���
       * @param  key �����t�@�C���ɕR�Â��镶����
       * @param  path �����t�@�C���̃p�X
       */
      void LoadSound(const std::string_view key, const std::string_view path);

      //!< �������W�X�g��
      std::unordered_map<std::string, int> _soundRegistry;
    };
  } // namespace Sound
} // namespace AppFrame