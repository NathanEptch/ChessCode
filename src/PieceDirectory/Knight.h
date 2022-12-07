#pragma once

#include <iostream>
#include <vector>

#include "../Configuration.h"
#include "../Piece.h"

using namespace std;

class Knight : public Piece
{

public:
    /**
      * @brief Constructeur par defaut de la classe Knight qui appel le Constructeur de la classe Piece
      *
      * @param white : booleen qui nous donnes la couleur de la Piece, true pour blanc et false pour noir
      */
    Knight(bool white);

    bool isMoveLegal(const Configuration &C, const int posXInit, const int posYInit,
                     const int posXFinal, const int posYFinal) const;
};
