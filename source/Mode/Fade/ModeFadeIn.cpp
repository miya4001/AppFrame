/*****************************************************************//**
 * @file   ModeFadeIn.cpp
 * @brief  モード遷移フェードインクラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "ModeFadeIn.h"

namespace AppFrame {
  namespace Mode {
    namespace Fade {
      ModeFadeIn::ModeFadeIn(Application::ApplicationBase& app) : ModeFadeBase(app) {

      }

      void ModeFadeIn::Enter() {
        // アルファ値の初期化
        _alpha = AlphaMax;
      }

      void ModeFadeIn::AlphaCalculation() {
        // アルファ値の減算
        _alpha -= AlphaSpeed;
      }

      bool ModeFadeIn::IsFadeFinish() {
        // アルファ値は下限以下か
        return _alpha <= AlphaMin;
      }
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame