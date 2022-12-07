#include "Configuration.h"

using namespace std;

Configuration::Configuration()
{

  // tabPiece[Y][X] avec Y qui représente l'axe des absices de gauche à droite et X qui représente l'axe vertical de bas en haut

  // Ligne 0 : les pièces blanches
  tabPiece[0][0] = new Rook(true);
  tabPiece[1][0] = new Knight(true);
  tabPiece[2][0] = new Bishop(true);
  tabPiece[3][0] = new Queen(true);
  tabPiece[4][0] = new King(true);
  tabPiece[5][0] = new Bishop(true);
  tabPiece[6][0] = new Knight(true);
  tabPiece[7][0] = new Rook(true);

  // Ligne 1 : les pions blancs
  for (int i = 0; i < 8; i++)
    tabPiece[i][1] = new Pawn(true);

  // les 4 lignes vides :
  for (int j = 2; j < 6; j++)
    for (int i = 0; i < 8; i++)
      tabPiece[i][j] = nullptr;

  // Ligne 6 : les pions noirs
  for (int i = 0; i < 8; i++)
    tabPiece[i][6] = new Pawn(false);

  // Ligne 7 : les pièces noires
  tabPiece[0][7] = new Rook(false);
  tabPiece[1][7] = new Knight(false);
  tabPiece[2][7] = new Bishop(false);
  tabPiece[3][7] = new Queen(false);
  tabPiece[4][7] = new King(false);
  tabPiece[5][7] = new Bishop(false);
  tabPiece[6][7] = new Knight(false);
  tabPiece[7][7] = new Rook(false);

  whiteToPlay = true;

  if (whiteToPlay)
    cout << "Configuration initiale créée ! C'est aux blancs de jouer" << endl;
  else
    cout << "Configuration initiale créée ! C'est aux noirs de jouer" << endl;
}


Configuration::~Configuration()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (tabPiece[i][j] != nullptr)
      {
        delete tabPiece[i][j];
      }
    }
  }
}


numPiece Configuration::convertNomPiece(string nomPiece) const
{
  if (nomPiece == "T")
  {
    return (numPiece::T);
  }
  if (nomPiece == "C")
  {
    return (numPiece::C);
  }
  if (nomPiece == "F")
  {
    return (numPiece::F);
  }
  if (nomPiece == "D")
  {
    return (numPiece::D);
  }
  if (nomPiece == "R")
  {
    return (numPiece::R);
  }
  if (nomPiece == "P")
  {
    return (numPiece::P);
  }

  return (numPiece::E); // vide
}

Piece *Configuration::board(int i, int j) const
{
  // cout << i << " "<< j << endl;
  assert(i >= 0 && j >= 0 && i < 8 && j < 8);
  return tabPiece[i][j];
}

void Configuration::setBoard(int i, int j, Piece *P)
{
  assert(i >= 0 && j >= 0 && i < 8 && j < 8);
  tabPiece[i][j] = P;
}

bool Configuration::getWhiteToPlay() const
{
  return whiteToPlay;
}

void Configuration::setWhiteToPlay(bool play)
{
  whiteToPlay = play;
}

void Configuration::moveCastleInConfig(Vector2D cursorStartPos, Vector2D cursorFinalPos)
{

  if ((cursorStartPos.getX()-cursorFinalPos.getX())>0)
        {
          if (board(0, cursorStartPos.getY())!=nullptr)
          {
            setBoard(cursorFinalPos.getX(), cursorFinalPos.getY(), board(cursorStartPos.getX(), cursorStartPos.getY())); // Change la valeur de la case d'arriver par la case de depart
            setBoard(cursorStartPos.getX(), cursorStartPos.getY(), nullptr); // Change la valeur de la case de depart par nullptr

            board(cursorFinalPos.getX(),cursorFinalPos.getY())->setIsMoved(true); // Change la valeur de isMoved par true de la piece selectionné qui est le roi.

            setBoard(3,cursorStartPos.getY(), board(0, cursorStartPos.getY())); // Change la valeur de la case d'arrivé de la tour lors du roque par la case ou se situe la tour
            setBoard(0, cursorStartPos.getY(), nullptr); // Change la valeur de la case ou se situait precedement la tour par nullptr

            board(3,cursorStartPos.getY())->setIsMoved(true); // Change la valeur de isMoved par true de la tour.
          }
          else  //cout pour verifier que la fonction fonctionne bien
          {
            cout << "Probleme dans isMoveCastle pas de tour la ou il faut en X=0" << endl;
          }
        }
        else
        {
          if (board(7, cursorStartPos.getY())!=nullptr)
          {
            setBoard(cursorFinalPos.getX(), cursorFinalPos.getY(), board(cursorStartPos.getX(), cursorStartPos.getY())); // Change la valeur de la case d'arriver par la case de depart
            setBoard(cursorStartPos.getX(), cursorStartPos.getY(), nullptr); // Change la valeur de la case de depart par nullptr

            board(cursorFinalPos.getX(),cursorFinalPos.getY())->setIsMoved(true); // Change la valeur de isMoved par true de la piece selectionné qui est le roi.

            setBoard(5,cursorStartPos.getY(), board(7, cursorStartPos.getY())); // Change la valeur de la case d'arrivé de la tour lors du roque par la case ou se situe la tour
            setBoard(7, cursorStartPos.getY(), nullptr); // Change la valeur de la case ou se situait precedement la tour par nullptr

            board(5,cursorStartPos.getY())->setIsMoved(true); // Change la valeur de isMoved par true de la tour.
          }
          else  //cout pour verifier que la fonction fonctionne bien
          {
            cout << "Probleme dans isMoveCastle pas de tour la ou il faut en X=7" << endl;
          }
        }
}

