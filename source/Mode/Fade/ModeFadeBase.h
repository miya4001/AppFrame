/*****************************************************************//**
 * @file   ModeFadeBase.h
 * @brief  モード遷移フェードの基底クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#pragma once
#include "../ModeBase.h"

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
       * @class  ModeFade
       * @brief  モード遷移フェードの基底クラス
       */
      class ModeFadeBase : public ModeBase {
      public:
        /**
         * @brief  コンストラクタ
         * @param  app アプリケーションの参照
         */
        ModeFadeBase(Application::ApplicationBase& app);
        /**
         * @brief  デストラクタ
         */
        ~ModeFadeBase() override;
        /**
         * @brief  初期化
         * @return true:初期化成功
         *         false:初期化失敗
         */
        bool Init() override;
        /**
         * @brief  モード開始
         */
        virtual void Enter() override;
        /**
         * @brief  更新
         */
        virtual void Process() override;
        /**
         * @brief  描画
         */
        virtual void Draw() const override;

      protected:
        /**
         * @brief  フェードの終了判定
         * @return true:フェード終了
         *         false:フェード継続
         */
        virtual bool IsFadeFinish();

        int _alpha{ 0 };  //!< アルファ値
      };
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame