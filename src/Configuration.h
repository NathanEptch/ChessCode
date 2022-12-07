#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <vector>

#include "Piece.h"
#include "PieceDirectory/Pawn.h"
#include "PieceDirectory/Rook.h"
#include "PieceDirectory/Knight.h"
#include "PieceDirectory/Bishop.h"
#include "PieceDirectory/King.h"
#include "PieceDirectory/Queen.h"
#include "Configuration.h"
#include "numPiece.h"
#include "SaveConfig.h"
#include "Vector2D.h"



using namespace std;

class Configuration
{
private:
    /**
     * @param whiteToPlay : permet de donner le trait, qui doit jouer le coup
     * Si whiteToPlay == true; c'est aux blancs de jouer, aux noirs sinon
     */
    bool whiteToPlay;

    /**
     * @param tabPiece : contient l'enselbke des pièces présentes sur le plateau de jeu, dans une configuration de jeu
     * type pointeur vers Tableau de piece
     */
    Piece *tabPiece[8][8];

public:
    /**
     * @brief Construit un nouvel objet de Configuration
     *
     */
    Configuration();

    /**
     * @brief Détruit un objet de Configuration
     *
     */
    ~Configuration();

    numPiece convertNomPiece(string nomPiece) const;

    /**
     * @brief Accesseur de tabPiece, permet de d'accéder de manière sûre à chacune des cases de tabPiece[8][8]
     *
     * @param i : indice de la case X de tabPiece
     * @param j : indice de la case Y de tabPiece
     * @return Piece*
     */
    Piece *board(int i, int j) const;

    /**
     * @brief Mutateur permettant de modifier de manière sûre les valeurs des cases de tabPiece
     *
     * @param i : indice de la case X de tabPiece
     * @param j : indice de la case Y de tabPiece
     * @param P : représente la pièce/valeur à ajouter dans la case correspondante
     */
    void setBoard(int i, int j, Piece *P);

    /**
     * @brief Accède à la valeur stocké dans whiteToPlay, permet de connaitre la couleur du trait
     *
     * @return Retourne la valeur stockée dans whiteToPlay
     */
    bool getWhiteToPlay() const;

    /**
      * @brief Mutateur : modifie le booleen whiteToPlay
      *
      * @param play : nouveau booleen de whiteToPlay
      */
    void setWhiteToPlay(bool play);

    /**
      * @brief Effectue le deplacement du roque dans le tableau de notre Configuration
      *
      * @param cursorStartPos : coordonnées de depart du roi
      * @param cursorFinalPos : coordonées d'arrivée du roi
      */
    void moveCastleInConfig(Vector2D cursorStartPos, Vector2D cursorFinalPos);

    /**
      * @brief Effectue le deplacement en version graphique d'une piece d'une postion de depart a une postion d'arrivée dans le tableau de configuration si le mouvement est autorisé.
      *
      * @param cursorStartPos : coordonées de depart de la piece a deplacer
      * @param cursorFinalPos : coordonées d'arrivée de la piece a deplacer
      *
      * @return Retourne un booleen indiquant si le deplacement a pu etre effectué ou non
      */
    bool movePiece(Vector2D cursorStartPos, Vector2D cursorFinalPos);

    /**
      * @brief Effectue le deplacement en version texte d'une piece en demandant a l'utilisateur les coordonées de depart et d'arrivé de la piece puis en effectuant le deplacement dans le tableau de configuration si le mouvement est autorisé.
      *
      * @return Retourne un booleen indiquant si le deplacement a pu etre effectué ou non
      */
    bool movePieceTexte();

    SaveConfig saveConfiguration() const;

    void loadConfiguration(const SaveConfig & config);

    /**
      * @brief Regarde si la configuration actuelle est en etat d'echec pour le joueur dont c'est le tour de joueur
      *
      * @return true si la configuration est en echec
      * @return false si la configuration n'est pas en echec
      */
    bool isKingCheck();

    /**
      * @brief Regarde si la configuration actuelle est en etat d'echec et mat pour le joueur dont c'est le tour de joueur
      *
      * @return true si la configuration est en echec et mat
      * @return false si la configuration n'est pas en echec et mat
      */
    bool isKingMate();
};