bool Configuration::movePiece(Vector2D cursorStartPos, Vector2D cursorFinalPos)
{
  // Verifie que la case de depart comprenne bien une Piece
  if (board(cursorStartPos.getX(), cursorStartPos.getY()) != nullptr)
  {

    bool movePossible = board(cursorStartPos.getX(), cursorStartPos.getY())
                            ->isMoveLegal(*this, cursorStartPos.getX(), cursorStartPos.getY(), cursorFinalPos.getX(), cursorFinalPos.getY());
    bool moveCastle = board(cursorStartPos.getX(), cursorStartPos.getY())
                            ->isMoveCastle(*this, cursorStartPos.getX(), cursorStartPos.getY(), cursorFinalPos.getX(), cursorFinalPos.getY());
    // Verifie si le mouvement est autorisé et si c'est le cas effectue le deplacement de la Piece dans la configuration
    if (movePossible)
    {
      // Appel moveCastleInConfig pour effectuer le deplacement si le deplacement est un roque
      if (moveCastle)
      {
        moveCastleInConfig(cursorStartPos, cursorFinalPos); //On déplace tour et roi concernés par le roque, dans la configuration
      }
      else
      {
        board(cursorStartPos.getX(), cursorStartPos.getY())->setIsMoved(true); // Mets le isMoved de la piece qui va se deplacer a true

        setBoard(cursorFinalPos.getX(), cursorFinalPos.getY(), board(cursorStartPos.getX(), cursorStartPos.getY())); // on écrase la pièce d'avant par la pièce d'arrivée

        setBoard(cursorStartPos.getX(), cursorStartPos.getY(), nullptr); // on définit la case occupée par la pièce déplacée avant le coup à nullptr

        if (!(board(cursorFinalPos.getX(), cursorFinalPos.getY())->getIsMoved())) // Change la valeur de isMoved par true si la piece qui se déplace n'avait jamais bouger
        {
          board(cursorFinalPos.getX(),cursorFinalPos.getY())->setIsMoved(true);
        }

        cout << "Vous avez choisi de déplacer la piece située à la position [" << cursorStartPos.getX() << " , " << cursorStartPos.getY() << "]" << endl;

        cout << "et de la mettre à la position [" << cursorFinalPos.getX() << " , " << cursorFinalPos.getX() << "]" << endl;
      }
    }
    else
    {
      cout << "Ce mouvement est interdit !" << endl;
    }
    return movePossible;
  }

  else
  {
    cout << "Selectionnez une case occupée par une pièce" << endl;
  }
  return false;
}

bool Configuration::movePieceTexte()
{
  Vector2D cursorStartPos;
  Vector2D cursorFinalPos;
  int X, Y;

  cout << "***********************************************************" << endl;
  cout << "Choisissez la coordonée X de départ de la pièce à déplacer" << endl;
  cout << " X = ";
  cin >> X;
  cursorStartPos.setX(X);
  cout << endl;
  cout << "Choisissez la coordonée Y de départ la pièce à déplacer" << endl;
  cout << " Y = ";
  cin >> Y;
  cursorStartPos.setY(Y);
  cout << endl;
  if (this->board(cursorStartPos.getX(), cursorStartPos.getY()) != nullptr)
  {
    if (this->board(cursorStartPos.getX(), cursorStartPos.getY())->getIsWhite() == this->getWhiteToPlay())
    {
      cout << "***********************************************************" << endl;
      cout << "Choisissez la coordonée Y d'arrivée de la pièce à déplacer" << endl;
      cout << " X = ";
      cin >> X;
      cursorFinalPos.setX(X);
      cout << endl;
      cout << "Choisissez la coordonée Y d'arrivée de la pièce à déplacer" << endl;
      cout << " Y = ";
      cin >> Y;
      cursorFinalPos.setY(Y);
      cout << endl;

      movePiece(cursorStartPos, cursorFinalPos);

      return true;
    }
    else
    {
      cout << "La pièce selectionnée n'a pas le trait, choisissez une pièce de la couleur opposée" << endl;

      return false;
    }
  }
  movePiece(cursorStartPos, cursorFinalPos);
  return false;
}

SaveConfig Configuration::saveConfiguration() const
{
  SaveConfig C;
  for (int j = 0; j < 8; j++)
  {
    for (int i = 0; i < 8; i++)
    {
      if (this->board(i, j) != nullptr) // si la case est occupée par une pièce
      {
        if (this->board(i, j)->getIsWhite())
          C.setTabID(i, j, convertNomPiece(this->board(i, j)->getNomPiece()), white); // on stocke le nom de la piece dans tabID
        else
          C.setTabID(i, j, convertNomPiece(this->board(i, j)->getNomPiece()), black); // on insère le nom de la pièce dans le fichier
      }

      else
        C.setTabID(i, j, E, E);
    }
  }

  cout << "Sauvegarde de la configuration  ... OK\n";

  return C;
}

