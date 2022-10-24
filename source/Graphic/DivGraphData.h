/*****************************************************************//**
 * @file   DivGraphData.h
 * @brief  分割画像情報クラス
 * 
 * @author 宮澤耀生
 * @date   October 2022
 *********************************************************************/
#pragma once
#include <string_view>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  画像
   */
  namespace Graphic {
    /**
     * @class  DivGraphData
     * @brief  分割画像情報クラス
     */
    class DivGraphData {
    public:
      /**
       * @brief  コンストラクタ
       * @param  path ファイルパス
       * @param  allNumber 総分割数
       * @param  xNumber 横分割数
       * @param  yNumber 縦分割数
       * @param  xSize 分割横サイズ
       * @param  ySize 分割縦サイズ
       */
      DivGraphData(const std::string_view path, const int allNumber, const int xNumber, const int yNumber, const int xSize, const int ySize);
      /**
       * @brief  ファイルパスの取得
       * @return ファイルパス
       */
      inline std::string_view GetFilePath() const {
        return _filePath;
      }
      /**
       * @brief  分割数の取得
       * @return 分割数(総分割数, 横分割数, 縦分割数)
       */
      inline std::tuple<int, int, int> GetNumber() const {
        return { _allNumber, _xNumber, _yNumber };
      }
      /**
       * @brief  分割サイズの取得
       * @return 分割サイズ(横分割数, 縦分割数)
       */
      inline std::pair<int, int> GetSize() const {
        return { _xSize, _ySize };
      }

    private:
      int _allNumber{ 0 };  //!< 総分割数
      int _xNumber{ 0 };    //!< 横分割数
      int _yNumber{ 0 };    //!< 縦分割数
      int _xSize{ 0 };      //!< 分割縦サイズ
      int _ySize{ 0 };      //!< 分割横サイズ
      //!< ファイルパス
      std::string_view _filePath;
    };
  } // namespace Graphic
} // namespace AppFrame