/*****************************************************************//**
 * @file   DivGraphData.cpp
 * @brief  ŠæîņNX
 * 
 * @author {āVsķ
 * @date   October 2022
 *********************************************************************/
#include "DivGraphData.h"

namespace AppFrame {
  namespace Graphic {
    DivGraphData::DivGraphData(const std::string_view path, const int allNumber, const int xNumber, const int yNumber, const int xSize, const int ySize) {
      _filePath = path;
      _allNumber = allNumber;
      _xNumber = xNumber;
      _yNumber = yNumber;
      _xSize = xSize;
      _ySize = ySize;
    }
  } // namespace Graphic
} // namespace AppFrame