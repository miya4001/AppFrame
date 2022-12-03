/*****************************************************************//**
 * @file   GraphicLoadServer.h
 * @brief  �摜��ǂݍ��ރT�[�o�N���X
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
   * @brief  �摜
   */
  namespace Graphic {
    class DivGraphData;
    /**
     * @class  GraphicLoadServer
     * @brief  �摜��ǂݍ��ރT�[�o�N���X
     */
    class GraphicLoadServer {
    public:
      /**
       * @brief  �摜�����i�[���铮�I�z��
       * @param  �摜�t�@�C���ɕR�Â��镶����
       * @param  �摜�t�@�C���̃p�X
       */
      using LoadGraphicMap = std::vector<std::pair<std::string_view, std::string_view>>;
      /**
       * @brief  �����摜�����i�[���铮�I�z��
       * @param  �����摜�t�@�C���ɕR�Â��镶����
       * @param  �����摜���
       */
      using LoadDivGraphicMap = std::vector<std::pair<std::string_view, DivGraphData>>;
      /**
       * @brief  �R���X�g���N�^
       */
      GraphicLoadServer();
      /**
       * @brief  �f�X�g���N�^
       */
      ~GraphicLoadServer();
      /**
       * @brief  ���
       */
      void Release();
      /**
       * @brief  �摜�̈ꊇ�ǂݍ���
       * @param  graphic �摜�����i�[���铮�I�z��
       */
      void LoadGraphics(const LoadGraphicMap graphic);
      /**
       * @brief  �����摜�̈ꊇ�ǂݍ���
       * @param  divgraph �����摜�����i�[���铮�I�z��
       */
      void LoadDivGraphics(const LoadDivGraphicMap divGraph);
      /**
       * @brief  �w�肵���摜�n���h���̎擾
       * @param  key �Ώۂ̉摜�ɕR�Â���ꂽ������
       * @return �摜�n���h����Ԃ�
       *         �L�[���L���łȂ��ꍇ-1
       */
      int GetGraphicHandle(const std::string_view key) const;
      /**
       * @brief  �w�肵�������摜�n���h���̎擾
       * @param  key �Ώۂ̕����摜�ɕR�Â���ꂽ������
       * @return �摜�n���h�����i�[�����R���e�i��Ԃ�
       */
      std::vector<int> GetDivGraphicHandles(const std::string_view key) const;

    private:
      /**
       * @brief  �摜�̓ǂݍ���
       * @param  key �摜�t�@�C���ɕR�Â��镶����
       * @param  path �摜�t�@�C���̃p�X
       */
      void LoadGraphic(const std::string_view key, const std::string_view path);
      /**
       * @brief  �����摜�̓ǂݍ���
       * @param  key �����摜�t�@�C���ɕR�Â��镶����
       * @param  divGraph �����摜���
       */
      void LoadDivGraphic(const std::string_view key, const DivGraphData divGraph);
      /**
       * @brief  �����摜�n���h���̍폜
       * @param  handles �����摜�n���h��
       */
      void DeleteDivGraphics(const std::vector<int> handles);

      //!< �摜���W�X�g��
      std::unordered_map<std::string, int> _graphicRegistry;
      //!< �����摜���W�X�g��
      std::unordered_map<std::string, std::vector<int>> _divGraphicRegistry;
    };
  } // namespace Graphic
} // namespace AppFrame