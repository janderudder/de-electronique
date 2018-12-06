#ifndef NUMBER_PICKER_HPP
#define NUMBER_PICKER_HPP
using time_t = unsigned long;

class NumberPicker
{
  bool mActive = false;


public:
  explicit NumberPicker() {}

  void update(time_t);

};

#endif // NUMBER_PICKER_HPP
