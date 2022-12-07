#pragma once

/**
 * @brief Enumération permettant d'associer les couleurs des joueurs, 
 * le nom des pièces ou encore les cases vides à des valeur entières
 * 
 * numPiece est le nom de cette énumération
 */

typedef enum {
    white,
    black,
    T,
    C,
    F,
    D,
    R,
    P,
    E   //empty : case vide
} numPiece; 