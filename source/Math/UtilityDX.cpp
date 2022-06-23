/*****************************************************************//**
 * @file   UtilityDX.cpp
 * @brief  DXライブラリ構造体への相互変換クラス
 * 
 * @author 宮澤耀生
 * @date   June 2022
 *********************************************************************/
#include "UtilityDX.h"
#include "Vector4.h"
#include "Matrix44.h"

namespace AppFrame {
  namespace Math {
    VECTOR UtilityDX::ToVECTOR(const Vector4 vector) {
      return VECTOR(vector.GetX(), vector.GetY(), vector.GetZ());
    }

    Vector4 UtilityDX::ToVector(const VECTOR& vector) {
      return Vector4(vector.x, vector.y, vector.z);
    }

    MATRIX UtilityDX::ToMATRIX(const Matrix44 matrix) {
      MATRIX matrixDX;
      for (auto row = 0; row < AppFrame::Math::MaxRow; ++row) {
        for (auto column = 0; column < AppFrame::Math::MaxColumn; ++column) {
          // 値をコピーする
          matrixDX.m[row][column] = matrix.GetValue(row, column);
        }
      }
      return matrixDX;
    }
  } // namespace Math
} // namespace AppFrame