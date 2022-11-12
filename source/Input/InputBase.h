/*****************************************************************//**
 * @file   InputBase.h
 * @brief  入力処理の基底クラス
 * 
 * @author 宮澤耀生
 * @date   November 2022
 *********************************************************************/
#pragma once
#include <DxLib.h>
#include <array>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  入力
   */
  namespace Input {
    constexpr int InputError = -1;        //!< エラー
    constexpr bool InputPress = true;     //!< 押下情報
    constexpr bool InputTrigger = false;  //!< トリガ情報
    /**
     * @class  InputBase
     * @brief  入力処理の基底クラス
     */
    class InputBase {
    public:
      /**
       * @brief  コンストラクタ
       */
      InputBase();
      /**
       * @brief  デストラクタ
       */
      virtual ~InputBase();
      /**
       * @brief  初期化
       * @return true:初期化成功
       *         false:初期化失敗
       */
      virtual bool Init();
      /**
       * @brief  更新
       */
      virtual void Process();
    };
  } // namespace Input
} // namespace AppFrame