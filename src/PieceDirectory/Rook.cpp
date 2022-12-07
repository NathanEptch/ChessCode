#include <iostream>
#include <vector>
#include <string>

#include "../Piece.h"
#include "../DisplayText.h"
#include "Rook.h"


using namespace std;

Rook::Rook(bool white) : Piece(5, "T", white)
{}

// Fonction isMoveLegal testée et validée
bool Rook::isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                       const int posXFinal, const int posYFinal) const
{
  // Verifie si le mouvement est un mouvement vertical ou horizontal et renvoie true si c'est le cas
  if (moveVertical(C, posXInit, posYInit, posXFinal, posYFinal))
  {
    return true;
  }
  // Renvoie false dans l'autre cas
  return false;
}
