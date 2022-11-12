/*****************************************************************//**
 * @file   appframe.h
 * @brief  フレームワークのライブラリ指定
 * 
 * @author 宮澤耀生
 * @date   April 2022
 *********************************************************************/
#pragma once
#pragma comment(lib, "AppFrame.lib")

#include "Application/ApplicationBase.h"
#include "Input/InputManager.h"
#include "Input/InputXJoypad.h"
#include "Input/InputKeyboard.h"
#include "Mode/ModeBase.h"
#include "Mode/ModeServer.h"
#include "Graphic/DivGraphData.h"
#include "Graphic/GraphicLoadServer.h"
#include "Model/ModelLoadServer.h"
#include "Effect/EffectLoadServer.h"
#include "Sound/SoundLoadServer.h"
#include "Sound/SoundComponent.h"
#include "Math/Vector4.h"
#include "Math/Matrix44.h"
#include "Math/Utility.h"
#include "Math/UtilityDX.h"