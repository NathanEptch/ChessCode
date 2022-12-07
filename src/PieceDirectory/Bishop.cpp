#include <iostream>
#include <vector>
#include <cmath>

#include "../Piece.h"
#include "Bishop.h"

using namespace std;

Bishop::Bishop(bool white) : Piece(3, "F", white)
{
}

// Fonction isMoveLegal testée et validée
bool Bishop::isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                         const int posXFinal, const int posYFinal) const
{
  // Appel moveDiagonal pour savoir si le deplacement est un mouvement en diagonal autorisé retourne true si il l'est et false sinon
  if (moveDiagonal(C, posXInit, posYInit, posXFinal, posYFinal))
  {
    return true;
  }
  return false;
}
