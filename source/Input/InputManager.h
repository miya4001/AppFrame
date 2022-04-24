/*****************************************************************//**
 * @file   InputManager.h
 * @brief  全ての入力の一括管理クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#include "InputXJoypad.h"

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

    private:
      //!< アプリケーションの参照
      Application::ApplicationBase& _app;
      //!< XInputジョイパッドの入力処理の参照
      InputXJoypad _xJoypad;
    };
  } // namespace Input
} // namespace AppFrame