#include <iostream>
#include <vector>

#include "../Piece.h"
#include "Queen.h"

using namespace std;

Queen::Queen(bool white) : Piece(7, "D", white)
{}

// Fonction isMoveLegal testée et validée
bool Queen::isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                        const int posXFinal, const int posYFinal) const
{
  // Prends un booleen qui indique si le deplacement est un mouvement autorisé en diagonal
  bool diagonal = moveDiagonal(C, posXInit, posYInit, posXFinal, posYFinal);
  // Prends un booleen qui indique si le deplacement est un mouvement autorisé en vertical
  bool vertical = moveVertical(C, posXInit, posYInit, posXFinal, posYFinal);
  // Renvoie true si le deplacement est soit diagonal soit vertical
  if (diagonal || vertical)
  {
    return true;
  }
  // Renvoie false si le deplacement n'est ni diagonal ni vertical
  else
  {
    return false;
  }
}
