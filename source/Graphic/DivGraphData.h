/*****************************************************************//**
 * @file   DivGraphData.h
 * @brief  �����摜���N���X
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
   * @brief  �摜
   */
  namespace Graphic {
    /**
     * @class  DivGraphData
     * @brief  �����摜���N���X
     */
    class DivGraphData {
    public:
      /**
       * @brief  �R���X�g���N�^
       * @param  path �t�@�C���p�X
       * @param  allNumber ��������
       * @param  xNumber ��������
       * @param  yNumber �c������
       * @param  xSize �������T�C�Y
       * @param  ySize �����c�T�C�Y
       */
      DivGraphData(const std::string_view path, const int allNumber, const int xNumber, const int yNumber, const int xSize, const int ySize);
      /**
       * @brief  �t�@�C���p�X�̎擾
       * @return �t�@�C���p�X
       */
      inline std::string_view GetFilePath() const {
        return _filePath;
      }
      /**
       * @brief  �������̎擾
       * @return ������(��������, ��������, �c������)
       */
      inline std::tuple<int, int, int> GetNumber() const {
        return { _allNumber, _xNumber, _yNumber };
      }
      /**
       * @brief  �����T�C�Y�̎擾
       * @return �����T�C�Y(��������, �c������)
       */
      inline std::pair<int, int> GetSize() const {
        return { _xSize, _ySize };
      }

    private:
      int _allNumber{ 0 };  //!< ��������
      int _xNumber{ 0 };    //!< ��������
      int _yNumber{ 0 };    //!< �c������
      int _xSize{ 0 };      //!< �����c�T�C�Y
      int _ySize{ 0 };      //!< �������T�C�Y
      //!< �t�@�C���p�X
      std::string_view _filePath;
    };
  } // namespace Graphic
} // namespace AppFrame