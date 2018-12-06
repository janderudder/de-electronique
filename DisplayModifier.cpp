#include "DisplayModifier.hpp"


DisplayModifier::DisplayModifier(SevenSegmentDisplay& display)
  : mDisplay { display }
{
  
}



void DisplayModifier::blink(time_t ft, time_t period)
{
  static bool blinkState = true;
  mClock += ft;
  
  if (mClock > period) {
    if (blinkState) {
      mDisplay.save();
      mDisplay.clear(); 
    } else {
      mDisplay.recall();
    }
    blinkState = !blinkState;
    mClock = 0;
  }
  
}
