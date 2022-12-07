#include <iostream>

#include "Game.h"


using namespace std;


Game::Game(double time)
{
  timeSeconds = timer.convertFromMinutesToSeconds(time); //on convertie son temps de jeu en secondes

  whitePlayer.setTimeToPlay(timeSeconds);
  blackPlayer.setTimeToPlay(timeSeconds);

  displayPlayerTime(true);
  displayPlayerTime(false);
}

Game::~Game()
{


}


void Game::handlePlayerTime(bool white)
{
  if(white)
  {
    double newWhiteDeltaTimePlay = timer.getTime()
                                  - (timeSeconds - whitePlayer.getTimeToPlay())
                                  - (timeSeconds - blackPlayer.getTimeToPlay());

    double newTime = whitePlayer.getTimeToPlay() - newWhiteDeltaTimePlay;//on calcul le temps restant du joueur en faisant la soustraction

    whitePlayer.setTimeToPlay(newTime); //on modifie le temps

    displayPlayerTime(white);
  }
  if(!white)
  {
    double newBlackDeltaTimePlay = timer.getTime()
                                  - (timeSeconds - whitePlayer.getTimeToPlay())
                                  - (timeSeconds - blackPlayer.getTimeToPlay());

    double newTime = blackPlayer.getTimeToPlay() - newBlackDeltaTimePlay;//on calcul le temps restant du joueur en faisant la soustraction

    blackPlayer.setTimeToPlay(newTime); //on modifie le temps

    displayPlayerTime(!white);
  }
}

void Game::switchWhiteToPlay(Configuration & C)
{
  if(C.getWhiteToPlay() == true)
  {
    C.setWhiteToPlay(false);
  }
  else
  {
    C.setWhiteToPlay(true);
  }
}

void Game::displayPlayerTime(bool white) //gère l'affichage des temps des joueurs
{
  if (white)
  {
    cout << "Temps de réflexion du joueur blanc : "
         << floor(whitePlayer.getTimeToPlay() / 60)
         << ":" << ((int)whitePlayer.getTimeToPlay()) % 60 << endl;
  }
  else
  {
    cout << "Temps de réflexion du joueur noir : "
         << floor(blackPlayer.getTimeToPlay() / 60)
         << ":" << ((int)blackPlayer.getTimeToPlay()) % 60 << endl;
  }
}

bool Game::isGameOver(Configuration & C)
{
  if(whitePlayer.getTimeToPlay() <= 0 || C.isKingMate())
  {
    isTimeOver = true;
    cout << "La partie est perdue / Echec et Mat. Temps écoulé. Les noirs ont gagné ! " << endl;

  }
  if(blackPlayer.getTimeToPlay() <= 0 || C.isKingMate())
  {
    isTimeOver = true;
    cout << "La partie est perdue / Echec et Mat. Temps écoulé. Les blancs ont gagné ! " << endl;
  }

  return isTimeOver;
}



Player Game::getPlayer(bool white)
  {
    if(white)
    {
      return whitePlayer;
    }
    else
    {
      return blackPlayer;
    }
  }
