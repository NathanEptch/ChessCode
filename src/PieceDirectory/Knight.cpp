#include <iostream>
#include <vector>
#include <cmath>

#include "../Piece.h"
#include "Knight.h"

using namespace std;

Knight::Knight(bool white) : Piece(3, "C", white)
{
}

// Fonction isMoveLegal testée et validée
bool Knight::isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                         const int posXFinal, const int posYFinal) const
{
  // Verifie que la case de depart comprenne bien un Piece sinon renvoie false
  if (C.board(posXInit, posYInit) == nullptr)
  {
    return false;
  }
  // Verifie si la case d'arrivé contient une Piece puis verifie si elle est de la meme couleur que celle de depart et renvoie false si c'est le cas
  if ((C.board(posXFinal, posYFinal) != nullptr) && (C.board(posXInit, posYInit)) != nullptr)
  {
    if (((C.board(posXFinal, posYFinal))->getIsWhite()) == ((C.board(posXInit, posYInit))->getIsWhite()))
    {
      return false;
    }
  }
  // Verifei si le deplacement s'effectue bien de 2 en horizontal et de 1 en verticale ou inversement et renvoie false si ce n'est pas le cas
  if (((abs(posXInit - posXFinal) != 2) || (abs(posYInit - posYFinal) != 1)) &&
      ((abs(posXInit - posXFinal) != 1) || (abs(posYInit - posYFinal) != 2)))
  {
    return false;
  }
  // Renvoie true si tout les tests on été passé sans rien retourné
  return true;
}
