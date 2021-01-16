#include "Player.h"

void Player::setName(string name) { this->name = name; }
string Player::getName() { return name; }

void Player::setComplexity(int complexity) { this->complexity = complexity; }
int Player::getComplexity() { return complexity; }

void Player::setNumberOfShots(int numberOfShots) { this->numberOfShots += numberOfShots; }
int Player::getNumberOfShots() { return numberOfShots; }

void Player::setNumberOfHits(int numberOfHits) { this->numberOfHits = numberOfHits; }
int Player::getNumberOfHits() { return numberOfHits; }
