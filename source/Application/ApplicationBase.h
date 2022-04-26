/*****************************************************************//**
 * @file   ApplicationBase.h
 * @brief  アプリケーションの基底クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#pragma once
#include <memory>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  constexpr int ScreenWidth = 1920;   //!< 画面解像度(横)
  constexpr int ScreenHeight = 1080;  //!< 画面解像度(縦)
  constexpr int ColorBit = 32;        //!< ビットカラー
  constexpr int Particle = 8000;      //!< パーティクル数
  /**
   * @brief  入力
   */
  namespace Input {
    class InputManager;
  } // namespace Input
  /**
   * @brief  モード
   */
  namespace Mode {
    class ModeServer;
  } // namespace Mode
  /**
   * @brief  アプリケーション
   */
  namespace Application {
    /**
     * @class  ApplicationBase
     * @brief  アプリケーションの基底クラス
     */
    class ApplicationBase {
    public:
      /**
       * @brief  アプリケーションの状態
       */
      enum class AppState {
        Play,    //!< 実行中
        Paused,  //!< 一時停止
        Quit     //!< 終了
      };
      /**
       * @brief  コンストラクタ
       */
      ApplicationBase();
      /**
       * @brief  デストラクタ
       */
      virtual ~ApplicationBase();
      /**
       * @brief  アプリケーションの初期化
       * @return true:初期化成功
       *         false:初期化失敗
       */
      virtual bool Init();
      /**
       * @brief  アプリケーションの実行
       */
      virtual void Run();
      /**
       * @brief  アプリケーションの終了
       */
      virtual void Terminate();
      /**
       * @brief  アプリケーションの終了要請
       */
      virtual void RequestTerminate();
      /**
       * @brief  アプリケーションの参照を取得
       * @return アプリケーションの参照
       */
      static std::shared_ptr<ApplicationBase> GetApplication() {
        return _application;
      }
      /**
       * @brief  インプットマネージャーの取得
       * @return インプットマネージャーの参照
       */
      Input::InputManager& GetInputManager();
      /**
       * @brief  モードサーバーの取得
       * @return モードサーバーの参照
       */
      Mode::ModeServer& GetModeServer();

    protected:
      /**
       * @brief  入力
       */
      virtual void Input();
      /**
       * @brief  更新
       */
      virtual void Process();
      /**
       * @brief  描画
       */
      virtual void Draw();
      /**
       * @brief  Dxライブラリの初期化
       * @return true:初期化成功
       *         false:初期化失敗
       */
      virtual bool DxLibInit();
      /**
       * @brief  Effekseerの初期化
       * @return true:初期化成功
       *         false:初期化失敗
       */
      virtual bool EffekseerInit();
      /**
       * @brief  アプリケーションを生成するかの判定
       * @return true:生成する
       *         false:生成しない
       */
      static bool IsSetApplication();

      static inline bool _windowMode{ false };  //!< 画面モード
      static inline bool _isSetApp{ false };    //!< 生成フラグ

      //!< アプリケーションの状態
      AppState _appState{ AppState::Paused };
      //!< アプリケーションの実態
      static inline std::shared_ptr<ApplicationBase> _application{ nullptr };
      //!< インプットマネージャー
      std::unique_ptr<Input::InputManager> _input{ nullptr };
      //!< モードサーバー
      std::unique_ptr<Mode::ModeServer> _modeServer{ nullptr };
    };
  } // namespace Application
} // namespace AppFrame