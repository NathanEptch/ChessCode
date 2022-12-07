#include <iostream>
#include <vector>
#include <cmath>

#include "../Piece.h"
#include "Pawn.h"

using namespace std;

Pawn::Pawn(bool white) : Piece(5, "P", white)
{
}

// Fonction isMoveLegal testée et validée
bool Pawn::isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                       const int posXFinal, const int posYFinal) const
{
  // Renvoie false si la case de depart ne contient aucune piece.
  if (C.board(posXInit, posYInit) == nullptr)
  {
    return false;
  }
  // Renvoie false si la case d'arriver comprends une piece d'une couleur identique de celle de depart.
  if (C.board(posXFinal, posYFinal) != nullptr && C.board(posXInit, posYInit) != nullptr)
  {
    if ((C.board(posXFinal, posYFinal)->getIsWhite()) == (C.board(posXInit, posYInit)->getIsWhite()))
    {
      return false;
    }
  }
  // Renvoie false si la case d'arriver ne fait pas partie des cases soit au dessus du pion ou en dessous
  // ou alors en diagonal de 1 en avant ou en arriere.
  if (((abs(posXInit - posXFinal) != 1) || (abs(posYInit - posYFinal) != 1)) &&
      ((abs(posXInit - posXFinal) != 0 || abs(posYInit - posYFinal) > 2)))
  {
    return false;
  }
  // Renvoie false si la case d'arriver est en diagonal de la piece et que il n'y a aucune piece dessus.
  if ((posXInit != posXFinal) && (C.board(posXFinal, posYFinal) == nullptr))
  {
    return false;
  }
  // Renvoie false si le pion avance tout droit et qu'il y a un pion devant lui
  if ((C.board(posXFinal, posYFinal) != nullptr) && (posXInit - posXFinal == 0))
  {
    return false;
  }
  // Renvoie false si le pion avance de 2 alors que il a deja bouger.
  if (((C.board(posXInit, posYInit)->getIsMoved())) && (abs(posYInit - posYFinal) == 2))
  {
    return false;
  }
  // Renvoie false si la case est blanche et que le pion monte.
  if ((C.board(posXInit, posYInit)->getIsWhite()) && (posYInit > posYFinal))
  {
    return false;
  }
  // Renvoie false si la case est noir et que le pion descent.
  if ((!(C.board(posXInit, posYInit)->getIsWhite())) && (posYInit < posYFinal))
  {
    return false;
  }
  // Renvoie false si le pion est blanc et qu'il avance de 2 et que il y a un pion sur la case par laquel il doit passer.
  if (!(C.board(posXInit, posYInit)->getIsWhite()) && (abs(posYInit - posYFinal) == 2) &&
      (C.board(posXInit, posYFinal + 1) != nullptr))
  {
    return false;
  }
  // Renvoie false si le pion est noir et qu'il avance de 2 et que il y a un pion sur la case par laquel il doit passer.
  if ((C.board(posXInit, posYInit)->getIsWhite()) && (abs(posYInit - posYFinal) == 2) &&
      (C.board(posXInit, posYFinal - 1) != nullptr))
  {
    return false;
  }
  // Renvoie true si tout les tests on été passé sans rien retourné
  return true;
}