void Configuration::loadConfiguration(const SaveConfig &config)
{
  for (int j = 0; j < 8; j++)
  {
    for (int i = 0; i < 8; i++)
    {
      if (this->board(i, j) != nullptr)
      {
        delete board(i, j); // libérer mémoire associé en i,j dans board car on va perdre le pointeur vers la case i,j de tabPiece à cause de setBoa
      }

      Piece *p;
      pieceColor info = config.getTabID(i, j);

      if (info.type == numPiece::T)
        p = new Rook(info.color == numPiece::white);
      else if (info.type == numPiece::C)
        p = new Knight(info.color == numPiece::white);
      else if (info.type == numPiece::F)
        p = new Bishop(info.color == numPiece::white);
      else if (info.type == numPiece::D)
        p = new Queen(info.color == numPiece::white);
      else if (info.type == numPiece::R)
        p = new King(info.color == numPiece::white);
      else if (info.type == numPiece::P)
        p = new Pawn(info.color == numPiece::white);
      else
        p = nullptr;

      this->setBoard(i, j, p); // on charge chacune des cases de la configuration retournée
      // par la case de la configuration stockée dans configVector à la position iterator
    }
  }
  cout << "Lecture de la configuration ... OK" << endl;
}

bool Configuration::isKingCheck()
{
  bool kingFind = false;
  int i = 0;
  int j = 0;
  // Boucle qui cherche le roi de la couleur du trait dans le tableau de la configuration
  while ((!(kingFind)) && (i < 8))
  {
    j = 0;
    while ((!(kingFind)) && (j < 8))
    {
      // Verifie si la case selectionné contient une piece puis mets kingFind a true si la piece a comme valeur 10 et la meme couleur que le trait
      if (board(i, j) != nullptr)
      {
        if ((board(i, j)->getValuePiece() == 10) &&
            (board(i, j)->getIsWhite() == getWhiteToPlay()))
        {
          kingFind = true;
        }
      }
      if (!(kingFind))
      {
        j += 1;
      }
    }
    if (!(kingFind))
    {
      i += 1;
    }
  }
  // Si le roi a ete trouvé on regarde pour chaque case si il y a une Piece dessus et si elle peut prendre le roi si c'est le cas elle renvoie true
  if (kingFind)
  {
    int x, y;
    for (x = 0; x < 8; x++)
    {
      for (y = 0; y < 8; y++)
      {
        if (board(x, y) != nullptr)
        {
          if (board(x, y)->isMoveLegal(*this, x, y, i, j))
          {
            return true;
          }
        }
      }
    }
    // Si la boucle se finie on renvoie false
    return false;
  }
  // Cout surtout pour verfier que la fonction marche correctement
  else
  {
    cout << "Le joueur dont c'est le tour n'as plus de roi il a donc perdu la partie" << endl;
    if (getWhiteToPlay())
    {
      cout << "Le joueur blanc à gagné la partie !" << endl;
    }
    else
    {
      cout << "Le joueur noir à gagné la partie !" << endl;
    }
  }
  return true;
}

bool Configuration::isKingMate()
{
  // Renvoie false si le roi n'est pas en echec car il ne peut donc pas etre en echec et mat
  if (!(isKingCheck()))
  {
    return false;
  }
  // Parcous le tableau de configuration et regarde pour chacun tout les coups possible et renvoie false si un mouvement dans la configuration permet de ne plus etre en echec
  for (int i=0; i<8; i++)
  {
    for (int j=0; j<8; j++)
    {
      if (board(i,j)!=nullptr)
      {
        if ((board(i,j)->getIsWhite()) == getWhiteToPlay())
        {
          for (int x=0; x<8; x++)
          {
            for (int y=0; y<8; y++)
            {
              if (board(i,j)->isMoveLegal(*this,i,j,x,y))
              {
                // Declare une piece pour permettre de stocker temporairement une piece du tableau
                Piece *p;
                p = board(x,y);
                setBoard(x, y, board(i,j)); // on écrase la pièce d'avant par la pièce d'arrivée
                setBoard(i, j, nullptr); // on définit la case occupée par la pièce déplacée avant le coup à nullptr
                if (!(isKingCheck()))
                {
                  // On replace les piece a leur position de depart grace a la piece que on a créée p
                  setBoard(i, j, board(x,y));
                  setBoard(x, y, p);

                  p = nullptr;
                  return false;
                }
                else
                {
                  // On replace les piece a leur position de depart grace a la piece que on a créée p
                  setBoard(i, j, board(x,y));
                  setBoard(x, y, p);
                  p = nullptr;
                }
              }
            }
          }
        }
      }
    }
  }
  // Renvoie true si lors du parcours du tableau aucun mouvement permettant de sortir de l'echec n'a ete trouvé
  return true;
}
