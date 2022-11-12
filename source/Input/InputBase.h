/*****************************************************************//**
 * @file   InputBase.h
 * @brief  ���͏����̊��N���X
 * 
 * @author �{�V�s��
 * @date   November 2022
 *********************************************************************/
#pragma once
#include <DxLib.h>
#include <array>

/**
 * @brief  �A�v���P�[�V�����t���[��
 */
namespace AppFrame {
  /**
   * @brief  ����
   */
  namespace Input {
    constexpr int InputError = -1;        //!< �G���[
    constexpr bool InputPress = true;     //!< �������
    constexpr bool InputTrigger = false;  //!< �g���K���
    /**
     * @class  InputBase
     * @brief  ���͏����̊��N���X
     */
    class InputBase {
    public:
      /**
       * @brief  �R���X�g���N�^
       */
      InputBase();
      /**
       * @brief  �f�X�g���N�^
       */
      virtual ~InputBase();
      /**
       * @brief  ������
       * @return true:����������
       *         false:���������s
       */
      virtual bool Init();
      /**
       * @brief  �X�V
       */
      virtual void Process();
    };
  } // namespace Input
} // namespace AppFrame