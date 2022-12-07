#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player
{
private:
  /** @param username : nom du joueur */

  string username;

  /** @param numberGame : nombre de partie jouée par le joueur */

  unsigned int numberGame;

  /** @param numberWin : nombre de victoire du joueur  */



  /**
   * @brief Instanciation du temps de réflexion du joueur
   */
  double timeToPlay;


public:
  /**
  @brief Constructeur par defaut de la classe Player
  */

  Player();


  /**
  @brief Destructeur de la classe Piece
  */

  ~Player();

/**
 * @brief Accesseur du temps de jeu restant du joueur
 * 
 * @return Double
 */
  double getTimeToPlay();

/**
 * @brief Mutateur du temps de jeu restant du joueur
 * 
 * @param time valeur de temps choisit pour écraser l'ancienne
 */
  void setTimeToPlay(double time);

};

