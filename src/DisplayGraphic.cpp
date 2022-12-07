#include <vector>

#include "DisplayGraphic.h"

#define SIZE 125

using namespace std;

DisplayGraphic::DisplayGraphic()
{
    sf::Texture *whitePawnText = new sf::Texture();
    whitePawnText->loadFromFile("data/image/whiteP.png");

    sf::Texture *blackPawnText = new sf::Texture();
    blackPawnText->loadFromFile("data/image/blackP.png");

    sf::Texture *whiteRookText = new sf::Texture();
    whiteRookText->loadFromFile("data/image/whiteT.png");

    sf::Texture *blackRookText = new sf::Texture();
    blackRookText->loadFromFile("data/image/blackT.png");

    sf::Texture *whiteBishopText = new sf::Texture();
    whiteBishopText->loadFromFile("data/image/whiteF.png");

    sf::Texture *blackBishopText = new sf::Texture();
    blackBishopText->loadFromFile("data/image/blackF.png");

    sf::Texture *whiteKnightText = new sf::Texture();
    whiteKnightText->loadFromFile("data/image/whiteC.png");

    sf::Texture *blackKnightText = new sf::Texture();
    blackKnightText->loadFromFile("data/image/blackC.png");

    sf::Texture *whiteQueenText = new sf::Texture();
    whiteQueenText->loadFromFile("data/image/whiteD.png");

    sf::Texture *blackQueenText = new sf::Texture();
    blackQueenText->loadFromFile("data/image/blackD.png");

    sf::Texture *whiteKingText = new sf::Texture();
    whiteKingText->loadFromFile("data/image/whiteR.png");

    sf::Texture *blackKingText = new sf::Texture();
    blackKingText->loadFromFile("data/image/blackR.png");

    sf::Texture *emptyText = new sf::Texture();
    emptyText->loadFromFile("data/image/empty.png");

    sf::Texture *circleText = new sf::Texture();
    circleText->loadFromFile("data/image/circle.png");

    //------------------------REMPLISSAGE DE mapText------------------------//

    mapText = {
        {
            "whiteP", // la chaine de charactère whiteP sera associée à la texture whitePawnText
            whitePawnText,
        },
        {
            "blackP",
            blackPawnText,
        },

        {
            "whiteT",
            whiteRookText,
        },
        {
            "blackT",
            blackRookText,
        },

        {
            "whiteF",
            whiteBishopText,
        },
        {
            "blackF",
            blackBishopText,
        },

        {
            "whiteC",
            whiteKnightText,
        },
        {
            "blackC",
            blackKnightText,
        },

        {
            "whiteD",
            whiteQueenText,
        },
        {
            "blackD",
            blackQueenText,
        },

        {
            "whiteR",
            whiteKingText,
        },
        {
            "blackR",
            blackKingText,
        },

        {
            "empty",   // la chaine de charactère empty sera associée à la texture emptyText
            emptyText, // utilisée pour les cases vides (texture transparante)
        },

        {
            "circle",
            circleText,
        }};
}

DisplayGraphic::~DisplayGraphic()
{
    for (auto i = mapText.begin(); i != mapText.end(); i++)
    {
        delete i->second;
    }
}

// Fonction renvoyant une paire d'entier x et y coordonnées de la piece cliqué par l'utilisateur
sf::Vector2i DisplayGraphic::getCoordonatesCursor(Configuration &C, sf::Vector2i pixelPos)
{
    sf::Vector2i coordonatesCursor;

    coordonatesCursor.x = pixelPos.x / SIZE;
    coordonatesCursor.y = pixelPos.y / SIZE;

    return coordonatesCursor;
}

// affiche un cercle sur les différentes cases possibles pour une pièce
void DisplayGraphic::displayPossiblePositions(Configuration &C, sf::RenderWindow &window, sf::Vector2i cursorStartPos)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (C.board(cursorStartPos.x, cursorStartPos.y) != nullptr) // test si la case cliquée est non vide
            {
                bool movePossible = C.board(cursorStartPos.x, cursorStartPos.y)->isMoveLegal(C, cursorStartPos.x, cursorStartPos.y, i, j); // test si le mouvement est légal

                if (movePossible) // si mouvement légal
                {
                    sf::RectangleShape circle = sf::RectangleShape(sf::Vector2f(125.0, 125.0)); // on crée un rectangle

                    circle.setTexture(mapText["circle"]); // on lui assigne une texture et une position
                    circle.setPosition(i * 125, j * 125);

                    window.draw(circle); // on dessine le rectangl
                }
            }
        }
    }
}

sf::RectangleShape DisplayGraphic::createTimeBox(bool white, sf::Color color)
{
    if (white)
    {
        sf::RectangleShape whiteTimeBox(sf::Vector2f(300, 100));
        whiteTimeBox.setFillColor(color);
        whiteTimeBox.setPosition(sf::Vector2f(1000, 0));

        return whiteTimeBox;
    }

    sf::RectangleShape blackTimeBox(sf::Vector2f(300, 100));
    blackTimeBox.setFillColor(color);
    blackTimeBox.setPosition(sf::Vector2f(1000, 900));

    return blackTimeBox;
}

sf::RectangleShape DisplayGraphic::createInfoGameBox(sf::Color color)
{
    sf::RectangleShape infoGameBox(sf::Vector2f(300, 400));
    infoGameBox.setFillColor(color);
    infoGameBox.setPosition(sf::Vector2f(500, 0));

    return infoGameBox;
}

Vector2D DisplayGraphic::translateSFvectorToVector2D(sf::Vector2i vector2i)
{
    Vector2D vectorSFML;
    vectorSFML.setX(vector2i.x);
    vectorSFML.setY(vector2i.y);

    return vectorSFML;
}

void DisplayGraphic::displayConfigGraphic(Configuration &C, sf::RenderWindow &window) // Affiche le tableau de rect après chaque appel de movePieceGraphic
{
    /*-------------affichage pour chacune des pièces------------*/
    window.clear(sf::Color(208, 211, 205));
    sf::RectangleShape chessBoard(sf::Vector2f(1000.0, 1000.0)); // création du rectangle contenant le plateau
    sf::Texture chessBoardTexture;                               // création d'une texture pour le plateau
    chessBoardTexture.loadFromFile("data/image/chessBoard.png"); // chargement de l'image du plateau sur la texture
    chessBoard.setTexture(&chessBoardTexture);
    window.draw(chessBoard); // on dessine la texture dans la window

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tabRect[i][j] = sf::RectangleShape(sf::Vector2f(125.0, 125.0));

            if (C.board(i, j) != nullptr) // on test si l'on est sur une case vide ou non
            {
                Piece *piece = C.board(i, j);

                string color;

                if (piece->getIsWhite()) // on assigne un string en accord avec la couleur de la pièce
                    color = "white";
                else
                    color = "black";

                tabRect[i][j].setTexture(mapText[color + piece->getNomPiece()]); /* on set la texture associé à la chaine
                 "color + piece->nomPiece" dans mapText. Exemple : tabRect[i][j]->setTexture(mapText["whiteP"]) avec P = pion*/
                tabRect[i][j].setPosition(i * 125, j * 125);                     // on place la texture à la position correspondant au parcours de l'échiquier
            }
            else
            {
                tabRect[i][j].setTexture(mapText["empty"]);  // on set la texture associé à la chaine "empty" dans mapText
                tabRect[i][j].setPosition(i * 125, j * 125); // on place la texture à la position correspondant au parcours de l'échiquier
            }
            window.draw(tabRect[i][j]); // on dessines la case en x = i et y = j;
        }
    }
}

sf::Font DisplayGraphic::loadFont()
{
    sf::Font font;
    if (!font.loadFromFile("data/font/arial.ttf"))
    {
        cout << "Erreur de chargement de la police" << endl;
    }

    return font;
}

void DisplayGraphic::displayTime(Configuration &C, Game &game, sf::RenderWindow &window, sf::Font font)
{

    sf::Text textTimeWhite;
    sf::Text textTimeBlack;

    textTimeWhite.setFont(font);
    textTimeBlack.setFont(font);

    textTimeWhite.setPosition(sf::Vector2f(1100, 25));
    textTimeBlack.setPosition(sf::Vector2f(1100, 925));

    textTimeWhite.setCharacterSize(50);
    textTimeBlack.setCharacterSize(50);

    textTimeWhite.setColor(sf::Color::White);
    textTimeBlack.setColor(sf::Color::White);

    std::stringstream stringWhite;
    std::stringstream stringBlack;

    stringWhite << floor(game.getPlayer(true).getTimeToPlay() / 60)
                << ":"
                << ((int)game.getPlayer(true).getTimeToPlay()) % 60;

    stringBlack << floor(game.getPlayer(false).getTimeToPlay() / 60)
                << ":"
                << ((int)game.getPlayer(false).getTimeToPlay() % 60);

    textTimeWhite.setString(stringWhite.str().c_str());
    textTimeBlack.setString(stringBlack.str().c_str());

    if (game.getPlayer(true).getTimeToPlay() > 0)
    {
        window.draw(textTimeWhite);
    }
    if (game.getPlayer(false).getTimeToPlay() > 0)
    {
        window.draw(textTimeBlack);
    }
}

void DisplayGraphic::displayInfoGameBox(Configuration &C, Game &game, sf::RenderWindow &window, sf::Font font)
{
    sf::Text textInfoGame;
    textInfoGame.setFont(font);
    textInfoGame.setPosition(sf::Vector2f(1010, 400));
    textInfoGame.setCharacterSize(28);
    textInfoGame.setColor(sf::Color::Black);
    

    

    
        if(C.getWhiteToPlay())
        {
            textInfoGame.setString("Le trait est blanc...\nEn attente d'un coup\n");
            
            if(C.isKingCheck())
            {
                textInfoGame.setString("Echec au roi blanc");
            }
            if(C.isKingMate())
            {
                textInfoGame.setString("Echec et mat !\nLes noirs gagnent !");
            }
        }
        else
        {
            textInfoGame.setString("Le trait est noir...\nEn attente d'un coup\n");
            
            if(C.isKingCheck())
            {
                textInfoGame.setString("Le roi noir est en position d'échec\n");
            }
            if(C.isKingMate())
            {
                textInfoGame.setString("Echec et mat !\nLes blancs gagnent !");
            }
        }

        window.draw(textInfoGame);


}

