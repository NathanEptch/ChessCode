#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include <sys/types.h>
#include <unistd.h>

#include "DisplayText.h"
#include "Configuration.h"
#include "Piece.h"
#include "Game.h"
#include "Timer.h"
#include "Player.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;

class DisplayGraphic
{
private:
    /**
     * @brief Tableau contenant les rectangles des textures
     *
     */
    sf::RectangleShape tabRect[8][8];

    /**
     * @brief "dictionnaire" associant des texture à des strings
     *
     */
    map<string, sf::Texture *> mapText = map<string, sf::Texture *>();

public:
    /**
     * @brief Constructeur de display Graphic
     *
     */
    DisplayGraphic();

    /**
     * @brief Destructeur de display Graphic
     *
     */
    ~DisplayGraphic();

    /**
     * @brief Renvoie un couple d'entiers compris entre 0 et 7 qui correspond aux coordonnées
     *  du curseur dans la fenêtre, indique sur quelle case est notre curseur
     *
     * @param C Configuration
     * @param pixelPos sf::Vector2i
     * @return sf::Vector2i
     */

    sf::Vector2i getCoordonatesCursor(Configuration &C, sf::Vector2i pixelPos);

    /**
     * @brief affiche dans la fenêtre une texture sur chacune des cases sur lesquelles une pièce peut se rendre
     *
     * @param C configuration
     * @param window fenetre sfml
     * @param cursorStartPos  sf::Vector2i
     */
    void displayPossiblePositions(Configuration &C, sf::RenderWindow &window, sf::Vector2i cursorStartPos);

    /**
     * @brief crée les boites contenant les temps de joueurs en haut/bas droite
     *
     * @param white Indique le joueur pour lequel on crée la boite
     * @param color Précise la couleur de la boite
     * @return sf::RectangleShape  : un rectangle
     */
    sf::RectangleShape createTimeBox(bool white, sf::Color color);

    /**
     * @brief crée une boites contenant les informations sur ledéroulé de la partie (echec, echec et mat, trait)
     * @param color Précise la couleur de la boite
     * @return sf::RectangleShape  : un rectangle
     */
    sf::RectangleShape createInfoGameBox(sf::Color color);

    /**
     * @brief Permet de traduire un sf::Vector, objet de SFML en un vector2D crée pour chessCode
     * Ainsi, cette fonction nous permet de développer chessCode avec un code plus modulable et indépendant de SFML
     *
     * @param vector2i
     * @return un objet de la classe Vector2D
     */
    Vector2D translateSFvectorToVector2D(sf::Vector2i vector2i);

    /**
     * @brief Fonction permettant l'affichage de la configuration passée en paramètre
     * Elle sera appelé tout au long de la partie pour, au début, afficher la configuration
     * initiale, mais ensuite pour afficher les modifications de cette configuration
     * @param C Une configuration
     * @param window La fenetre SFML dans laquelle nous souaitons afficher la configuration
     */
    void displayConfigGraphic(Configuration &C, sf::RenderWindow &window);

    /**
     * @brief Fonction renvoyant une font et permettant de charge une police de charactères
     * Elle sera appelée une seule fois en début de programme afin de charge la police arial stockée dans /data/font
     * @return sf::Font
     */
    sf::Font loadFont();

    /**
     * @brief Fonction permettant d'afficher les nouvelles valeurs du temps, à chaque fois qu'elle est appelée
     *
     * @param C Configuration
     * @param game Une partie
     * @param window La fenêtre SFML dans laquelle nous souhaitons afficher les valeurs de temps des joueurs
     * @param font La police de charactères que nous souhaitons utilisée, chargée par sf::Font loadFont();
     */
    void displayTime(Configuration &C, Game &game, sf::RenderWindow &window, sf::Font font);

    /**
     * @brief Fonction permettant d'afficher les informations de la partie
     *
     * @param C Configuration
     * @param game Une partie
     * @param window La fenêtre SFML dans laquelle nous souhaitons afficher les valeurs de temps des joueurs
     * @param font La police de charactères que nous souhaitons utilisée, chargée par sf::Font loadFont();
     */
    void displayInfoGameBox(Configuration &C, Game &game, sf::RenderWindow &window, sf::Font font);

    /**
     * @brief Cette fonction va gérer l'ensemble des interactions Homme-Machine :
     * elle va permettre de récupérer les entrées claviers, les iunformations de la souris, etc
     * et d'agir suivant l'action effectué par le joueur
     *
     * @param C Configuration
     * @param game Une partie
     */
    void displayGame(Configuration &C, Game game);
};