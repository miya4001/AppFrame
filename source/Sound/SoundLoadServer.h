/*****************************************************************//**
 * @file   SoundLoadServer.h
 * @brief  音源を読み込むサーバクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <unordered_map>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame{
  /**
   * @brief  音源
   */
  namespace Sound {
    /**
     * @class  SoundLoadServer
     * @brief  音源を読み込むサーバクラス
     */
    class SoundLoadServer {
    public:
      /**
       * @brief  音源情報を格納する動的配列
       * @param  音源ファイルに紐づける文字列
       * @param  音源ファイルのパス
       */
      using LoadSoundMap = std::vector<std::pair<std::string_view, std::string_view>>;
      /**
       * @brief  コンストラクタ
       */
      SoundLoadServer();
      /**
       * @brief  デストラクタ
       */
      ~SoundLoadServer();
      /**
       * @brief  解放
       */
      void Release();
      /**
       * @brief  音源の一括読み込み
       * @param  sound 音源情報を格納する動的配列
       */
      void LoadSounds(const LoadSoundMap sound);
      /**
       * @brief  指定した音源ハンドルの取得
       * @param  key 対象の音源に紐づけられた文字列
       * @return 音源ハンドルを返す
       *         キーが有効でない場合-1
       */
      int GetSoundHandle(const std::string_view key) const;

    private:
      /**
       * @brief  音源の読み込み
       * @param  key 音源ファイルに紐づける文字列
       * @param  path 音源ファイルのパス
       */
      void LoadSound(const std::string_view key, const std::string_view path);

      //!< 音源レジストリ
      std::unordered_map<std::string, int> _soundRegistry;
    };
  } // namespace Sound
} // namespace AppFrame