#include "Timer.h"

Timer::Timer()
{
  reset();
}

Timer::~Timer()
{
}

void Timer::reset()
{
  time = std::chrono::system_clock::now();
}

double Timer::getTime() const // renvoie le temps  écoulé depuis le lancement du programme
{
  std::chrono::duration<double, std::milli> diff = std::chrono::system_clock::now() - time;
  return floor(diff.count() / 1000); // returns the count of ticks in seconds
}

double Timer::convertFromMinutesToSeconds(double minutes)
{
  double seconds = minutes * 60;
  return seconds;
}
