/*****************************************************************//**
 * @file   InputXJoypad.cpp
 * @brief  XInputジョイパッドの入力処理クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "InputXJoypad.h"
#include <DxLib.h>
#include <algorithm>
#include "../Math/Utility.h"

namespace {
  constexpr int DeadZoneMin = 3000;    //!< デッドゾーン下限絶対値
  constexpr int DeadZoneMax = 30000;   //!< デッドゾーン上限絶対値
  constexpr int Error = -1;            //!< エラー
  constexpr int ButtonNumberMin = 0;   //!< ボタン番号下限
  constexpr int ButtonNumberMax = 15;  //!< ボタン番号上限

} // namespace

namespace AppFrame {
  namespace Input {
    InputXJoypad::InputXJoypad() {
      _press = XINPUT_STATE();
      _triggerButtons.fill(false);
      // デッドゾーン設定
      _deadZone = std::make_pair(DeadZoneMin, DeadZoneMax);
    }

    InputXJoypad::~InputXJoypad() {

    }

    void InputXJoypad::Process() {
      // 前フレームのボタン入力情報
      auto old = _press;
      // 入力状態の取得に失敗した場合エラー
      if (GetJoypadXInputState(DX_INPUT_PAD1, &_press) == Error) {
        return;  // 取得失敗
      }
      // アナログスティックの更新
      AnalogStickUpdate();
      // ボタンのトリガ情報の更新
      for (auto no = 0; auto && button : _triggerButtons) {
        // 入力状態を比較してトリガ情報を算出
        button = Trigger(_press.Buttons[no], old.Buttons[no]);
        no++;
      }
    }

    bool InputXJoypad::GetButton(const int key, const bool type) const {
      // 範囲内判定
      bool isRange = AppFrame::Math::Utility::IsRange(key, ButtonNumberMin, ButtonNumberMax);
      // 範囲内に収まっていない場合
      if (!isRange) {
        return false;  // キーが不正
      }
      // フラグに応じて返す値を切り替える
      if (type == InputPress) {
        // 押下情報を返す
        return _press.Buttons[key];
      } else {
        // トリガ情報を返す
        return _triggerButtons[key];
      }
    }

    bool InputXJoypad::GetAnyButton() const {
      // 何らかのボタン入力があるか
      for (auto button : _press.Buttons) {
        if (button == 1) {
          return true;  // 入力あり
        }
      }
      return false;  // 入力なし
    }

    std::pair<int, int> InputXJoypad::GetStick(const bool stick) const {
      int x, y;  // 縦横の入力状態
      // 左右どちらの入力状態を取得するか
      if (stick == StickLeft) {
        // 左スティックの入力状態
        x = static_cast<int>(_press.ThumbLX);
        y = static_cast<int>(_press.ThumbLY);
        return std::make_pair(x, y);
      } else {
        // 右スティックの入力状態
        x = static_cast<int>(_press.ThumbRX);
        y = static_cast<int>(_press.ThumbRY);
        return std::make_pair(x, y);
      }
    }

    void InputXJoypad::AnalogStickUpdate() {
      // 各種スティック情報にデッドゾーン処理
      DeadZone(_press.ThumbLX);
      DeadZone(_press.ThumbLY);
      DeadZone(_press.ThumbRX);
      DeadZone(_press.ThumbRY);
    }

    void InputXJoypad::DeadZone(short& stick) {
      // 正負どちらか判定
      bool isPositive = 0 <= stick;
      short p = isPositive ? 1 : -1;
      short min = _deadZone.first * p;
      short max = _deadZone.second * p;
      // 正負に応じて処理
      if (isPositive) {
        // 下限よりも小さい場合0とする
        if (stick < min) {
          stick = 0;
          return;
        }
        // クランプ処理
        stick = std::clamp(stick, min, max);
        return;
      } else {
        // 下限よりも大きい場合0とする
        if (min < stick) {
          stick = 0;
          return;
        }
        // クランプ処理
        stick = std::clamp(stick, max, min);
        return;
      }
    }
  } // namespace Input
} // namespace AppFrame