#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Configuration.h"
#include "DisplayGraphic.h"
#include "MenuTime.h"

/**
 * @brief Définit le nombre de choix possible sur le menu
 * 
 */
#define NUMBER_ITEMS 4 

using namespace std;

class Menu
{
private:

/**
 * @brief indique le choix du menu sélectionné
 * 
 */
    int selectedItemIndex;
/**
 * @brief indique la valeur du temps sélectionné dans le menu du temps
 * Valeur par défaut du temps de jeu de chacun des joueurs initialisée à 10
 * 
 */
    int selectedTimeValue = 10;
    /**
     * @brief Instanciation de la texture du menu
     * 
     */
    sf::Texture * textureMenu = new sf::Texture;
    /**
     * @brief Instanciation de la police d'écriture du menu
     * 
     */
    sf::Font fontMenu;
    /**
     * @brief instanciation des valeurs textuelle stockée aux différents indices du menu
     * 
     */
    sf::Text menu[NUMBER_ITEMS];
    /**
     * @brief instanciation du rectangleShape contenant le menu
     * 
     */
    sf::RectangleShape rectangleMenu;

public:
/**
 * @brief Constructeur du menu
 * 
 */
    Menu();
/**
 * @brief Surcharge du constructeur de menu permettant de préciser sa taille
 * 
 * @param width largeur du menu
 * @param height hauteur du menu
 */
    Menu(float width, float height);

    /**
     * @brief Destructeur du menu
     * 
     */
    ~Menu();
/**
 * @brief Procédure permettant de dessiner la texture du menu et les sf::Text qui ont été définit
 * 
 * @param window Fenêtre dans laquelle on souhaite afficher le menu
 */
    void draw(sf::RenderWindow &window);
/**
 * @brief Procédure permttant à l'utilisateur de naviguer dans le menu principal (vers le haut)
 * 
 */
    void moveUp();
/**
 * @brief Procédure permttant à l'utilisateur de naviguer dans le menu principal (vers le bas)
 * 
 */
    void moveDown();
/**
 * @brief Fonction retournant un entier permettant de connaitre le choix de l'utilisateur dans le menu
 * 
 * @return int 
 */
    int getPressedItem();

/**
 * @brief Procédure permettant d'aficher l'entiereté du menu
 * 
 */
    static void displayMenu();

/**
 * @brief Procédure qui, une fois appelée, va lancer un partie de la version graphique
 *  de chessCode avec le temps choisit dans le menu des temps, par défaut égal à 10 minutes
 */
    void launchChessCodeGraphic();

/**
 * @brief Procédure qui, une fois appelée, va lancer un partie de la version textuelle
 *  de chessCode avec le temps choisit dans le menu des temps, par défaut égal à 10 minutes
 */
    void launchChessCodeText();

/**
 * @brief Procédure qui, une fois appelée, va lancer le menu des temps dans lequel
 * l'utilisateur va pouvoir sélectionner un temps spécifique
 */  
    int launchMenuTime();
};

