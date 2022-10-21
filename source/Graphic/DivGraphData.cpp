/*****************************************************************//**
 * @file   DivGraphData.cpp
 * @brief  �����摜���N���X
 * 
 * @author �{�V�s��
 * @date   October 2022
 *********************************************************************/
#include "DivGraphData.h"

namespace AppFrame {
  namespace Graphic {
    DivGraphData::DivGraphData(const std::string_view path, const int xNumber, const int yNumber, const int allNumber, const int xSize, const int ySize) {
      _filePath = path;
      _xNumber = xNumber;
      _yNumber = yNumber;
      _allNumber = allNumber;
      _xSize = xSize;
      _ySize = ySize;
    }
  } // namespace Graphic
} // namespace AppFrame