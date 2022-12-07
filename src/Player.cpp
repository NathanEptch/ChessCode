#include "Player.h"

using namespace std;

Player::Player()
{}


Player::~Player()
{
}

double Player::getTimeToPlay()
{
  return timeToPlay;
}


void Player::setTimeToPlay(double time)
{
  timeToPlay = time;
}