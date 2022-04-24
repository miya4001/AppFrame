/*****************************************************************//**
 * @file   WinMain.cpp
 * @brief  �v���O�����̃G���g���[�|�C���g
 * 
 * @author �{�V�s��
 * @date   April 2022
 *********************************************************************/
#include <DxLib.h>
#include <stdexcept>
#include "Application/ApplicationBase.h"

/**
 * @brief  �v���O�����̃G���g���[�|�C���g
 * @return 0:����I�� -1:�ُ�I��
 */
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
  // �A�v���P�[�V�����̎��Ԃ��擾
  namespace App = AppFrame::Application;
  auto app = App::ApplicationBase::GetApplication();
  // �A�v���P�[�V�����̎��̔���
  if (app == nullptr) {
    return -1; // �A�v���P�[�V�����̐������s���Ă��Ȃ�
  }
#ifdef _DEBUG
  try {
    // �������ɐ��������ꍇ�̂݃Q�[���Ɉڍs
    if (app->Init()) {
      app->Run(); // �Q�[�����[�v
    }
  }
  catch (std::logic_error error) {
    // ��O��catch�����ꍇ�̓v���O�������I������
    // ����������O�����O�ɏo�͂���
    OutputDebugString(error.what());
  }
#else
  // �������ɐ��������ꍇ�̂݃Q�[���Ɉڍs
  if (app->Init()) {
    app->Run(); // �Q�[�����[�v
  }
#endif
  // �A�v���P�[�V�����I��
  app->Terminate();
  return 0;
}