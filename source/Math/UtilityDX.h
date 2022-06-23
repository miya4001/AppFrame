/*****************************************************************//**
 * @file   UtilityDX.h
 * @brief  DXライブラリ構造体への相互変換クラス
 * 
 * @author 宮澤耀生
 * @date   June 2022
 *********************************************************************/
#pragma once
#include <DxLib.h>

/**
 * @brief  アプリケーションフレーム
 */
namespace AppFrame {
  /**
   * @brief  算術
   */
  namespace Math {
    class Vector4;
    class Matrix44;
    /**
     * @class  UtilityDX
     * @brief  DXライブラリ構造体への相互変換クラス
     */
    class UtilityDX {
    public:
      /**
       * @brief  Vector4クラスの値をVECTOR構造体に変換
       * @param  vector 変換対象
       * @return VECTOR構造体
       */
      static VECTOR ToVECTOR(const Vector4 vector);
      /**
       * @brief  VECTOR構造体をVector4クラスに変換
       * @param  vector 変換対象
       * @return Vector4クラス
       */
      static Vector4 ToVector(const VECTOR& vector);
      /**
       * @brief  Matrix44クラスをMATRIX構造体に変換
       * @param  matrix 変換対象となるMatrix44クラス
       * @return MATRIX構造体
       */
      static MATRIX ToMATRIX(const Matrix44 matrix);
    };
  } // namespace Math
} // namespace AppFrame