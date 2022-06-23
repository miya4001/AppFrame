/*****************************************************************//**
 * @file   Matrix44.h
 * @brief  4*4�s��N���X
 * 
 * @author �{�V�s��
 * @date   June 2022
 *********************************************************************/
#pragma once
#include <array>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  �Z�p
   */
  namespace Math {
    class Vector4;
    constexpr int MaxRow = 4;     //!< �s�̏��
    constexpr int MaxColumn = 4;  //!< ��̏��
    /**
     * @class  Matrix44
     * @brief  4*4�s��N���X
     */
    class Matrix44 {
    private:
      // float�^��4*4�s���\��2�����z��
      using MatrixArray = std::array<std::array<float, MaxColumn>, MaxRow>;

    public:
      /**
       * @brief  ��̍s��𐶐�
       */
      Matrix44();
      /**
       * @brief  �s��R�s�[
       * @param  values �s��
       */
      Matrix44(const MatrixArray values);
      /**
       * @brief  �s��̍폜
       */
      ~Matrix44() = default;
      /**
       * @brief  �s��̏�����
       * @param  matrix �s��
       */
      static void Reset(MatrixArray& matrix);
      /**
       * @brief  �P�ʍs��
       * @return �P�ʍs��
       */
      static Matrix44 Identity();
      /**
       * @brief  �w�肵���s��̒P�ʍs��̎擾
       * @param  matrix �s��
       * @return �P�ʍs��
       */
      static Matrix44 Identity(const Matrix44& matrix);
      /**
       * @brief  ���s�ړ��s��̎擾
       * @param  x x����
       * @param  y y����
       * @param  z z����
       * @return ���s�ړ��s��
       */
      static Matrix44 Translate(const float x, const float y, const float z);
      /**
       * @brief  �x�N�g���𕽍s�ړ��s��ɕϊ�
       * @param  vector �x�N�g��
       * @return ���s�ړ��s��
       */
      static Matrix44 Translate(const Vector4& vector);
      /**
       * @brief  �s��̕��s�ړ�
       * @param  translate ���s�ړ��x�N�g��
       */
      void MulTranslate(const Vector4 translate);
      /**
       * @brief  �s��̃X�P�[�����O
       * @param  scale �g��k���x�N�g��
       */
      void MulScaling(const Vector4 scale);
      /**
       * @brief  ��]�s��(x��)
       * @param  radian �p�x(���W�A��)
       */
      void RotateX(const float radian);
      /**
       * @brief  ��]�s��(y��)
       * @param  radian �p�x(���W�A��)
       */
      void RotateY(const float radian);
      /**
       * @brief  ��]�s��(z��)
       * @param  radian �p�x(���W�A��)
       */
      void RotateZ(const float radian);
      /**
       * @brief  ��]�s��(x��)�̐���
       * @param  angle ��]�l(���W�A��)
       * @return ��]�s��(x��)
       */
      static Matrix44 ToRotationX(const float angle);
      /**
       * @brief  ��]�s��(y��)�̐���
       * @param  angle ��]�l(���W�A��)
       * @return ��]�s��(y��)
       */
      static Matrix44 ToRotationY(const float angle);
      /**
       * @brief  ��]�s��(z��)�̐���
       * @param  angle ��]�l(���W�A��)
       * @return ��]�s��(z��)
       */
      static Matrix44 ToRotationZ(const float angle);
      /**
       * @brief  �w�肵���s��̋t�s��̎擾
       * @param  matrix �s��
       * @return �t�s��
       */
      static Matrix44 Inverse(const Matrix44 matrix);
      /**
       * @brief  �w�肵���s��̒l���擾
       * @param  row �s
       * @param  column ��
       * @return �w�肵���s��̒l
       */
      float GetValue(const int row, const int column) const;
      /**
       * @brief  �s�񓯎m�̏�Z
       * @param  rhs �s��(�搔)
       * @return ��Z�����s��
       */
      Matrix44 operator*(const Matrix44 rhs) const;
      /**
       * @brief  �s��*�x�N�g���̏�Z
       * @param  vector �x�N�g��(�搔)
       * @return ��Z�����x�N�g��
       */
      Vector4 operator*(const Vector4 vector) const;

    private:
      //!< �s��
      MatrixArray _rowColumn;
    };
  } // namespace Math
} // namespace AppFrame