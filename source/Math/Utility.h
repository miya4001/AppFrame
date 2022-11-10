/*****************************************************************//**
 * @file   Utility.h
 * @brief  �Z�p�����̕⏕�@�\�N���X
 * 
 * @author �{�V�s��
 * @date   July 2022
 *********************************************************************/
#pragma once
#include <numbers>

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
    constexpr auto Degree = true;   //!< �f�O���[�t���O
    constexpr auto Radian = false;  //!< ���W�A���t���O
    /**
     * @class  Utility
     * @brief  �Z�p�����̕⏕�@�\�N���X
     */
    class Utility {
    public:
      //!< �~����PI�̒萔
      static constexpr float Pi = static_cast<float>(std::numbers::pi);
      //!< 180�x 
      static constexpr float Degrees180 = 180.0f;
      /**
       * @brief  ��̒l���r���čŏ��l��Ԃ�(int�^)
       * @param  a �la
       * @param  b �lb
       * @return �ŏ��l
       */
      static int Min(const int a, const int b);
      /**
       * @brief  ��̒l���r���čŏ��l��Ԃ�(float�^)
       * @param  a �la
       * @param  b �lb
       * @return �ŏ��l
       */
      static float Min(const float a, const float b);
      /**
       * @brief  ��̒l���r���čő�l��Ԃ�(int�^)
       * @param  a �la
       * @param  b �lb
       * @return �ő�l
       */
      static int Max(const int a, const int b);
      /**
       * @brief  ��̒l���r���čő�l��Ԃ�(float�^)
       * @param  a �la
       * @param  b �lb
       * @return �ő�l
       */
      static float Max(const float a, const float b);
      /**
       * @brief  �N�����v����(int�^)
       * @param  value �Ώےl
       * @param  min �ŏ��l
       * @param  max �ő�l
       * @return �N�����v�����l
       */
      static int Clamp(const int value, const int min, const int max);
      /**
       * @brief  �N�����v����(float�^)
       * @param  value �Ώےl
       * @param  min �ŏ��l
       * @param  max �ő�l
       * @return �N�����v�����l
       */
      static float Clamp(const float value, const float min, const float max);
      /**
       * @brief  �Ώےl�𐳐��ɕϊ�
       * @param  value �Ώےl
       * @return �Ώےl�𐳐��ɕϊ������l
       */
      static float ToPlus(const float value);
      /**
       * @brief  �Ώےl������������
       * @param  value �Ώےl
       * @return true:����
       *         false:����
       */
      static bool IsPositive(const int value);
      /**
       * @brief  �Ώےl���͈͓��Ɏ��܂��Ă��邩����
       * @param  value �Ώےl
       * @param  min �ŏ��l
       * @param  max �ő�l
       * @return true:�͈͓�
       *         false:�͈͊O
       */
      static bool IsRange(const int value, const int min, const int max);
      /**
       * @brief  �J�E���g����
       * @param  count �J�E���g
       * @param  max �J�E���g���
       * @return �J�E���g��1���₵���l
       *         �J�E���g����̏ꍇ0��Ԃ�
       */
      static int IncrementCount(const int count, const int max);
      /**
       * @brief  �f�O���[�l�����W�A���l�ɕϊ�
       * @param  degree �f�O���[�l
       * @return ���W�A���l
       */
      static inline float DegreeToRadian(const float degree) {
        return degree * Pi / Degrees180;
      }
      /**
       * @brief  ���W�A���l���f�O���[�l�ɕϊ�
       * @param  radian ���W�A���l
       * @return �f�O���[�l
       */
      static inline float RadianToDegree(const float radian) {
        return radian * Degrees180 / Pi;
      }
      /**
       * @brief  ��]�x�N�g��(�f�O���[�l)�ъe���������W�A���l�ɕϊ�
       * @param  rotation ��]�x�N�g��(�f�O���[�l)
       * @return �e���������W�A���l�ɕϊ������x�N�g��
       */
      static Vector4 RotationToRadian(const Vector4& rotation);
      /**
       * @brief  ���[���h���W�ϊ�
       * @param  position ���[�J�����W
       * @param  rotation ��]�x�N�g��
       * @param  scale �g�嗦
       * @param  angle ���[�e�[�V�����t���O(true:�f�O���[�l false:���W�A���l)
       * @return ���[���h���W
       */
      static Matrix44 ToWorldMatrix(const Vector4& position, Vector4 rotation, const Vector4& scale, const bool angle);
      /**
       * @brief  �s����g�p�����x�N�g���̕ϊ�
       * @param  vector �ϊ�����x�N�g��
       * @param  matrix �g�p����s��
       * @return �ϊ������x�N�g��
       */
      static Vector4 TransformVector(const Vector4& vector, const Matrix44& matrix);
    };
  } // namespace Math
} // namespace AppFrame