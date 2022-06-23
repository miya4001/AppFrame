/*****************************************************************//**
 * @file   UtilityDX.h
 * @brief  DX���C�u�����\���̂ւ̑��ݕϊ��N���X
 * 
 * @author �{�V�s��
 * @date   June 2022
 *********************************************************************/
#pragma once
#include <DxLib.h>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  �Z�p
   */
  namespace Math {
    class Vector4;
    class Matrix44;
    /**
     * @class  UtilityDX
     * @brief  DX���C�u�����\���̂ւ̑��ݕϊ��N���X
     */
    class UtilityDX {
    public:
      /**
       * @brief  Vector4�N���X�̒l��VECTOR�\���̂ɕϊ�
       * @param  vector �ϊ��Ώ�
       * @return VECTOR�\����
       */
      static VECTOR ToVECTOR(const Vector4 vector);
      /**
       * @brief  VECTOR�\���̂�Vector4�N���X�ɕϊ�
       * @param  vector �ϊ��Ώ�
       * @return Vector4�N���X
       */
      static Vector4 ToVector(const VECTOR& vector);
      /**
       * @brief  Matrix44�N���X��MATRIX�\���̂ɕϊ�
       * @param  matrix �ϊ��ΏۂƂȂ�Matrix44�N���X
       * @return MATRIX�\����
       */
      static MATRIX ToMATRIX(const Matrix44 matrix);
    };
  } // namespace Math
} // namespace AppFrame