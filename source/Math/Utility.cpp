/*****************************************************************//**
 * @file   Utility.cpp
 * @brief  算術処理の補助機能クラス
 * 
 * @author 宮澤耀生
 * @date   July 2022
 *********************************************************************/
#include "Utility.h"
#include "Vector4.h"
#include "Matrix44.h"

namespace AppFrame {
  namespace Math {
    int Utility::Min(const int a, const int b) {
      return (a < b) ? a : b;
    }

    float Utility::Min(const float a, const float b) {
      return (a < b) ? a : b;
    }

    int Utility::Max(const int a, const int b) {
      return (b < a) ? a : b;
    }

    float Utility::Max(const float a, const float b) {
      return (b < a) ? a : b;
    }

    float Utility::ToPlus(const float value) {
      // 対象が0未満の場合は正数に直した値を返す
      return (value < 0.0f) ? value * -1.0f : value;
    }

    Vector4 Utility::RotationToRadian(const Vector4& rotation) {
      // 各種成分の取得
      auto [x, y, z] = rotation.GetVector3();
      // 各成分をラジアンに変換する
      x = DegreeToRadian(x);
      y = DegreeToRadian(y);
      z = DegreeToRadian(z);
      return Vector4(x, y, z);
    }

    Matrix44 Utility::ToWorldMatrix(const Vector4& position, Vector4 rotation, const Vector4& scale, const bool angle) {
      // rotationがデグリー値の場合はラジアン値に変換する
      if (angle) {
        rotation = RotationToRadian(rotation);
      }
      // 単位行列の取得
      auto worldMatrix = Matrix44::Identity();
      // スケーリング
      worldMatrix.MulScaling(scale);
      // 回転
      worldMatrix.RotateZ(rotation.GetZ());
      worldMatrix.RotateY(rotation.GetY());
      worldMatrix.RotateX(rotation.GetX());
      // 平行移動
      worldMatrix.MulTranslate(position);
      return worldMatrix;
    }
  } // namespace Math
} // namespace AppFrame