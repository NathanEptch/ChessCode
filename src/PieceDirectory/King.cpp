#include <iostream>
#include <vector>
#include <cmath>

#include "../Piece.h"
#include "King.h"

using namespace std;

King::King(bool white) : Piece(10, "R", white)
{
}

bool King::isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                       const int posXFinal, const int posYFinal) const
{
  // Verifie que la case de depart comprends bien une Piece sinon renvoie false
  if (C.board(posXInit, posYInit) == nullptr)
  {
    return false;
  }
  // Verifie si le deplacement demandé est un roque si c'est le cas il renvoie true
  if (isMoveCastle(C, posXInit, posYInit, posXFinal, posYFinal))
  {
    return true;
  }
  // Verifie si la case d'arrivé contient une Piece puis verifie si elle est de la meme couleur que celle de depart et renvoie false si c'est le cas
  if ((C.board(posXFinal, posYFinal) != nullptr) && (C.board(posXInit, posYInit)) != nullptr)
  {
    if (((C.board(posXFinal, posYFinal))->getIsWhite()) == ((C.board(posXInit, posYInit))->getIsWhite()))
    {
      return false;
    }
  }
  // Verifie si le roi ne bouge pas de plus d'une case en verticale et/ou horizontal renvoie false si cest le cas
  if ((abs(posXInit - posXFinal) > 1) || (abs(posYInit - posYFinal) > 1))
  {
    return false;
  }
  // Renvoie true si tout les tests on été passé sans rien retourné
  return true;
}
