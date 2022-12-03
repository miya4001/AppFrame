/*****************************************************************//**
 * @file   EffectLoadServer.h
 * @brief  エフェクトを読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <string_view>
#include <unordered_map>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  エフェクト
   */
  namespace Effect {
    /**
     * @class  EffectLoadServer
     * @brief  エフェクトを読み込むサーバクラス
     */
    class EffectLoadServer {
    public:
      /**
       * @brief  エフェクト情報を格納する動的配列
       * @param  エフェクトファイルに紐づける文字列
       * @param  エフェクトファイルのパス
       * @param  エフェクト拡大率
       */
      using LoadEffectMap = std::vector<std::tuple<std::string_view, std::string_view, float>>;
      /**
       * @brief  コンストラクタ
       */
      EffectLoadServer();
      /**
       * @brief  デストラクタ
       */
      ~EffectLoadServer();
      /**
       * @brief  解放
       */
      void Release();
      /**
       * @brief  エフェクトの一括読み込み
       * @param  effect エフェクト情報を格納する動的配列
       */
      void LoadEffects(const LoadEffectMap effect);
      /**
       * @brief  指定したエフェクトハンドルの取得
       * @param  key 対象のエフェクトに紐づけられた文字列
       * @return エフェクトハンドルを返す
       *         キーが有効でない場合-1
       */
      int GetEffectHandle(const std::string_view key) const;

    private:
      /**
       * @brief  エフェクトの読み込み
       * @param  key エフェクトファイルに紐づける文字列
       * @param  path エフェクトファイルのパス
       * @param  magni エフェクト拡大率
       */
      void LoadEffect(const std::string_view key, const std::string_view path, const float magni);

      //!< エフェクトレジストリ
      std::unordered_map<std::string, int> _effectRegistry;
    };
  } // namespace Effect
} // namespace AppFrame