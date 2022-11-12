/*****************************************************************//**
 * @file   InputKeyboard.h
 * @brief  キーボードの入力処理クラス
 * 
 * @author 宮澤耀生
 * @date   November 2022
 *********************************************************************/
#pragma once
#include "InputBase.h"

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
 * @brief  入力
 */
  namespace Input {
    /**
     * @class  InputKeyboard
     * @brief  キーボードの入力処理クラス
     */
    class InputKeyboard : public InputBase {
    public:
      /**
       * @brief  コンストラクタ
       */
      InputKeyboard();
      /**
       * @brief  初期化
       * @return true:初期化成功
       *         false:初期化失敗
       */
      bool Init() override;
      /**
       * @brief  更新
       */
      void Process() override;

    private:

    };
  } // namespace Input
} // namespace AppFrame