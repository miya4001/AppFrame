/*****************************************************************//**
 * @file   Vector4.h
 * @brief  �l�����x�N�g���N���X
 * 
 * @author �{�V�s��
 * @date   May 2022
 *********************************************************************/
#pragma once
#include <tuple>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  �Z�p
   */
  namespace Math {
    /**
     * @class  Vector4
     * @brief  �l�����x�N�g���N���X
     */
    class Vector4 {
    public:
      /**
       * @brief  ��x�N�g���̐���
       */
      Vector4();
      /**
       * @brief  �񎟌��x�N�g���̐���
       * @param  x x����
       * @param  y y����
       */
      Vector4(const float x, const float y);
      /**
       * @brief  �x�N�g���̐���
       * @param  x x����
       * @param  y y����
       * @param  z z����
       * @param  w w����(�f�t�H���g��1.0)
       */
      Vector4(const float x, const float y, const float z, const float w = 1.0);
      /**
       * @brief  �[���x�N�g����
       */
      void Zero();
      /**
       * @brief  �x�N�g�����m�̉��Z
       * @param  vector �x�N�g��(����)
       */
      void Add(const Vector4 vector);
      /**
       * @brief  �x�N�g�����m�̌��Z
       * @param  vector �x�N�g��(����)
       */
      void Sub(const Vector4 vector);
      /**
       * @brief  �x�N�g�����m�̊e�����̏�Z
       * @param  vector �x�N�g��(�搔)
       */
      void Scale(const Vector4 vector);
      /**
       * @brief  �x�N�g���̐ݒ�
       * @param  vector �w�肷��x�N�g��
       */
      void Set(const Vector4 vector);
      /**
       * @brief  �w�肵���l���x�N�g���ɐݒ�
       * @param  x x�����Ɏw�肷��l
       * @param  y y�����Ɏw�肷��l
       * @param  z z�����Ɏw�肷��l
       */
      void Set(const float x, const float y, const float z);
      /**
       * @brief  �w�肵���l��xyz�����ɐݒ�
       * @param  value �w�肷��l
       */
      void Fill(const float value);
      /**
       * @brief  �w�肵���l��x�����ɐݒ�
       * @param  x x�����Ɏw�肷��l
       */
      inline void SetX(const float x) {
        _x = x;
      }
      /**
       * @brief  �w�肵���l��y�����ɐݒ�
       * @param  y y�����Ɏw�肷��l
       */
      inline void SetY(const float y) {
        _y = y;
      }
      /**
       * @brief  �w�肵���l��z�����ɐݒ�
       * @param  z z�����Ɏw�肷��l
       */
      inline void SetZ(const float z) {
        _z = z;
      }
      /**
       * @brief  2�����x�N�g���̎擾
       * @return x����, y����
       */
      inline const std::pair<float, float> GetVector2() const {
        return { _x, _y };
      }
      /**
       * @brief  3�����x�N�g���̎擾
       * @return x����, y����, z����
       */
      inline const std::tuple<float, float, float> GetVector3() const {
        return { _x, _y, _z };
      }
      /**
       * @brief  4�����x�N�g���̎擾
       * @return x����, y����, z����, w����
       */
      inline const std::tuple<float, float, float, float> GetVector4() const {
        return { _x, _y, _z, _w };
      }
      /**
       * @return x�����̎擾
       * @brief  x����
       */
      inline const float GetX() const {
        return _x;
      }
      /**
       * @brief  y�����̎擾
       * @return y����
       */
      inline const float GetY() const {
        return _y;
      }
      /**
       * @brief  z�����̎擾
       * @return z����
       */
      inline const float GetZ() const {
        return _z;
      }
      /**
       * @brief  w�����̎擾
       * @return w����
       */
      inline const float GetW() const {
        return _w;
      }
      /**
       * @brief  �x�N�g���̒����̎擾
       * @return �x�N�g���̒���
       */
      float Length() const;
      /**
       * @brief  �w�肵���x�N�g���̒����̎擾
       * @param  vector �w�肷��x�N�g��
       * @return �w�肵���x�N�g���̒���
       */
      static float Length(const Vector4& vector);
      /**
       * @brief  �x�N�g���̒����̎擾(2����)
       * @return �x�N�g���̒���(2����)
       */
      float Length2D() const;
      /**
       * @brief  �x�N�g���̒����̓��̎擾
       * @return �x�N�g���̒����̓��
       */
      float LengthSquared() const;
      /**
       * @brief  �w�肵���x�N�g���̒����̓��̎擾
       * @param  vector �w�肷��x�N�g��
       * @return �w�肵���x�N�g���̒����̓��
       */
      static float LengthSquared(const Vector4& vector);
      /**
       * @brief  �x�N�g���̒����̓��̎擾(2����)
       * @return �x�N�g���̒����̓��(2����)
       */
      float LengthSquared2D() const;
      /**
       * @brief  �x�N�g���̐��K��
       */
      void Normalize();
      /**
       * @brief  �P�ʃx�N�g���̎擾
       * @param  vector �x�N�g��
       * @return �P�ʃx�N�g��
       */
      static Vector4 Normalize(const Vector4& vector);
      /**
       * @brief  �x�N�g���̓��ς̎擾
       * @param  vector �x�N�g��
       * @return �x�N�g���̓���
       */
      float Dot(const Vector4& vector) const;
      /**
       * @brief  �w�肵���x�N�g���̓��ς̎擾
       * @param  left �x�N�g��(����)
       * @param  right �x�N�g��(�E��)
       * @return �w�肵���x�N�g���̓���
       */
      static float Dot(const Vector4& left, const Vector4& right);
      /**
       * @brief  �x�N�g���̓��ς̎擾(2����)
       * @param  vector �x�N�g��(2����)
       * @return �x�N�g���̓���(2����)
       */
      float Dot2D(const Vector4& vector) const;
      /**
       * @brief  �x�N�g���̊O�ς̎擾
       * @param  vector �x�N�g��
       * @return �x�N�g���̊O��
       */
      Vector4 Cross(const Vector4& vector) const;
      /**
       * @brief  �w�肵���x�N�g���̊O�ς̎擾
       * @param  left �x�N�g��(����)
       * @param  right �x�N�g��(�E��)
       * @return �w�肵���x�N�g���̊O��
       */
      static Vector4 Cross(const Vector4& left, const Vector4& right);
      /**
       * @brief  �Ώۃx�N�g���֌������x�N�g���̎擾
       * @param  vector �Ώۃx�N�g��
       * @return �����x�N�g��
       */
      Vector4 Direction(const Vector4& vector) const;
      /**
       * @brief  �x�N�g�����[�����̔���
       * @param  vector �x�N�g��
       * @return true:�[��
       *         false:�[���ł͂Ȃ�
       */
      static bool IsZero(const Vector4& vector);
      /**
       * @brief  �x�N�g�����m�̉��Z
       * @param  vector �x�N�g��(����)
       * @return ���Z�����x�N�g��
       */
      Vector4 operator+(const Vector4& vector) const;
      /**
       * @brief  �x�N�g�����m�̌��Z
       * @param  vector �x�N�g��(����)
       * @return ���Z�����x�N�g��
       */
      Vector4 operator-(const Vector4& vector) const;
      /**
       * @brief  �x�N�g���̃X�J���[�{
       * @param  scalar �X�J���[�l
       * @return �X�J���[�{�����x�N�g��
       */
      Vector4 operator*(const float scalar) const;
      /**
       * @brief  �x�N�g���̃X�J���[��
       * @param  scalar �X�J���[�l
       * @return �X�J���[�������x�N�g��
       */
      Vector4 operator/(const float scalar) const;

    private:
      float _x;  //!< x����
      float _y;  //!< y����
      float _z;  //!< z����
      float _w;  //!< w����
    };
  } // namespace Math
} // namespace AppFrame