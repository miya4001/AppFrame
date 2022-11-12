/*****************************************************************//**
 * @file   ModeBase.h
 * @brief  モードの基底クラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#pragma once

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
    class InputManager;
  } // namespace Input
  /**
   * @brief  モード
   */
  namespace Mode {
    /**
     * @class  ModeBase
     * @brief  モードの基底クラス
     */
    class ModeBase {
    public:
      /**
       * @brief  コンストラクタ
       * @param  app アプリケーションの参照
       */
      ModeBase(Application::ApplicationBase& app);
      /**
       * @brief  デストラクタ
       */
      virtual ~ModeBase();
      /**
       * @brief  初期化
       * @return true:初期化成功
       *         false:初期化失敗
       */
      virtual bool Init();
      /**
       * @brief  モード開始
       */
      virtual void Enter();
      /**
       * @brief  モード終了
       */
      virtual void Exit();
      /**
       * @brief  入力
       * @param  input インプットマネージャーの参照
       */
      virtual void Input(Input::InputManager& input);
      /**
       * @brief  更新
       */
      virtual void Process();
      /**
       * @brief  描画
       */
      virtual void Draw() const;
      /**
       * @brief  アプリケーションの取得
       * @return アプリケーションの参照
       */
      virtual Application::ApplicationBase& GetApplication();

    protected:
      /**
       * @brief  リソース読み込み
       */
      virtual void LoadResource();
      /**
       * @brief  モード切り替え
       */
      virtual void ChangeMode();

      int _modeCount{ 0 };    //!< 本モード内経過時間(フレーム)
      bool _isLoad{ false };  //!< リソース読み込みフラグ
      //!< アプリケーションの参照
      Application::ApplicationBase& _app;
    };
  } // namespace Mode
} // namespace AppFrame