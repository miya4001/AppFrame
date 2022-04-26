/*****************************************************************//**
 * @file   ModeFadeBase.cpp
 * @brief  モード遷移フェードの基底クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "ModeFadeBase.h"
#include <DxLib.h>
#include "../../Application/ApplicationBase.h"
#include "../ModeServer.h"

namespace AppFrame {
  namespace Mode {
    namespace Fade {
      ModeFadeBase::ModeFadeBase(Application::ApplicationBase& app) : ModeBase(app) {

      }

      ModeFadeBase::~ModeFadeBase() {

      }

      bool ModeFadeBase::Init() {
        return true;
      }

      void ModeFadeBase::Enter() {

      }

      void ModeFadeBase::Process() {
        // フェードの終了判定
        if (IsFadeFinish()) {
          // 自身を削除する
          _app.GetModeServer().PopBuck();
        }
      }

      void ModeFadeBase::Draw() const {
        // アルファブレンドモード
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, _alpha);
        //フェードボックスの描画
        DrawBox(0, 0, ScreenWidth, ScreenHeight, GetColor(0, 0, 0), true);
        //ノーマルブレンドモード
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
      }

      bool ModeFadeBase::IsFadeFinish() {
        return true;
      }
    } // namespace Fade
  } // namespace Mode
} // namespace AppFrame