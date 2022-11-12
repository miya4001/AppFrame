/*****************************************************************//**
 * @file   InputManager.h
 * @brief  全ての入力の一括管理クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "InputXJoypad.h"
#include "InputKeyboard.h"

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  アプリケーション
   */
  namespace Application {
    class ApplicationBase;
  } // namespace Application
  /**
   * @brief  入力
   */
  namespace Input {
    /**
     * @class  InputManager
     * @brief  全ての入力の一括管理クラス
     */
    class InputManager {
    public:
      /**
       * @brief  コンストラクタ
       * @param  app アプリケーションの参照
       */
      InputManager(Application::ApplicationBase& app);
      /**
       * @brief  デストラクタ
       */
      ~InputManager();
      /**
       * @brief  更新
       */
      void Process();
      /**
       * @brief  XInputジョイパッドの入力処理の取得
       * @return Xinputジョイパッドの入力処理の参照
       */
      inline InputXJoypad& GetXJoypad() {
        return _xJoypad;
      }
      /**
       * @brief  キーボードの入力処理の取得
       * @return キーボードの入力処理の参照
       */
      inline InputKeyboard& GetKeyboard() {
        return _keyboard;
      }

    private:
      //!< アプリケーションの参照
      Application::ApplicationBase& _app;
      //!< XInputジョイパッドの入力処理
      InputXJoypad _xJoypad;
      //!< キーボードの入力処理
      InputKeyboard _keyboard;
    };
  } // namespace Input
} // namespace AppFrame