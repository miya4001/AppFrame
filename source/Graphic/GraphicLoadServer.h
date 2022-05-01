/*****************************************************************//**
 * @file   GraphicLoadServer.h
 * @brief  画像を読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <unordered_map>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  画像
   */
  namespace Graphic {
    /**
     * @class  GraphicLoadServer
     * @brief  画像を読み込むサーバクラス
     */
    class GraphicLoadServer {
    public:
      /**
       * @brief  画像情報を格納する動的配列
       * @param  画像ファイルに紐づける文字列
       * @param  画像ファイルのパス
       */
      using LoadGraphicMap = std::vector<std::pair<std::string_view, std::string_view>>;
      /**
       * @brief  コンストラクタ
       */
      GraphicLoadServer();
      /**
       * @brief  デストラクタ
       */
      ~GraphicLoadServer();
      /**
       * @brief  解放
       */
      void Release();
      /**
       * @brief  画像の一括読み込み
       * @param  graphic 画像情報を格納する動的配列
       */
      void LoadGraphics(const LoadGraphicMap graphic);
      /**
       * @brief  指定した画像ハンドルの取得
       * @param  key 対象の画像に紐づけられた文字列
       * @return 画像ハンドルを返す
       *         キーが有効でない場合-1
       */
      int GetGraphicHandle(const std::string_view key) const;

    private:
      /**
       * @brief  画像の読み込み
       * @param  key 画像ファイルに紐づける文字列
       * @param  path 画像ファイルのパス
       */
      void LoadGraphic(const std::string_view key, const std::string_view path);

      //!< 画像レジストリ
      std::unordered_map<std::string, int> _graphicRegistry;
    };
  } // namespace Graphic
} // namespace AppFrame