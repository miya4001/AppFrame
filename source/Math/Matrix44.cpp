/*****************************************************************//**
 * @file   Matrix44.cpp
 * @brief  4*4行列クラス
 * 
 * @author 宮澤耀生
 * @date   June 2022
 *********************************************************************/
#include "Matrix44.h"
#include <cmath>
#include "Vector4.h"

namespace AppFrame {
  namespace Math {
    Matrix44::Matrix44() {
      Reset(_rowColumn);
    }

    Matrix44::Matrix44(const MatrixArray values) {
      _rowColumn = values;
    }

    void Matrix44::Reset(MatrixArray& matrix) {
      for (auto&& values : matrix) {
        values.fill(0.0f);
      }
    }

    Matrix44 Matrix44::Identity() {
      MatrixArray identity;
      Reset(identity);
      // 単位行列の生成
      for (auto i = 0; i < MaxRow; ++i) {
        identity[i][i] = 1.0f;
      }
      return Matrix44(identity);
    }

    Matrix44 Matrix44::Identity(const Matrix44& matrix) {
      auto m = matrix._rowColumn;
      // 単位行列の生成
      for (auto i = 0; i < MaxRow; ++i) {
        m[i][i] = 1.0f;
      }
      return Matrix44(m);
    }

    Matrix44 Matrix44::Translate(const float x, const float y, const float z) {
      auto translate = Identity();
      // 平行移動行列の生成
      translate._rowColumn[0][3] = x;
      translate._rowColumn[1][3] = y;
      translate._rowColumn[2][3] = z;
      return translate;
    }

    Matrix44 Matrix44::Translate(const Vector4& vector) {
      auto [x, y, z] = vector.GetVector3();
      return Translate(x, y, z);
    }

    void Matrix44::MulTranslate(const Vector4 translate) {
      _rowColumn[3][0] += translate.GetX();
      _rowColumn[3][1] += translate.GetY();
      _rowColumn[3][2] += translate.GetZ();
    }

    void Matrix44::MulScaling(const Vector4 scale) {
      _rowColumn[0][0] *= scale.GetX();
      _rowColumn[1][1] *= scale.GetY();
      _rowColumn[2][2] *= scale.GetZ();
    }

    void Matrix44::RotateX(const float radian) {
      auto rotateX = ToRotationX(radian);
      *this = *this * rotateX;
    }

    void Matrix44::RotateY(const float radian) {
      auto rotateY = ToRotationY(radian);
      *this = *this * rotateY;
    }

    void Matrix44::RotateZ(const float radian) {
      auto rotateZ = ToRotationZ(radian);
      *this = *this * rotateZ;
    }

    Matrix44 Matrix44::ToRotationX(const float angle) {
      auto matrix = Identity();
      // 回転行列(x軸)の生成
      float cos = std::cos(angle);
      float sin = std::sin(angle);
      matrix._rowColumn[1][1] = cos;
      matrix._rowColumn[1][2] = sin;
      matrix._rowColumn[2][1] = -sin;
      matrix._rowColumn[2][2] = cos;
      return matrix;
    }

    Matrix44 Matrix44::ToRotationY(const float angle) {
      auto matrix = Identity();
      // 回転行列(y軸)の生成
      auto cos = std::cos(angle);
      auto sin = std::sin(angle);
      matrix._rowColumn[0][0] = cos;
      matrix._rowColumn[0][2] = sin;
      matrix._rowColumn[2][0] = -sin;
      matrix._rowColumn[2][2] = cos;
      return matrix;
    }

    Matrix44 Matrix44::ToRotationZ(const float angle) {
      auto matrix = Identity();
      // 回転行列(z軸)の生成
      auto cos = std::cos(angle);
      auto sin = std::sin(angle);
      matrix._rowColumn[0][0] = cos;
      matrix._rowColumn[0][1] = -sin;
      matrix._rowColumn[1][0] = sin;
      matrix._rowColumn[1][1] = cos;
      return matrix;
    }

    Matrix44 Matrix44::Inverse(const Matrix44 matrix) {
      auto inverse = Identity();
      auto rowColumn = matrix._rowColumn;
      // 掃き出し法による逆行列の算出
      for (auto i = 0; i < MaxColumn; ++i) {
        auto dot = 1.0f / matrix._rowColumn[i][i];
        for (auto j = 0; j < MaxRow; ++j) {
          rowColumn[i][j] *= dot;
          inverse._rowColumn[i][j] *= dot;
        }
        for (auto j = 0; j < MaxRow; ++j) {
          if (i == j) {
            continue;
          }
          dot = rowColumn[j][i];
          for (auto k = 0; k < MaxRow; ++k) {
            rowColumn[j][k] -= rowColumn[i][k] * dot;
            inverse._rowColumn[j][k] -= inverse._rowColumn[i][k] * dot;
          }
        }
      }
      return inverse;
    }

    float Matrix44::GetValue(const int row, const int column) const {
      return _rowColumn[row][column];
    }

    Matrix44 Matrix44::operator*(const Matrix44 rhs) const {
      MatrixArray matrix;
      for (auto row = 0; row < MaxRow; ++row) {
        for (auto column = 0; column < MaxColumn; ++column) {
          float value = 0.0f;
          for (auto m = 0; m < 4; ++m) {
            value += _rowColumn[row][m] * rhs.GetValue(m, column);
          }
          matrix[row][column] = value;
        }
      }
      return Matrix44(matrix);
    }

    Vector4 Matrix44::operator*(const Vector4 vector) const {
      auto [x, y, z, w] = vector.GetVector4();
      // 処理用に配列を生成
      std::array<float, MaxRow> vector4 = { x, y, z, w };
      auto r = _rowColumn;
      for (auto i = 0; i < MaxRow; ++i) {
        vector4[i] = r[i][0] * x + r[i][1] * y + r[i][2] * z + r[i][3] * w;
      }
      return Vector4(vector4.at(0), vector4.at(1), vector4.at(2), vector4.at(3));
    }
  } // namespace Math
} // namespace AppFrame