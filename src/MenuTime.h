#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"

#include "Configuration.h"
#include "DisplayGraphic.h"

/**
 * @brief Définit le nombre de choix possible sur le menu des temps
 * 
 */
#define NUMBER_TIMES 5

using namespace std;

class MenuTime
{
private:
/**
 * @brief indique le choix du menu sélectionné
 * 
 */
    int selectedTime;

    /**
     * @brief Instanciation de la texture du menu des temps
     * 
     */
    sf::Texture * textureMenu = new sf::Texture;

    /**
     * @brief Instanciation de la police d'écriture du menu des temps
     * 
     */
    sf::Font fontMenu;

    /**
     * @brief instanciation des valeurs textuelle stockée aux différents indices du menu des temps
     * 
     */
    sf::Text menuTimes[NUMBER_TIMES];

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
    MenuTime();

    /**
 * @brief Surcharge du constructeur de menu permettant de préciser sa taille
 * 
 * @param width largeur du menu des temps
 * @param height hauteur du menu des temps
 */
    MenuTime(float width, float height);

    /**
     * @brief Destructeur du menu
     * 
     */
    ~MenuTime();

/**
 * @brief Procédure permettant de dessiner la texture du menu des temps et les sf::Text qui ont été définit
 * 
 * @param window Fenêtre dans laquelle on souhaite afficher le menu des temps
 */
    void drawTimes(sf::RenderWindow &window);
/**
 * @brief Procédure permttant à l'utilisateur de naviguer dans le menu des temps (vers le haut)
 * 
 */
    void moveUp();
/**
 * @brief Procédure permttant à l'utilisateur de naviguer dans le menu des temps (vers le bas)
 * 
 */
    void moveDown();

    /**
 * @brief Fonction retournant un entier permettant de connaitre le choix de l'utilisateur dans le menu des temps
 * 
 * @return int 
 */
    int getPressedTime();
    
    /**
 * @brief Procédure permettant d'aficher l'entiereté du menu des temps
 * 
 */
    static int displayMenuTimes();
};

