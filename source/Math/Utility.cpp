/*****************************************************************//**
 * @file   Utility.cpp
 * @brief  �Z�p�����̕⏕�@�\�N���X
 * 
 * @author �{�V�s��
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
      // �Ώۂ�0�����̏ꍇ�͐����ɒ������l��Ԃ�
      return (value < 0.0f) ? value * -1.0f : value;
    }

    Vector4 Utility::RotationToRadian(const Vector4& rotation) {
      // �e�퐬���̎擾
      auto [x, y, z] = rotation.GetVector3();
      // �e���������W�A���ɕϊ�����
      x = DegreeToRadian(x);
      y = DegreeToRadian(y);
      z = DegreeToRadian(z);
      return Vector4(x, y, z);
    }

    Matrix44 Utility::ToWorldMatrix(const Vector4& position, Vector4 rotation, const Vector4& scale, const bool angle) {
      // rotation���f�O���[�l�̏ꍇ�̓��W�A���l�ɕϊ�����
      if (angle) {
        rotation = RotationToRadian(rotation);
      }
      // �P�ʍs��̎擾
      auto worldMatrix = Matrix44::Identity();
      // �X�P�[�����O
      worldMatrix.MulScaling(scale);
      // ��]
      worldMatrix.RotateZ(rotation.GetZ());
      worldMatrix.RotateY(rotation.GetY());
      worldMatrix.RotateX(rotation.GetX());
      // ���s�ړ�
      worldMatrix.MulTranslate(position);
      return worldMatrix;
    }
  } // namespace Math
} // namespace AppFrame