void DisplayGraphic::displayGame(Configuration &C, Game game)
{
    sf::Font font = loadFont();

    sf::RenderWindow window(sf::VideoMode(1300, 1000), "Chess Code !"); // création d'une fenêtre sans bordure
                                                                        // créée std::vector de saveConfig dans classe jeu,
    Menu menu(window.getSize().x, window.getSize().y);

    sf::RectangleShape whiteTimeBox = createTimeBox(true, sf::Color(130, 130, 130));
    sf::RectangleShape blackTimeBox = createTimeBox(false, sf::Color(130, 130, 130));

    sf::RectangleShape infoGameBox = createInfoGameBox(sf::Color(130, 130, 130));

    vector<SaveConfig> configVector;               // on crée le vector de configuration
    configVector.push_back(C.saveConfiguration()); // on ajoute la configuration initiale dans le vector de configuration
    unsigned int iterator = 0;                     // itérateur pour le parcours des éléments de configVector

    displayConfigGraphic(C, window);

    sf::Vector2i cursorStartPos; // position Initiale de la pièce
    sf::Vector2i cursorFinalPos; // position Finale de la pièce

    sf::Event event;

    bool isRightClicLegal = false;

    while (window.isOpen())
    {
        if (game.isGameOver(C)) // On test si a partie est terminée
        {
            sleep(5);
            break;
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            static bool lock_click;
            if (event.type == sf::Event::MouseButtonPressed) // Si clic sur  bouton souris
            {

                /******************************* CLIC GAUCHE DE L'UTILISATEUR *****************************/

                if (event.mouseButton.button == sf::Mouse::Left && lock_click != true) // précise quel bouton de la souris est concerné
                {
                    sf::Vector2i pixelPos = sf::Mouse::getPosition(window); // on récupère la position du curseur dans pixelPos
                    cursorStartPos = getCoordonatesCursor(C, pixelPos);     // on appel la fonction getCoordonatesCursor avec C
                                                                            // et pixelPos que l'on assigne a coordonatesCursor

                    if (C.board(cursorStartPos.x, cursorStartPos.y) != nullptr)
                    {
                        if (C.board(cursorStartPos.x, cursorStartPos.y)->getIsWhite() == C.getWhiteToPlay()) // si la couleur de la pièce choisieest la même
                                                                                                             // que le trait alors on peut la déplacer
                        {
                            if (iterator == configVector.size() - 1)
                            {
                                displayConfigGraphic(C, window);
                                displayPossiblePositions(C, window, cursorStartPos);

                                lock_click = true;       // verrouillage de la boucle
                                isRightClicLegal = true; // on autorise le clic droit
                            }
                        }
                    }
                }

                /******************************* CLIC DROIT DE L'UTILISATEUR *******************************/

                if (event.mouseButton.button == sf::Mouse::Right && lock_click != true)
                {
                    if (isRightClicLegal) // si le clic gauche à été autorisé
                    {
                        sf::Vector2i pixelPos = sf::Mouse::getPosition(window); // on récupère la position du curseur dans pixelPos
                        cursorFinalPos = getCoordonatesCursor(C, pixelPos);     // on appel la fonction getCoordonatesCursor avec C et pixelPos que l'on assigne a coordonatesCursor
                        // C.isKingMate(); // Ajout pour faire un test
                        if (C.movePiece(translateSFvectorToVector2D(cursorStartPos), translateSFvectorToVector2D(cursorFinalPos)))
                        {
                            game.handlePlayerTime(C.getWhiteToPlay()); // on stop l'horloge du joueur qui a joué et
                                                                       // déclenche celle de l'adversaire
                            game.switchWhiteToPlay(C);                 // on modifie le trait après que le coup ait été joué

                            configVector.push_back(C.saveConfiguration());
                            iterator++; // on ajoute une configuration à configVector donc on incrémente iterator de 1
                        }
                        displayConfigGraphic(C, window);

                        // on ajoute à configVector la nouvelle configuration après le déplacement

                        lock_click = true; /* après l'éxécution du code au dessus, cela va verrouiller la boucle
                        et ne pas répéter l'action un nombre de fois trop important*/
                        isRightClicLegal = false;
                    }
                }
            }

            /******************************* L'UTILISATEUR RELACHE SON CLIC *****************************/

            if (event.type == sf::Event::MouseButtonReleased) // Le bouton de la souris est relaché
            {
                if (event.mouseButton.button == sf::Mouse::Left || event.mouseButton.button == sf::Mouse::Right) // on spécifie le bouton pressé
                {
                    lock_click = false; // déverouille la boucle lorsque le bouton est relaché;
                }
            }
        }

        static bool lock_press_touch = false; // verrouilage de la touche fleche

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) // si on appuie sur echap, on ferme la fenêtre
            window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && lock_press_touch != true) // si on appuie sur flèche de gauche, on charge la config du coup précédent
        {
            if (iterator > 0)
            {
                C.loadConfiguration(configVector[--iterator]); // on charge la configuration stockée dans configVector à la position iterator --
                displayConfigGraphic(C, window);
                lock_press_touch = true;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && lock_press_touch != true) // si on appuie sur flèce de droite, on charge la config du coup suivant
        {
            if (iterator < configVector.size() - 1)
            {
                C.loadConfiguration(configVector[++iterator]); // on charge la configuration stockée dans configVector à la position iterator ++
                displayConfigGraphic(C, window);
                lock_press_touch = true;
            }
        }

        if (event.type == sf::Event::KeyReleased) // Le bouton de la souris est relaché
        {
            lock_press_touch = false; // déverouille la boucle lorsque le bouton est relaché;
        }

        /******************************* AFFICHAGE DES OBJETS GRAPHIQUES *******************************/

        window.draw(whiteTimeBox);
        window.draw(blackTimeBox);
        displayTime(C, game, window, font);
        displayInfoGameBox(C, game, window, font);

        window.display();
    }
}
