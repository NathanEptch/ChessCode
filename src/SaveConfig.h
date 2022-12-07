#ifndef SAVE_CONFIG_H
#define SAVE_CONFIG_H

#include "numPiece.h"

using namespace std;

/**
 * @brief Structure d'énum numPiece permettant de préciser
 * la couleur de le type de chacune des pièces

 */
struct pieceColor
{
    numPiece type;
    numPiece color;
};

class SaveConfig
{
private:
    /**
     * @brief Tableau de pieceColor de taille 8x8
     *
     */
    pieceColor tabID[8][8];

public:
    /**
     * @brief Constructeur de SaveConfig
     *
     */
    SaveConfig();

    /**
     * @brief Destructeur de SaveConfig
     *
     */
    ~SaveConfig();

    /**
     * @brief Fonction renvoyant la pieceColor stockée dans tabID aux indices i et j
     *
     * @param i position de la pieceColor dans tabID
     * @param j position de la pieceColor dans tabI
     * @return pieceColor
     */
    pieceColor getTabID(int i, int j) const;
    void setTabID(int i, int j, numPiece type, numPiece color);
};

#endif
