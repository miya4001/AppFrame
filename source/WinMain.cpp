/*****************************************************************//**
 * @file   WinMain.cpp
 * @brief  プログラムのエントリーポイント
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include <DxLib.h>
#include <stdexcept>
#include "Application/ApplicationBase.h"

/**
 * @brief  プログラムのエントリーポイント
 * @return 0:正常終了 -1:異常終了
 */
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
  // アプリケーションの実態を取得
  namespace App = AppFrame::Application;
  auto app = App::ApplicationBase::GetApplication();
  // アプリケーションの実体判定
  if (app == nullptr) {
    return -1; // アプリケーションの生成が行われていない
  }
#ifdef _DEBUG
  try {
    // 初期化に成功した場合のみゲームに移行
    if (app->Init()) {
      app->Run(); // ゲームループ
    }
  }
  catch (std::logic_error error) {
    // 例外をcatchした場合はプログラムを終了する
    // 発生した例外をログに出力する
    OutputDebugString(error.what());
  }
#else
  // 初期化に成功した場合のみゲームに移行
  if (app->Init()) {
    app->Run(); // ゲームループ
  }
#endif
  // アプリケーション終了
  app->Terminate();
  return 0;
}