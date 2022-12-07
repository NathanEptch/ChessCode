#include "MenuTime.h"

MenuTime::MenuTime()
{}

MenuTime::MenuTime(float width, float height)
{
    if(!fontMenu.loadFromFile("data/font/arial.ttf"))
    {
        cout << "Erreur de chargement de la police" << endl;
    }

    textureMenu->loadFromFile("data/image/menuBackground.jpg");
    
    rectangleMenu.setTexture(textureMenu);
    rectangleMenu.setSize(sf::Vector2f(width, height));
    rectangleMenu.setPosition(sf::Vector2f(0,0));

    //Menu de sélection des temps

    menuTimes[0].setFont(fontMenu);
    menuTimes[0].setColor(sf::Color(219, 83, 22));
    menuTimes[0].setString("1 minute");
    menuTimes[0].setPosition(sf::Vector2f(width/3, height / (NUMBER_TIMES + 1) * 1));

    menuTimes[1].setFont(fontMenu);
    menuTimes[1].setColor(sf::Color::White);
    menuTimes[1].setString("5 minutes");
    menuTimes[1].setPosition(sf::Vector2f(width/3, height / (NUMBER_TIMES + 1) * 2));

    menuTimes[2].setFont(fontMenu);
    menuTimes[2].setColor(sf::Color::White);
    menuTimes[2].setString("10 minutes");
    menuTimes[2].setPosition(sf::Vector2f(width/3, height / (NUMBER_TIMES + 1) * 3));

    menuTimes[3].setFont(fontMenu);
    menuTimes[3].setColor(sf::Color::White);
    menuTimes[3].setString("30 minutes");
    menuTimes[3].setPosition(sf::Vector2f(width/3, height / (NUMBER_TIMES + 1) * 4));

    menuTimes[4].setFont(fontMenu);
    menuTimes[4].setColor(sf::Color::White);
    menuTimes[4].setString("1 heure");
    menuTimes[4].setPosition(sf::Vector2f(width/3, height / (NUMBER_TIMES + 1) * 5));

    selectedTime = 0;

}

MenuTime::~MenuTime()
{
    delete textureMenu;
}


void MenuTime::drawTimes(sf::RenderWindow &window)
{
    window.draw(rectangleMenu);

    for(int i = 0; i < NUMBER_TIMES; i++)
    {
        window.draw(menuTimes[i]);
    }
}


void MenuTime::moveUp()
{
    if(selectedTime - 1 >= 0) //si l'item selectionné n'est pas celui en première position
    {
        menuTimes[selectedTime].setColor(sf::Color::White);
        selectedTime--;
        menuTimes[selectedTime].setColor(sf::Color(219, 83, 22));
    }
}

void MenuTime::moveDown()
{
    if(selectedTime + 1 < NUMBER_TIMES)//si l'item selectionné n'est pas celui en dernière position
    {
        menuTimes[selectedTime].setColor(sf::Color::White);
        selectedTime++;
        menuTimes[selectedTime].setColor(sf::Color(219, 83, 22));
    }
}


int MenuTime::getPressedTime(){ return selectedTime;}


int MenuTime::displayMenuTimes()
{
    sf::RenderWindow menuTimesWindow(sf::VideoMode(850, 569), "Selection du temps de rélfexion...");
    MenuTime menuTimes(menuTimesWindow.getSize().x, menuTimesWindow.getSize().y);

    while (menuTimesWindow.isOpen())
    {
        sf::Event event;

        while(menuTimesWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        menuTimesWindow.close();
                        break;

                    case sf::Keyboard::Up:
                        menuTimes.moveUp();
                        break;

                    case sf::Keyboard::Down:
                        menuTimes.moveDown();
                        break;
                    case sf::Keyboard::Return:
                        switch (menuTimes.getPressedTime())
                        {
                        case 0:
                            cout << "Vous avez choisi un temps de 1 minute : " << endl;
                            menuTimesWindow.close();//on ferme le menu
                            return 1;
                            break;


                        case 1:
                            cout << "Vous avez choisi un temps de 5 minutes : " << endl;
                            menuTimesWindow.close();   
                            return 5;                         
                            break;

                        case 2:
                            cout << "Vous avez choisi un temps de 10 minutes : " << endl;
                            menuTimesWindow.close();
                            break;

                        case 3:
                            cout << "Vous avez choisi un temps de 30 minutes : " << endl;
                            menuTimesWindow.close();
                            return 30;
                            break;

                        case 4:
                            cout << "Vous avez choisi un temps de 1 heure : " << endl;
                            menuTimesWindow.close();
                            return 60;
                            break;
                                               
                        default:
                            break;
                        }
                        break;
                    
                    default:
                        break;
                }
            break;

            case sf::Event::Closed:
                menuTimesWindow.close();
                break;
            
            default:
                break;
            }
        }
        menuTimesWindow.clear();
        menuTimes.drawTimes(menuTimesWindow);
        menuTimesWindow.display();
    }

    return 10;
}