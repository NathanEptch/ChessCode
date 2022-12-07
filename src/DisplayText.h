#include <iostream>


#include "Configuration.h"

using namespace std;



class DisplayText
{
private:
    
public:
/**
 * @brief Construct a new display Text object
 * 
 */
    DisplayText();
/**
 * @brief Destroy the display Text object
 * 
 */
    ~DisplayText();
/**
 * @brief procédure permettant d'afficher une Configuration dans la console.
 * 
 * @param C : Représente la configuration que l'on souhaite afficher.   
 */
    static void displayConfig(Configuration &C);

};