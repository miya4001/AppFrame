/*****************************************************************//**
 * @file   ModeFadeOut.h
 * @brief  モード遷移フェードアウトクラス
 *
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#pragma once
#include "ModeFadeBase.h"

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  モード
   */
  namespace Mode {
    /**
     * @brief  フェード
     */
    namespace Fade {
      /**
       * @class  ModeFadeOut
       * @brief  モード遷移フェードアウトクラス
       */
      class ModeFadeOut : public ModeFadeBase {
      public:
        /**
         * @brief  コンストラクタ
         * @param  app アプリケーションの参照
         */
        ModeFadeOut(Application::ApplicationBase& app);
        /**
         * @brief  モード開始
         */
        void Enter() override;

      private:
        /**
         * @brief  アルファ値の計算
         */
        void AlphaCalculation() override;
        /**
         * @brief  フェードの終了判定
         * @return true:フェード終了
         *         false:フェード継続
         */
        bool IsFadeFinish() override;
      };
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame