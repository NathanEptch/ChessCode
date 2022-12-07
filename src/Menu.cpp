#include "Menu.h"

Menu::Menu()
{}


Menu::Menu(float width, float height)
{
    if(!fontMenu.loadFromFile("data/font/arial.ttf"))
    {
        cout << "Erreur de chargement de la police" << endl;
    }

    textureMenu->loadFromFile("data/image/menuBackground.jpg");

    rectangleMenu.setTexture(textureMenu);
    rectangleMenu.setSize(sf::Vector2f(width, height));
    rectangleMenu.setPosition(sf::Vector2f(0,0));

    menu[0].setFont(fontMenu);
    menu[0].setColor(sf::Color(219, 83, 22));
    menu[0].setString("ChessCode Version Graphique");
    menu[0].setPosition(sf::Vector2f(width/3, height / (NUMBER_ITEMS + 1) * 1));

    menu[1].setFont(fontMenu);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("ChessCode Version Texte");
    menu[1].setPosition(sf::Vector2f(width/3, height / (NUMBER_ITEMS + 1) * 2));

    menu[2].setFont(fontMenu);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Options");
    menu[2].setPosition(sf::Vector2f(width/3, height / (NUMBER_ITEMS + 1) * 3));

    menu[3].setFont(fontMenu);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Quitter ChessCode");
    menu[3].setPosition(sf::Vector2f(width/3, height / (NUMBER_ITEMS + 1) * 4));
    
    selectedItemIndex = 0;
}

Menu::~Menu()
{
    delete textureMenu;
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(rectangleMenu);

    for(int i = 0; i < NUMBER_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::moveUp()
{
    if(selectedItemIndex - 1 >= 0) //si l'item selectionné n'est pas celui en première position
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color(219, 83, 22));
    }
}

void Menu::moveDown()
{
    if(selectedItemIndex + 1 < NUMBER_ITEMS)//si l'item selectionné n'est pas celui en dernière position
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color(219, 83, 22));
    }
}

int Menu::getPressedItem(){ return selectedItemIndex;}


void Menu::displayMenu()
{
    sf::RenderWindow menuWindow(sf::VideoMode(850, 569), "Bienvenue dans ChessCode !");

    Menu menu(menuWindow.getSize().x, menuWindow.getSize().y);
    
    while (menuWindow.isOpen())
    {
        sf::Event event;

        while(menuWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        menuWindow.close();
                        break;

                    case sf::Keyboard::Up:
                        menu.moveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu.moveDown();
                        break;
                    case sf::Keyboard::Return:
                        switch (menu.getPressedItem())
                        {
                        case 0:
                            cout << "Vous avez choisi la version graphique de ChessCode : " << endl;
                            menuWindow.close();//on ferme le menu
                            menu.launchChessCodeGraphic(); //puis on lance la version graphique
                            break;
                        
                        case 1:
                            cout << "Vous avez choisi la version textuelle de ChessCode : " << endl;
                            menuWindow.close();
                            menu.launchChessCodeText();
                            break;

                        case 2:
                            cout << "Vous êtes dans les options : " << endl;
                            menu.selectedTimeValue = menu.launchMenuTime();
                            break;

                        case 3:
                            cout << "Vous avez choisi de quitter ChessCode : " << endl;
                            menuWindow.close();
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
                menuWindow.close();
                break;
            
            default:
                break;
            }
        }
        menuWindow.clear();
        menu.draw(menuWindow);
        menuWindow.display();
    }
    
}

void Menu::launchChessCodeGraphic()
{
    Game game(selectedTimeValue); //Initialisation de la game
    Configuration Start_Config; //initialisation de la configuraiton
    DisplayGraphic display;
    display.displayGame(Start_Config, game);
}

void Menu::launchChessCodeText()
{

    Game game(selectedTimeValue);// Initialisation de la game avec le temps choisi
    Configuration Start_Config; // initialisation de la configuration
    bool movePiece = false;
    while (true)
    {
        DisplayText::displayConfig(Start_Config);
        movePiece = Start_Config.movePieceTexte();

        if(movePiece)
        {
            game.handlePlayerTime(Start_Config.getWhiteToPlay()); // on stop l'horloge du joueur qui a joué et
                                                                  // déclenche celle de l'adversaire
            game.switchWhiteToPlay(Start_Config);                 // on modifie le trait après que le coup ait été joué
        }
    }
}

int Menu::launchMenuTime()
{
    MenuTime menuTime;
    int selectedTime = menuTime.displayMenuTimes();
    return selectedTime;
} 