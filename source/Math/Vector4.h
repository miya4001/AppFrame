/*****************************************************************//**
 * @file   Vector4.h
 * @brief  四次元ベクトルクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <tuple>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  算術
   */
  namespace Math {
    /**
     * @class  Vector4
     * @brief  四次元ベクトルクラス
     */
    class Vector4 {
    public:
      /**
       * @brief  空ベクトルの生成
       */
      Vector4();
      /**
       * @brief  二次元ベクトルの生成
       * @param  x x成分
       * @param  y y成分
       */
      Vector4(const float x, const float y);
      /**
       * @brief  ベクトルの生成
       * @param  x x成分
       * @param  y y成分
       * @param  z z成分
       * @param  w w成分(デフォルトで1.0)
       */
      Vector4(const float x, const float y, const float z, const float w = 1.0);
      /**
       * @brief  ゼロベクトル化
       */
      void Zero();
      /**
       * @brief  ベクトル同士の加算
       * @param  vector ベクトル(加数)
       */
      void Add(const Vector4 vector);
      /**
       * @brief  ベクトル同士の減算
       * @param  vector ベクトル(減数)
       */
      void Sub(const Vector4 vector);
      /**
       * @brief  ベクトル同士の各成分の乗算
       * @param  vector ベクトル(乗数)
       */
      void Scale(const Vector4 vector);
      /**
       * @brief  ベクトルの設定
       * @param  vector 指定するベクトル
       */
      void Set(const Vector4 vector);
      /**
       * @brief  指定した値をベクトルに設定
       * @param  x x成分に指定する値
       * @param  y y成分に指定する値
       * @param  z z成分に指定する値
       */
      void Set(const float x, const float y, const float z);
      /**
       * @brief  指定した値をxyz成分に設定
       * @param  value 指定する値
       */
      void Fill(const float value);
      /**
       * @brief  指定した値をx成分に設定
       * @param  x x成分に指定する値
       */
      inline void SetX(const float x) {
        _x = x;
      }
      /**
       * @brief  指定した値をy成分に設定
       * @param  y y成分に指定する値
       */
      inline void SetY(const float y) {
        _y = y;
      }
      /**
       * @brief  指定した値をz成分に設定
       * @param  z z成分に指定する値
       */
      inline void SetZ(const float z) {
        _z = z;
      }
      /**
       * @brief  2次元ベクトルの取得
       * @return x成分, y成分
       */
      inline const std::pair<float, float> GetVector2() const {
        return { _x, _y };
      }
      /**
       * @brief  3次元ベクトルの取得
       * @return x成分, y成分, z成分
       */
      inline const std::tuple<float, float, float> GetVector3() const {
        return { _x, _y, _z };
      }
      /**
       * @brief  4次元ベクトルの取得
       * @return x成分, y成分, z成分, w成分
       */
      inline const std::tuple<float, float, float, float> GetVector4() const {
        return { _x, _y, _z, _w };
      }
      /**
       * @return x成分の取得
       * @brief  x成分
       */
      inline const float GetX() const {
        return _x;
      }
      /**
       * @brief  y成分の取得
       * @return y成分
       */
      inline const float GetY() const {
        return _y;
      }
      /**
       * @brief  z成分の取得
       * @return z成分
       */
      inline const float GetZ() const {
        return _z;
      }
      /**
       * @brief  w成分の取得
       * @return w成分
       */
      inline const float GetW() const {
        return _w;
      }
      /**
       * @brief  ベクトルの長さの取得
       * @return ベクトルの長さ
       */
      float Length() const;
      /**
       * @brief  指定したベクトルの長さの取得
       * @param  vector 指定するベクトル
       * @return 指定したベクトルの長さ
       */
      static float Length(const Vector4& vector);
      /**
       * @brief  ベクトルの長さの取得(2次元)
       * @return ベクトルの長さ(2次元)
       */
      float Length2D() const;
      /**
       * @brief  ベクトルの長さの二乗の取得
       * @return ベクトルの長さの二乗
       */
      float LengthSquared() const;
      /**
       * @brief  指定したベクトルの長さの二乗の取得
       * @param  vector 指定するベクトル
       * @return 指定したベクトルの長さの二乗
       */
      static float LengthSquared(const Vector4& vector);
      /**
       * @brief  ベクトルの長さの二乗の取得(2次元)
       * @return ベクトルの長さの二乗(2次元)
       */
      float LengthSquared2D() const;
      /**
       * @brief  ベクトルの正規化
       */
      void Normalize();
      /**
       * @brief  単位ベクトルの取得
       * @param  vector ベクトル
       * @return 単位ベクトル
       */
      static Vector4 Normalize(const Vector4& vector);
      /**
       * @brief  ベクトルの内積の取得
       * @param  vector ベクトル
       * @return ベクトルの内積
       */
      float Dot(const Vector4& vector) const;
      /**
       * @brief  指定したベクトルの内積の取得
       * @param  left ベクトル(左辺)
       * @param  right ベクトル(右辺)
       * @return 指定したベクトルの内積
       */
      static float Dot(const Vector4& left, const Vector4& right);
      /**
       * @brief  ベクトルの内積の取得(2次元)
       * @param  vector ベクトル(2次元)
       * @return ベクトルの内積(2次元)
       */
      float Dot2D(const Vector4& vector) const;
      /**
       * @brief  ベクトルの外積の取得
       * @param  vector ベクトル
       * @return ベクトルの外積
       */
      Vector4 Cross(const Vector4& vector) const;
      /**
       * @brief  指定したベクトルの外積の取得
       * @param  left ベクトル(左辺)
       * @param  right ベクトル(右辺)
       * @return 指定したベクトルの外積
       */
      static Vector4 Cross(const Vector4& left, const Vector4& right);
      /**
       * @brief  対象ベクトルへ向かうベクトルの取得
       * @param  vector 対象ベクトル
       * @return 向きベクトル
       */
      Vector4 Direction(const Vector4& vector) const;
      /**
       * @brief  ベクトルがゼロかの判定
       * @param  vector ベクトル
       * @return true:ゼロ
       *         false:ゼロではない
       */
      static bool IsZero(const Vector4& vector);
      /**
       * @brief  ベクトル同士の加算
       * @param  vector ベクトル(加数)
       * @return 加算したベクトル
       */
      Vector4 operator+(const Vector4& vector) const;
      /**
       * @brief  ベクトル同士の減算
       * @param  vector ベクトル(減数)
       * @return 減算したベクトル
       */
      Vector4 operator-(const Vector4& vector) const;
      /**
       * @brief  ベクトルのスカラー倍
       * @param  scalar スカラー値
       * @return スカラー倍したベクトル
       */
      Vector4 operator*(const float scalar) const;
      /**
       * @brief  ベクトルのスカラー割
       * @param  scalar スカラー値
       * @return スカラー割したベクトル
       */
      Vector4 operator/(const float scalar) const;

    private:
      float _x;  //!< x成分
      float _y;  //!< y成分
      float _z;  //!< z成分
      float _w;  //!< w成分
    };
  } // namespace Math
} // namespace AppFrame