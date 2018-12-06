#ifndef DISPLAY_MODIFIER_HPP
#define DISPLAY_MODIFIER_HPP
#include "SevenSegmentDisplay.hpp"
using time_t = unsigned long;

class DisplayModifier
{
  SevenSegmentDisplay&  mDisplay;
  time_t                mClock      = 0;

public:
  explicit DisplayModifier(SevenSegmentDisplay&);

  void blink(time_t elapsed, time_t period);
};

#endif // DISPLAY_MODIFIER_HPP
