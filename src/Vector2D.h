#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief La classe Vector2D est une classe permettant de se défaire de la classe sf::Vector de SFMl
 * et de rendre chessCode moins dépendant de la librairie graphique utilisée
 */
class Vector2D
{
private:
    /**
     * @brief valeur x et y du vector2D
     *
     */
    int x;
    int y;

public:
    /**
     * @brief Constructeur de Vector2D
     *
     */
    Vector2D();

    /**
     * @brief Destructeur de Vector2D
     *
     */
    ~Vector2D();

    /**
     * @brief Accesseur de la valeur x du Vector2D
     *
     * @return int
     */
    int getX();

    /**
     * @brief Accesseur de la valeur y du Vector2D
     *
     * @return int
     */
    int getY();

    /**
     * @brief Mutateur permettant de définir la valeur de x du Vector2D
     *
     * @param Xvalue
     */
    void setX(int Xvalue);

    /**
     * @brief Mutateur permettant de définir la valeur y du Vector2D
     *
     * @param Yvalue
     */
    void setY(int Yvalue);
};