/*****************************************************************//**
 * @file   ModeFadeOut.cpp
 * @brief  モード遷移フェードアウトクラス
 *
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "ModeFadeOut.h"
#include "../../Application/ApplicationBase.h"
#include "../ModeServer.h"

namespace AppFrame {
  namespace Mode {
    namespace Fade {
      ModeFadeOut::ModeFadeOut(Application::ApplicationBase& app) : ModeFadeBase(app) {

      }

      void ModeFadeOut::Enter() {
        // アルファ値の初期化
        _alpha = AlphaMin;
      }

      void ModeFadeOut::Process() {
        // アルファ値の計算
        AlphaCalculation();
        // フェードの終了判定
        if (IsFadeFinish()) {
          // 自身を削除する
          _app.GetModeServer().PopBuck();
          // 自身の直前のモードを削除する
          _app.GetModeServer().PopBuck();
        }
      }

      void ModeFadeOut::AlphaCalculation() {
        // アルファ値の加算
        _alpha += AlphaSpeed;
      }

      bool ModeFadeOut::IsFadeFinish() {
        // アルファ値は上限以上か
        return AlphaMax <= _alpha;
      }
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame