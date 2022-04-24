/*****************************************************************//**
 * @file   InputXJoypad.h
 * @brief  XInputジョイパッドの入力処理クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
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
    constexpr int ButtonNum = 16;         //!< ボタン総数
    constexpr bool InputPress = true;     //!< 押下情報
    constexpr bool InputTrigger = false;  //!< トリガ情報
    constexpr bool StickLeft = true;      //!< 左スティック
    constexpr bool StickRight = false;    //!< 右スティック
    /**
     * @class  InputXJoypad
     * @brief  XInputジョイパッドの入力処理クラス
     */
    class InputXJoypad {
    public:
      /**
       * @brief  コンストラクタ
       */
      InputXJoypad();
      /**
       * @brief  デストラクタ
       */
      ~InputXJoypad();
      /**
       * @brief  更新
       */
      void Process();
      /**
       * @brief  ボタンの入力状態の取得
       * @param  key 対応するキー番号(0～15)
       *             DXライブラリのXINPUTボタン入力定義
       * @param  type 取得する情報の種類
       *              InputPress:押下情報
       *              InputTrigger:トリガ情報
       * @return true:入力あり
       *         false:入力なし
       */
      bool GetButton(const int key, const bool type) const;
      /**
       * @brief  何らかのボタンの入力があるかの判定
       * @return true:入力あり
       *         false:入力なし
       */
      bool GetAnyButton() const;
      /**
       * @brief  アナログスティックの入力状態の取得
       * @param  stick 取得するスティックの左右
       *               StickLeft:左スティック
       *               StickRight:右スティック
       * @return first:横軸の入力状態
       *         second:縦軸の入力状態
       */
      std::pair<int, int> GetStick(const bool stick) const;

    private:
      /**
       * @brief  アナログスティックの更新
       */
      void AnalogStickUpdate();
      /**
       * @brief  デッドゾーン処理
       * @param  stick スティック入力情報の参照
       */
      void DeadZone(short& stick);
      /**
       * @brief  トリガ情報の生成
       * @param  press 対象キーの押下状態
       * @param  old 前フレームの対象キーの押下状態
       * @return 対象キーのトリガ情報
       */
      inline int Trigger(const int press, const int old) {
        return press ^ old & press;
      }

      //!< 入力情報(押下入力)
      XINPUT_STATE _press;
      //!< 各種ボタンの押下情報
      std::array<bool, ButtonNum> _triggerButtons;
      //!< 各種スティックのデッドゾーン情報
      std::pair<short, short> _deadZone;
    };
  } // namespace Input
} // namespace AppFrame