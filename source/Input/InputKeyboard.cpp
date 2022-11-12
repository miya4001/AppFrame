/*****************************************************************//**
 * @file   InputKeyboard.cpp
 * @brief  キーボードの入力処理クラス
 * 
 * @author 宮澤耀生
 * @date   November 2022
 *********************************************************************/
#include "InputKeyboard.h"
#include "../Math/Utility.h"

namespace AppFrame {
  namespace Input {
    InputKeyboard::InputKeyboard() {
      Init();
    }

    bool InputKeyboard::Init() {
      // 入力情報の設定
      _press.fill(0);
      _trigger = _press;
      return true;
    }

    void InputKeyboard::Process() {
      // 前フレームのキーボード入力情報
      auto old = _press;
      // 押下状態を格納する配列
      char keyboard[AllKeyNumber];
      // 入力状態の取得に成功したか
      if (GetHitKeyStateAll(keyboard) == InputError) {
        return; // 取得失敗
      }
      // 各種状態の更新
      for (auto num = 0; auto&& key : _press) {
        // 押下情報の更新
        key = keyboard[num];
        // トリガ情報の更新
        _trigger[num] = _press[num] ^ old[num] & _press[num];
        // 番号を増やす
        ++num;
      }
    }

    bool InputKeyboard::GetKey(const int key, const bool type) const {
      // 範囲内判定
      bool isRange = AppFrame::Math::Utility::IsRange(key, 0, AllKeyNumber - 1);
      // 範囲内に収まっていない場合
      if (!isRange) {
        return false;  // キーが不正
      }
      // フラグに応じて返す値を切り替える
      if (type == InputPress) {
        // 押下情報を返す
        return _press[key];
      } else {
        // トリガ情報を返す
        return _trigger[key];
      }
    }

    bool InputKeyboard::GetAnyKey() const {
      // 何らかのキーボード入力があるか
      for (auto key : _press) {
        if (key == 1) {
          return true;  // 入力あり
        }
      }
      return false;  // 入力なし
    }
  } // namespace Input
} // namespace AppFrame