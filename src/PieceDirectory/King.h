#pragma once
#include <iostream>
#include <vector>

#include "../Piece.h"
#include "../Configuration.h"

using namespace std;

class King : public Piece
{
public:
  /**
    * @brief Constructeur par defaut de la classe King qui appel le Constructeur de la classe Piece
    *
    * @param white : booleen qui nous donnes la couleur de la Piece, true pour blanc et false pour noir
    */
  King(bool white);

  bool isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                   const int posXFinal, const int posYFinal) const;
};
