#pragma once

#include "Player.h"
#include "Configuration.h"
#include "Timer.h"

class Game
{
private:
  /**
   * @brief Variable booléenne permettant de définir si oui ou  non la partie est terminée.
   *
   */
  bool isTimeOver = false;

  /**
   * @brief Instanciation du player Blanc
   *
   */

  Player whitePlayer;

  /**
   * @brief Instanciation du player Noir
   *
   */

  Player blackPlayer;

  /**
   * @brief Instanciation d'un timer
   *
   */
  Timer timer;

  /**
   * @brief instanciation du temps en secondes de la partie,
   * il représente la conversion du temps en minutes choisi pas l'utilisateur en temps en secondes
   */

  double timeSeconds;

public:
  /**
   * @brief Constructeur de game, crée une game avec un temps de jeu (passé en paramètre)
   *
   * @param time Temps de réflexion pour chacun des joueurs
   */

  Game(double time);

  /**
   * @brief Destructeur de game
   *
   */
  ~Game();

  /**
   * @brief Accesseur d'un player
   *
   * @param white Défini le joueur que l'on veut récupérer
   * @return Player
   */
  Player getPlayer(bool white);

  /**
   * @brief Permet de faire varier diminuer les temps des joueurs et de les affichers
   *
   * @param white Permet de définir sur quel joueur on agit
   */
  void handlePlayerTime(bool white);

  /**
   * @brief Procédure permettant de changer le trait (définissant qui doit jouer) à chaque coup
   *
   * @param C Configuration en cours
   */
  void switchWhiteToPlay(Configuration &C);

  /**
   * @brief Permet d'afficher de manière textuelle les valeurs des temps des joueurs
   *
   * @param white Défini le joueur pour lequel on affiche le temps
   */
  void displayPlayerTime(bool white);

  /**
   * @brief Fonction renseignant si la partie est terminée ou non
   *
   * @param C configuration actuelle
   * @return true si la partie est terminée
   * @return false sinon
   */
  bool isGameOver(Configuration &C);
};
