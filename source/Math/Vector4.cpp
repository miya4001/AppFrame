/*****************************************************************//**
 * @file   Vector4.cpp
 * @brief  四次元ベクトルクラス
 * 
 * @author 宮澤耀生
 * @date   May 2022
 *********************************************************************/
#include "Vector4.h"
#include <cmath>

namespace AppFrame {
  namespace Math {
    Vector4::Vector4() {
      // 空ベクトル
      Zero();
    }

    Vector4::Vector4(const float x, const float y) {
      // 二次元ベクトル
      _x = x;
      _y = y;
      _z = 0.0f;
      _w = 0.0f;
    }

    Vector4::Vector4(const float x, const float y, const float z, const float w) {
      // 四次元ベクトル
      _x = x;
      _y = y;
      _z = z;
      _w = w;
    }

    void Vector4::Zero() {
      // 各成分を0にする
      Fill(0.0f);
    }

    void Vector4::Add(const Vector4 vector) {
      _x += vector.GetX();
      _y += vector.GetY();
      _z += vector.GetZ();
    }

    void Vector4::Sub(const Vector4 vector) {
      _x -= vector.GetX();
      _y -= vector.GetY();
      _z -= vector.GetZ();
    }

    void Vector4::Scale(const Vector4 vector) {
      _x *= vector.GetX();
      _y *= vector.GetY();
      _z *= vector.GetZ();
    }

    void Vector4::Set(const Vector4 vector) {
      _x = vector.GetX();
      _y = vector.GetY();
      _z = vector.GetZ();
      _w = vector.GetW();
    }

    void Vector4::Set(const float x, const float y, const float z) {
      _x = x;
      _y = y;
      _z = z;
    }

    void Vector4::Fill(const float value) {
      _x = value;
      _y = value;
      _z = value;
    }

    float Vector4::Length() const {
      return std::sqrt(_x * _x + _y * _y + _z * _z);
    }

    float Vector4::Length(const Vector4& vector) {
      return vector.Length();
    }

    float Vector4::Length2D() const {
      return std::sqrt(_x * _x + _y * _y);
    }

    float Vector4::LengthSquared() const {
      return _x * _x + _y * _y + _z * _z;
    }

    float Vector4::LengthSquared(const Vector4& vector) {
      return vector.LengthSquared();
    }

    float Vector4::LengthSquared2D() const {
      return _x * _x + _y * _y;
    }

    void Vector4::Normalize() {
      // 全ての値が0の場合ゼロベクトル化
      if (LengthSquared() == 0.0f) {
        Zero();
        return;
      }
      // ベクトルの正規化
      float length = Length();
      _x /= length;
      _y /= length;
      _z /= length;
    }

    Vector4 Vector4::Normalize(const Vector4& vector) {
      // 元から長さが0の場合空ベクトルを返す
      if (IsZero(vector)) {
        return Vector4();
      }
      // 単位ベクトルを返す
      float length = vector.Length();
      float x = vector.GetX() / length;
      float y = vector.GetY() / length;
      float z = vector.GetZ() / length;
      return Vector4(x, y, z);
    }

    float Vector4::Dot(const Vector4& vector) const {
      return _x * vector.GetX() + _y * vector.GetY() + _z * vector.GetZ();
    }

    float Vector4::Dot(const Vector4& left, const Vector4& right) {
      return right.Dot(left);
    }

    float Vector4::Dot2D(const Vector4& vector) const {
      return _x * vector.GetX() + _y * vector.GetY();
    }

    Vector4 Vector4::Cross(const Vector4& vector) const {
      float x = _y * vector.GetZ() - _z * vector.GetY();
      float y = _z * vector.GetX() - _x * vector.GetZ();
      float z = _x * vector.GetY() - _y * vector.GetX();
      return Vector4(x, y, z);
    }

    Vector4 Vector4::Cross(const Vector4& left, const Vector4& right) {
      return left.Cross(right);
    }

    Vector4 Vector4::Direction(const Vector4& vector) const {
      return vector - *this;
    }

    bool Vector4::IsZero(const Vector4& vector) {
      return vector.LengthSquared() == 0.0f;
    }

    Vector4 Vector4::operator+(const Vector4& vector) const {
      auto [x, y, z] = vector.GetVector3();
      return Vector4(_x + x, _y + y, _z + z);
    }

    Vector4 Vector4::operator-(const Vector4& vector) const {
      auto [x, y, z] = vector.GetVector3();
      return Vector4(_x - x, _y - y, _z - z);
    }

    Vector4 Vector4::operator*(const float scalar) const {
      return Vector4(_x * scalar, _y * scalar, _z * scalar);
    }

    Vector4 Vector4::operator/(const float scalar) const {
      return Vector4(_x / scalar, _y / scalar, _z / scalar);
    }
  } // namespace Math
} // namespace AppFrame