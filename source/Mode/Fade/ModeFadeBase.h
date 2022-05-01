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
      constexpr float AlphaMax = 255.0f;  //!< アルファ値の上限
      constexpr float AlphaMin = 0.0f;    //!< アルファ値の下限
      constexpr float FadeTime = 60.0f;   //!< フェード時間(フレーム)
      constexpr float AlphaSpeed = (AlphaMax / FadeTime);  //!< アルファ値の変化量
      /**
       * @class  ModeFadeBase
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
        void Draw() const override;

      protected:
        /**
         * @brief  アルファ値の計算
         */
        virtual void AlphaCalculation();
        /**
         * @brief  フェードの終了判定
         * @return true:フェード終了
         *         false:フェード継続
         */
        virtual bool IsFadeFinish() const;

        float _alpha{ 0 };  //!< アルファ値
      };
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame