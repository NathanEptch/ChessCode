#pragma once

#include <iostream>
#include <vector>
#include <utility>

class Configuration; // interdépendance entre config et piece -> dire à piece que config existe puis définir plus précisément

using namespace std;

class Piece
{
private:
  /** @param isWhite : booleen pour savoir si la piece est blanche */

  bool isWhite;

  /** @param valuePiece : valeur de la piece 1 = pion / 3 = cavalier / 3 = fou / 5 = tour / 9 = reine */

  int valuePiece;

  /** @param isMoved : booleen pour savoir si la piece a deja bouger depuis le debut de la partie */

  bool isMoved;


public:
  string nomPiece;
  /**
  @brief Constructeur par defaut de la classe Piece
  */
  Piece();

  Piece(bool white);

  Piece(int V, string N, bool white);

  /**
  @brief Destructeur de la classe Piece
  */
  virtual ~Piece();

  /**
    * @brief Accesseur : récupère le booleen isWhite de la Piece
    * @return true si la piece est blanche
  @return false si la piece est noir
  */
  bool getIsWhite() const;

  /**
  @brief Mutateur : modifie le booleen isWhite de la Piece
  @param newColor : booleen qui nous dis si la Piece est white = true ou black = noir
  */
  void setIsWhite(bool newColor);

  /**
  @brief Accesseur : récupère la value de la Piece
  @return un entier de la valeur de la piece
  */
  int getValuePiece() const;

  /**
    * @brief Mutateur : modifie le value de la Piece
    *
    * @param V : nouvelle valeur de la Piece
    */
  void setValuePiece(const int V);

  /**
    * @brief Accesseur : récupère le booleen isMoved de la Piece
    *
    * @return true si la piece a deja bouger
    * @return false si la piece n'a pas encore bouger
  */
  bool getIsMoved() const;

  /**
    * @brief Mutateur : modifie le booleen isMoved de la Piece
    *
    * @param moved : booleen qui nous dis si la Piece a deja bouger
  */
  void setIsMoved(const bool moved);

  /**
    * @brief Accesseur : recupere le nom de la piece
    *
    * @return string contenant le nom de la Piece
    */
  string getNomPiece();

  /**
    *@brief Fonction qui fait des tests pour savoir si le mouvement en partant de la position initial a celle d'arrivée est autorisé.
    *
    * @param C configuration actuelle
    * @param posXInit @param posYInit : coordonnées de la pièce a deplacé
    * @param posXFinal @param posYFinal : coordonnées d'arrivée de la pièce a deplacé
    *
    * @return true si le mouvement est autorisé
    * @return false si le mouvement n'est pas autorisé
    */
  virtual bool isMoveLegal(const Configuration& C,const int posXInit,const int posYInit,
const int posXFinal,const int posYFinal) const;

  /**
    * @brief Fonction qui renvoie un booleen indiquant si le mouvement effectué est un mouvement diagonal sans aucune piece sur le chemin.
    *
    * @param C configuration actuelle
    * @param posXInit @param posYInit : coordonnées de la pièce a deplacé
    * @param posXFinal @param posYFinal : coordonnées d'arrivée de la pièce a deplacé
    *
    * @return true si le mouvement est autorisé
    * @return false si le mouvement n'est pas autorisé
    */
  bool moveVertical(const Configuration &C, const int posXInit, const int posYInit,
const int posXFinal, const int posYFinal) const;

  /**
    * @brief Fonction qui renvoie un booleen indiquant si le mouvement effectué est un mouvement en vertical ou horizontal sans aucune piece sur le chemin.
    *
    * @param C configuration actuelle
    * @param posXInit @param posYInit : coordonnées de la pièce a deplacé
    * @param posXFinal @param posYFinal : coordonnées d'arrivée de la pièce a deplacé
    *
    * @return true si le mouvement est autorisé
    * @return false si le mouvement n'est pas autorisé
    */
  bool moveDiagonal(const Configuration& C,const int posXInit,const int posYInit,
  const int posXFinal,const int posYFinal) const;

  /**
    * @brief Fonction qui effectue des tests et renvoie un booleen indiquant si le mouvement effectué est un roque.
    *
    * @param C configuration actuelle
    * @param posXInit @param posYInit : coordonnées de la pièce a deplacé
    * @param posXFinal @param posYFinal : coordonnées d'arrivée de la pièce a deplacé
    *
    * @return true si le mouvement est un roque
    * @return false si le mouvement n'est pas un roque
  */  bool isMoveCastle(const Configuration& C, const int posXInit, const int posYInit,
  const int posXFinal, const int posYFinal) const;

  bool isMoveGetKingCheck(Configuration C, const int x, const int y, const int i, const int j);

};
