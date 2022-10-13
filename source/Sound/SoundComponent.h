/*****************************************************************//**
 * @file   SoundComponent.h
 * @brief  音源コンポーネント
 * 
 * @author 宮澤耀生
 * @date   October 2022
 *********************************************************************/
#pragma once
#include <string_view>

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
   * @brief  音源
   */
  namespace Sound {
    constexpr int DefaultVolume = 100;  //!< デフォルト再生音量
    /**
     * @class  SoundComponent
     * @brief  音源コンポーネント
     */
    class SoundComponent {
    public:
      /**
       * @brief  コンストラクタ
       * @param  app アプリケーションの参照
       */
      SoundComponent(Application::ApplicationBase& app);
      /**
       * @brief  デストラクタ
       */
      ~SoundComponent();
      /**
       * @brief  音源のバックグラウンド再生
       * @param  key 音源に紐づけられた文字列
       * @param  volume 再生音量(デフォルトで100)
       */
      void PlayBackGround(const std::string_view key, const int volume = DefaultVolume);
      /**
       * @brief  音源のループ再生
       * @param  key 音源に紐づけられた文字列
       * @param  volume 再生音量(デフォルトで100)
       */
      void PlayLoop(const std::string_view key, const int volume = DefaultVolume);
      /**
       * @brief  音源の再生停止
       * @param  key 音源に紐づけられた文字列
       */
      void StopSound(const std::string_view key);
      /**
       * @brief  音源の再生判定
       * @param  key 音源に紐づけられた文字列
       * @return true:再生中
       *         false:再生されていない
       */
      bool CheckSound(const std::string_view key);

    private:
      /**
       * @brief  音源の再生
       * @param  key 音源に紐づけられた文字列
       * @param  type 再生タイプ
       */
      void Play(const std::string_view key, const int type);
      /**
       * @brief  音源の音量の設定
       * @param  key 音源に紐づけられた文字列
       * @param  volume 再生音量(0~255)
       */
      void SetVolume(const std::string_view key, const int volume);
      /**
       * @brief  音源ハンドルの取得
       * @param  key 音源に紐づけられた文字列
       * @return 音源ハンドルを返す
       *         取得に失敗した場合-1
       */
      int GetSoundHandle(const std::string_view key);

      //!< アプリケーションの参照
      Application::ApplicationBase& _app;
    };
  } // namespace Sound
} // namespace AppFrame