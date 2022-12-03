/*****************************************************************//**
 * @file   EffectLoadServer.h
 * @brief  �G�t�F�N�g��ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <string_view>
#include <unordered_map>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  �G�t�F�N�g
   */
  namespace Effect {
    /**
     * @class  EffectLoadServer
     * @brief  �G�t�F�N�g��ǂݍ��ރT�[�o�N���X
     */
    class EffectLoadServer {
    public:
      /**
       * @brief  �G�t�F�N�g�����i�[���铮�I�z��
       * @param  �G�t�F�N�g�t�@�C���ɕR�Â��镶����
       * @param  �G�t�F�N�g�t�@�C���̃p�X
       * @param  �G�t�F�N�g�g�嗦
       */
      using LoadEffectMap = std::vector<std::tuple<std::string_view, std::string_view, float>>;
      /**
       * @brief  �R���X�g���N�^
       */
      EffectLoadServer();
      /**
       * @brief  �f�X�g���N�^
       */
      ~EffectLoadServer();
      /**
       * @brief  ���
       */
      void Release();
      /**
       * @brief  �G�t�F�N�g�̈ꊇ�ǂݍ���
       * @param  effect �G�t�F�N�g�����i�[���铮�I�z��
       */
      void LoadEffects(const LoadEffectMap effect);
      /**
       * @brief  �w�肵���G�t�F�N�g�n���h���̎擾
       * @param  key �Ώۂ̃G�t�F�N�g�ɕR�Â���ꂽ������
       * @return �G�t�F�N�g�n���h����Ԃ�
       *         �L�[���L���łȂ��ꍇ-1
       */
      int GetEffectHandle(const std::string_view key) const;

    private:
      /**
       * @brief  �G�t�F�N�g�̓ǂݍ���
       * @param  key �G�t�F�N�g�t�@�C���ɕR�Â��镶����
       * @param  path �G�t�F�N�g�t�@�C���̃p�X
       * @param  magni �G�t�F�N�g�g�嗦
       */
      void LoadEffect(const std::string_view key, const std::string_view path, const float magni);

      //!< �G�t�F�N�g���W�X�g��
      std::unordered_map<std::string, int> _effectRegistry;
    };
  } // namespace Effect
} // namespace AppFrame