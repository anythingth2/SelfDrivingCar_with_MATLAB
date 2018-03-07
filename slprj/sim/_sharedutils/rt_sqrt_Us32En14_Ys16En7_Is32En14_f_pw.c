#include "rtwtypes.h"
#include "multiword_types.h"
#include "rt_sqrt_Us32En14_Ys16En7_Is32En14_f_pw.h"

int16_T rt_sqrt_Us32En14_Ys16En7_Is32En14_f_pw(int32_T u)
{
  int16_T y;
  int16_T tmp01_y;
  int16_T shiftMask;
  int32_T iBit;
  if (u > 0) {
    y = 0;
    shiftMask = 16384;
    for (iBit = 0; iBit < 15; iBit++) {
      tmp01_y = (int16_T)(y | shiftMask);
      if (tmp01_y * tmp01_y <= u) {
        y = tmp01_y;
      }

      shiftMask = (int16_T)((uint32_T)shiftMask >> 1U);
    }
  } else {
    y = 0;
  }

  return y;
}
