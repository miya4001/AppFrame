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
   * @brief  画像
   */
  namespace Graphic {
    class GraphicLoadServer;
  } // namespace Graphic
  /**
   * @brief  モデル
   */
  namespace Model {
    class ModelLoadServer;
  } // namespace Model
  /**
   * @brief  エフェクト
   */
  namespace Effect {
    class EffectLoadServer;
  } // namespace Effect
  /**
   * @brief  音源
   */
  namespace Sound {
    class SoundLoadServer;
    class SoundComponent;
  } // namespace Sound
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
       * @brief  モードサーバの取得
       * @return モードサーバの参照
       */
      Mode::ModeServer& GetModeServer();
      /**
       * @brief  画像読み込みサーバの取得
       * @return 画像読み込みサーバの参照
       */
      Graphic::GraphicLoadServer& GetGraphicLoadServer();
      /**
       * @brief  モデル読み込みサーバの取得
       * @return モデル読み込みサーバの参照
       */
      Model::ModelLoadServer& GetModelLoadServer();
      /**
       * @brief  エフェクト読み込みサーバの取得
       * @return エフェクト読み込みサーバの参照
       */
      Effect::EffectLoadServer& GetEffectLoadServer();
      /**
       * @brief  音源読み込みサーバの取得
       * @return 音源読み込みサーバの参照
       */
      Sound::SoundLoadServer& GetSoundLoadServer();
      /**
       * @brief  音源コンポーネントの取得
       * @return 音源コンポーネントの参照
       */
      Sound::SoundComponent& GetSoundComponent();

    protected:
      /**
       * @brief  解放
       */
      virtual void Release();
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
      std::unique_ptr<Input::InputManager> _inputManager{ nullptr };
      //!< モードサーバ
      std::unique_ptr<Mode::ModeServer> _modeServer{ nullptr };
      //!< 画像読み込みサーバ
      std::unique_ptr<Graphic::GraphicLoadServer> _graphicLoadServer{ nullptr };
      //!< モデル読み込みサーバ
      std::unique_ptr<Model::ModelLoadServer> _modelLoadServer{ nullptr };
      //!< エフェクト読み込みサーバ
      std::unique_ptr<Effect::EffectLoadServer> _effectLoadServer{ nullptr };
      //!< 音源読み込みサーバ
      std::unique_ptr<Sound::SoundLoadServer> _soundLoadServer{ nullptr };
      //!< 音源コンポーネント
      std::unique_ptr<Sound::SoundComponent> _soundComponent{ nullptr };
    };
  } // namespace Application
} // namespace AppFrame