/*****************************************************************//**
 * @file   ModelLoadServer.h
 * @brief  モデルを読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <unordered_map>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  モデル
   */
  namespace Model {
    /**
     * @class  ModelLoadServer
     * @brief  モデルを読み込むサーバクラス
     */
    class ModelLoadServer {
    public:
      /**
       * @brief  モデル情報を格納する動的配列
       * @param  モデルファイルに紐づける文字列
       * @param  モデルファイルのパス
       */
      using LoadModelMap = std::vector<std::pair<std::string_view, std::string_view>>;
      /**
       * @brief  コンストラクタ
       */
      ModelLoadServer();
      /**
       * @brief  デストラクタ
       */
      ~ModelLoadServer();
      /**
       * @brief  解放
       */
      void Release();
      /**
       * @brief  モデルの一括読み込み
       * @param  model モデル情報を格納する動的配列
       */
      void LoadModels(const LoadModelMap model);
      /**
       * @brief  複製したモデルの解放
       */
      void DeleteDuplicateModels();
      /**
       * @brief  指定したモデルハンドルの取得
       * @param  key 対象のモデルに紐づけられた文字列
       * @return モデルハンドルを返す
       *         キーが有効でない場合-1
       */
      int GetModelHandle(const std::string_view key) const;
      /**
       * @brief  指定したモデルハンドルの複製の取得
       * @param  key 対象のモデルに紐づけられた文字列
       * @return 複製したモデルハンドルを返す
       *         キーが有効でない場合-1
       */
      int GetDuplicateModelHandle(const std::string_view key);

    private:
      /**
       * @brief  モデルの読み込み
       * @param  key モデルファイルに紐づける文字列
       * @param  path モデルファイルのパス
       */
      void LoadModel(const std::string_view key, const std::string_view path);
      /**
       * @brief  モデルの複製
       * @param  key 対象のモデルに紐づけられた文字列
       * @return 複製したモデルハンドル
       */
      int DuplicateModel(const std::string_view key);

      //!< モデルレジストリ
      std::unordered_map<std::string, int> _modelRegistry;
      //!< 複製モデルレジストリ
      std::vector<int> _duplicateRegistry;
    };
  } // namespace Model
} // namespace AppFrame