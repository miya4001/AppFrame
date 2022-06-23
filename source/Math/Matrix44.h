/*****************************************************************//**
 * @file   Matrix44.h
 * @brief  4*4行列クラス
 * 
 * @author 宮澤耀生
 * @date   June 2022
 *********************************************************************/
#pragma once
#include <array>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  算術
   */
  namespace Math {
    class Vector4;
    constexpr int MaxRow = 4;     //!< 行の上限
    constexpr int MaxColumn = 4;  //!< 列の上限
    /**
     * @class  Matrix44
     * @brief  4*4行列クラス
     */
    class Matrix44 {
    private:
      // float型の4*4行列を表す2次元配列
      using MatrixArray = std::array<std::array<float, MaxColumn>, MaxRow>;

    public:
      /**
       * @brief  空の行列を生成
       */
      Matrix44();
      /**
       * @brief  行列コピー
       * @param  values 行列
       */
      Matrix44(const MatrixArray values);
      /**
       * @brief  行列の削除
       */
      ~Matrix44() = default;
      /**
       * @brief  行列の初期化
       * @param  matrix 行列
       */
      static void Reset(MatrixArray& matrix);
      /**
       * @brief  単位行列化
       * @return 単位行列
       */
      static Matrix44 Identity();
      /**
       * @brief  指定した行列の単位行列の取得
       * @param  matrix 行列
       * @return 単位行列
       */
      static Matrix44 Identity(const Matrix44& matrix);
      /**
       * @brief  平行移動行列の取得
       * @param  x x成分
       * @param  y y成分
       * @param  z z成分
       * @return 平行移動行列
       */
      static Matrix44 Translate(const float x, const float y, const float z);
      /**
       * @brief  ベクトルを平行移動行列に変換
       * @param  vector ベクトル
       * @return 平行移動行列
       */
      static Matrix44 Translate(const Vector4& vector);
      /**
       * @brief  行列の平行移動
       * @param  translate 平行移動ベクトル
       */
      void MulTranslate(const Vector4 translate);
      /**
       * @brief  行列のスケーリング
       * @param  scale 拡大縮小ベクトル
       */
      void MulScaling(const Vector4 scale);
      /**
       * @brief  回転行列(x軸)
       * @param  radian 角度(ラジアン)
       */
      void RotateX(const float radian);
      /**
       * @brief  回転行列(y軸)
       * @param  radian 角度(ラジアン)
       */
      void RotateY(const float radian);
      /**
       * @brief  回転行列(z軸)
       * @param  radian 角度(ラジアン)
       */
      void RotateZ(const float radian);
      /**
       * @brief  回転行列(x軸)の生成
       * @param  angle 回転値(ラジアン)
       * @return 回転行列(x軸)
       */
      static Matrix44 ToRotationX(const float angle);
      /**
       * @brief  回転行列(y軸)の生成
       * @param  angle 回転値(ラジアン)
       * @return 回転行列(y軸)
       */
      static Matrix44 ToRotationY(const float angle);
      /**
       * @brief  回転行列(z軸)の生成
       * @param  angle 回転値(ラジアン)
       * @return 回転行列(z軸)
       */
      static Matrix44 ToRotationZ(const float angle);
      /**
       * @brief  指定した行列の逆行列の取得
       * @param  matrix 行列
       * @return 逆行列
       */
      static Matrix44 Inverse(const Matrix44 matrix);
      /**
       * @brief  指定した行列の値を取得
       * @param  row 行
       * @param  column 列
       * @return 指定した行列の値
       */
      float GetValue(const int row, const int column) const;
      /**
       * @brief  行列同士の乗算
       * @param  rhs 行列(乗数)
       * @return 乗算した行列
       */
      Matrix44 operator*(const Matrix44 rhs) const;
      /**
       * @brief  行列*ベクトルの乗算
       * @param  vector ベクトル(乗数)
       * @return 乗算したベクトル
       */
      Vector4 operator*(const Vector4 vector) const;

    private:
      //!< 行列
      MatrixArray _rowColumn;
    };
  } // namespace Math
} // namespace AppFrame