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
    constexpr int AllKeyNumber = 256;  //!< キー総数
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
      /**
       * @brief  
       * @param  key 対応するキー番号
       *         DXライブラリのキーボード入力定義
       * @param  type 取得する情報の種類
       *              InputPress:押下情報
       *              InputTrigger:トリガ情報
       * @return true:入力あり
       *         false:入力なし
       */
      bool GetKey(const int key, const bool type) const;
      /**
       * @brief  何らかのキーボードの入力があるかの判定
       * @return true:入力あり
       *         false:入力なし
       */
      bool GetAnyKey() const;

    private:
      //!< 押下情報
      std::array<char, AllKeyNumber> _press;
      //!< トリガ情報
      std::array<char, AllKeyNumber> _trigger;
    };
  } // namespace Input
} // namespace AppFrame