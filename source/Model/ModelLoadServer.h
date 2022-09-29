/*****************************************************************//**
 * @file   ModelLoadServer.h
 * @brief  ���f����ǂݍ��ރT�[�o�N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <unordered_map>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  ���f��
   */
  namespace Model {
    /**
     * @class  ModelLoadServer
     * @brief  ���f����ǂݍ��ރT�[�o�N���X
     */
    class ModelLoadServer {
    public:
      /**
       * @brief  ���f�������i�[���铮�I�z��
       * @param  ���f���t�@�C���ɕR�Â��镶����
       * @param  ���f���t�@�C���̃p�X
       */
      using LoadModelMap = std::vector<std::pair<std::string_view, std::string_view>>;
      /**
       * @brief  �R���X�g���N�^
       */
      ModelLoadServer();
      /**
       * @brief  �f�X�g���N�^
       */
      ~ModelLoadServer();
      /**
       * @brief  ���
       */
      void Release();
      /**
       * @brief  ���f���̈ꊇ�ǂݍ���
       * @param  model ���f�������i�[���铮�I�z��
       */
      void LoadModels(const LoadModelMap model);
      /**
       * @brief  �����������f���̉��
       */
      void DeleteDuplicateModels();
      /**
       * @brief  �w�肵�����f���n���h���̎擾
       * @param  key �Ώۂ̃��f���ɕR�Â���ꂽ������
       * @return ���f���n���h����Ԃ�
       *         �L�[���L���łȂ��ꍇ-1
       */
      int GetModelHandle(const std::string_view key) const;
      /**
       * @brief  �w�肵�����f���n���h���̕����̎擾
       * @param  key �Ώۂ̃��f���ɕR�Â���ꂽ������
       * @return �����������f���n���h����Ԃ�
       *         �L�[���L���łȂ��ꍇ-1
       */
      int GetDuplicateModelHandle(const std::string_view key);

    private:
      /**
       * @brief  ���f���̓ǂݍ���
       * @param  key ���f���t�@�C���ɕR�Â��镶����
       * @param  path ���f���t�@�C���̃p�X
       */
      void LoadModel(const std::string_view key, const std::string_view path);
      /**
       * @brief  ���f���̕���
       * @param  key �Ώۂ̃��f���ɕR�Â���ꂽ������
       * @return �����������f���n���h��
       */
      int DuplicateModel(const std::string_view key);

      //!< ���f�����W�X�g��
      std::unordered_map<std::string, int> _modelRegistry;
      //!< �������f�����W�X�g��
      std::vector<int> _duplicateRegistry;
    };
  } // namespace Model
} // namespace AppFrame