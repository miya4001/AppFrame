/*****************************************************************//**
 * @file   ModeFadeOut.cpp
 * @brief  モード遷移フェードアウトクラス
 *
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "ModeFadeOut.h"

namespace AppFrame {
  namespace Mode {
    namespace Fade {
      ModeFadeOut::ModeFadeOut(Application::ApplicationBase& app) : ModeFadeBase(app) {

      }

      void ModeFadeOut::Enter() {
        // アルファ値の初期化
        _alpha = AlphaMin;
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