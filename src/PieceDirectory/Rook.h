#pragma once

#include <iostream>
#include <vector>

#include "../Configuration.h"
#include "../Piece.h"

using namespace std;

class Rook : public Piece
{
public:
    /**
      * @brief Constructeur par defaut de la classe Rook qui appel le Constructeur de la classe Piece
      *
      * @param white : booleen qui nous donnes la couleur de la Piece, true pour blanc et false pour noir
      */
    Rook(bool white);

    bool isMoveLegal(const Configuration &C, const int posXInit, const int posYInit, const int posXFinal, const int posYFinal) const;
};
