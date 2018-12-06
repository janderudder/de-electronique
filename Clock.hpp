#ifndef CLOCK_HPP
#define CLOCK_HPP
using time_t = decltype(millis());


class Clock
{
  time_t mTimer       = 0;
  time_t mProgramTime = 0;

public:
  const Clock& update(time_t programTime) {
    mTimer = programTime - mProgramTime;
    mProgramTime = programTime;
    return *this;
  }

  time_t getTime() const {
    return mTimer;
  }
};

#endif // CLOCK_HPP
