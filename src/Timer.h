#pragma once

#include <iostream>
#include <chrono>
#include <tgmath.h>
#include <math.h>

using namespace std;

class Timer
{

private:
    /**
     * @brief time représente la valeur du temps au moment ou le constructeur de Timer est appelé
     */
    std::chrono::time_point<std::chrono::system_clock> time;

public:
    /**
     * @brief Constructeur de la classe Timer
     *
     */
    Timer();

    /**
     * @brief Destructeur de la classe Timer
     *
     */
    ~Timer();

    /**
     * @brief Définit une nouvelle valeur pour time : le temps écoulé depuis le 1er janvier 1970
     */
    void reset();
    ;

    /**
     * @brief Renvoie le temps écoulé depuis le lancement du programme
     *
     * @return double
     */

    double getTime() const;

    /**
     * @brief Fonction de conversion de minutes en secondes pour pouvoir manipuler des secondes avec getTime, etc
     *
     * @param minutes Le nombre de minute à convertir
     * @return Le nombre de seconds
     */

    double convertFromMinutesToSeconds(double minutes);
};
