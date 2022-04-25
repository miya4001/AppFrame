/*****************************************************************//**
 * @file   ModeServer.h
 * @brief  各種モードを管理するサーバクラス
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#pragma once
#include <memory>
#include <unordered_map>

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
  } // namespace InputManager
  /**
   * @brief  モード
   */
  namespace Mode {
    class ModeBase;
    /**
     * @class  ModeServer
     * @brief  各種モードを管理するサーバクラス
     */
    class ModeServer {
    public:
      /**
       * @brief  コンストラクタ
       * @param  app アプリケーションの参照
       */
      ModeServer(Application::ApplicationBase& app);
      /**
       * @brief  デストラクタ
       */
      ~ModeServer();
      /**
       * @brief  更新
       */
      virtual void Process();
      /**
       * @brief  描画
       */
      virtual void Draw() const;
      /**
       * @brief  データベースにモードを登録
       * @param  key 登録に使用する文字列
       * @param  mode 登録するモードのシェアードポインタ
       */
      void AddMode(std::string_view key, std::shared_ptr<ModeBase> mode);
      /**
       * @brief  指定したモードをリストの末尾に追加
       * @param  key 対象モードに紐づけられた文字列
       */
      void PushBack(std::string_view key);
      /**
       * @brief  リストの末尾に登録されているモードを削除
       */
      void PopBuck();
      /**
       * @brief  モード遷移
       * @param  key 対象モードに紐づけられた文字列
       */
      void TransionToMode(std::string_view key);

    private:
      /**
       * @brief  データベースから指定したモードを取得
       * @param  key 対象モードに紐づけられた文字列
       * @param  enter モード開始処理を行うか判定
       * @return 指定したモードを返す
       *         キーが有効でない場合nullptrを返す
       */
      std::shared_ptr<ModeBase> FetchMode(std::string_view key, const bool enter = true);

      //!< モードデータベース(登録用)
      std::unordered_map<std::string, std::shared_ptr<ModeBase>> _modeRegistry;
      //!< モードリスト(処理用)
      std::list<std::shared_ptr<ModeBase>> _modeList;
    };
  } // namespace Mode
} // namespace AppFrame