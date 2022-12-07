#pragma once
#include <iostream>
#include <vector>

#include "../Piece.h"
#include "../Configuration.h"

using namespace std;

class Pawn : public Piece
{
public:
  /**
    * @brief Constructeur par defaut de la classe Pawn qui appel le Constructeur de la classe Piece
    *
    * @param white : booleen qui nous donnes la couleur de la Piece, true pour blanc et false pour noir
    */
  Pawn(bool white);

  bool isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                   const int posXFinal, const int posYFinal) const;
};
