/*****************************************************************//**
 * @file   Utility.h
 * @brief  算術処理の補助機能クラス
 * 
 * @author 宮澤耀生
 * @date   July 2022
 *********************************************************************/
#pragma once
#include <numbers>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  算術
   */
  namespace Math {
    class Vector4;
    class Matrix44;
    constexpr auto Degree = true;   //!< デグリーフラグ
    constexpr auto Radian = false;  //!< ラジアンフラグ
    /**
     * @class  Utility
     * @brief  算術処理の補助機能クラス
     */
    class Utility {
    public:
      //!< 円周率PIの定数
      static constexpr float Pi = static_cast<float>(std::numbers::pi);
      //!< 180度 
      static constexpr float Degrees180 = 180.0f;
      /**
       * @brief  二つの値を比較して最小値を返す(int型)
       * @param  a 値a
       * @param  b 値b
       * @return 最小値
       */
      static int Min(const int a, const int b);
      /**
       * @brief  二つの値を比較して最小値を返す(float型)
       * @param  a 値a
       * @param  b 値b
       * @return 最小値
       */
      static float Min(const float a, const float b);
      /**
       * @brief  二つの値を比較して最大値を返す(int型)
       * @param  a 値a
       * @param  b 値b
       * @return 最大値
       */
      static int Max(const int a, const int b);
      /**
       * @brief  二つの値を比較して最大値を返す(float型)
       * @param  a 値a
       * @param  b 値b
       * @return 最大値
       */
      static float Max(const float a, const float b);
      /**
       * @brief  クランプ処理(int型)
       * @param  value 対象値
       * @param  min 最小値
       * @param  max 最大値
       * @return クランプした値
       */
      static int Clamp(const int value, const int min, const int max);
      /**
       * @brief  クランプ処理(float型)
       * @param  value 対象値
       * @param  min 最小値
       * @param  max 最大値
       * @return クランプした値
       */
      static float Clamp(const float value, const float min, const float max);
      /**
       * @brief  対象値を正数に変換
       * @param  value 対象値
       * @return 対象値を正数に変換した値
       */
      static float ToPlus(const float value);
      /**
       * @brief  対象値が正数か判定
       * @param  value 対象値
       * @return true:正数
       *         false:負数
       */
      static bool IsPositive(const int value);
      /**
       * @brief  対象値が範囲内に収まっているか判定
       * @param  value 対象値
       * @param  min 最小値
       * @param  max 最大値
       * @return true:範囲内
       *         false:範囲外
       */
      static bool IsRange(const int value, const int min, const int max);
      /**
       * @brief  カウント増加
       * @param  count カウント
       * @param  max カウント上限
       * @return カウントを1増やした値
       *         カウント上限の場合0を返す
       */
      static int IncrementCount(const int count, const int max);
      /**
       * @brief  デグリー値をラジアン値に変換
       * @param  degree デグリー値
       * @return ラジアン値
       */
      static inline float DegreeToRadian(const float degree) {
        return degree * Pi / Degrees180;
      }
      /**
       * @brief  ラジアン値をデグリー値に変換
       * @param  radian ラジアン値
       * @return デグリー値
       */
      static inline float RadianToDegree(const float radian) {
        return radian * Degrees180 / Pi;
      }
      /**
       * @brief  回転ベクトル(デグリー値)び各成分をラジアン値に変換
       * @param  rotation 回転ベクトル(デグリー値)
       * @return 各成分をラジアン値に変換したベクトル
       */
      static Vector4 RotationToRadian(const Vector4& rotation);
      /**
       * @brief  ワールド座標変換
       * @param  position ローカル座標
       * @param  rotation 回転ベクトル
       * @param  scale 拡大率
       * @param  angle ローテーションフラグ(true:デグリー値 false:ラジアン値)
       * @return ワールド座標
       */
      static Matrix44 ToWorldMatrix(const Vector4& position, Vector4 rotation, const Vector4& scale, const bool angle);
      /**
       * @brief  行列を使用したベクトルの変換
       * @param  vector 変換するベクトル
       * @param  matrix 使用する行列
       * @return 変換したベクトル
       */
      static Vector4 TransformVector(const Vector4& vector, const Matrix44& matrix);
    };
  } // namespace Math
} // namespace AppFrame