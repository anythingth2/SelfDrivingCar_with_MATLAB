#include "rtwtypes.h"
#include "multiword_types.h"
#include "div_s32s64_floor.h"

int32_T div_s32s64_floor(int64_T numerator, int64_T denominator)
{
  int32_T quotient;
  uint64_T absNumerator;
  uint64_T absDenominator;
  uint64_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0LL) {
    quotient = numerator >= 0LL ? MAX_int32_T : MIN_int32_T;
  } else {
    absNumerator = numerator < 0LL ? ~(uint64_T)numerator + 1ULL : (uint64_T)
      numerator;
    absDenominator = denominator < 0LL ? ~(uint64_T)denominator + 1ULL :
      (uint64_T)denominator;
    quotientNeedsNegation = ((numerator < 0LL) != (denominator < 0LL));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0ULL) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? (int32_T)-(int64_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}
