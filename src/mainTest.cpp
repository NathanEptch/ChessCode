#include <iostream>

#include "Piece.h"
#include "Configuration.h"
#include "DisplayText.h"
#include "Game.h"

using namespace std;

int main()
{
  Configuration test_config;
  Configuration config_init;
  Game game = Game(10);
  cout << " " << endl;
  cout << " " << endl;
  cout << "Commencement du test isKingMate" << endl;
  bool kingMate;
  kingMate = test_config.isKingMate();

  bool b = false;
  if((test_config.board(2,1)) != nullptr)
  {
    b = ((test_config.board(2,1))->isMoveLegal(test_config,2,4,2,6));
  }
  cout << b << endl;
  DisplayText::displayConfig(config_init);
  DisplayText::displayConfig(test_config);
  
  int posX1 = 0;
  int posY1 = 1;
  int posX2 = 0;
  int posY2 = 6;

  Vector2D cursorStartPos;
  Vector2D cursorFinalPos;

  cursorStartPos.setX(posX1);
  cursorStartPos.setY(posY1);
  cursorFinalPos.setX(posX2);
  cursorFinalPos.setY(posY2);

  config_init.movePiece(cursorStartPos, cursorFinalPos);
  
  // Assert pour tester les si les cases initiales sont bien des pointeurs sur des Pieces.
  assert((test_config.board(2,4))!=nullptr);
  assert((test_config.board(6,2))!=nullptr);
  assert((test_config.board(3,3))!=nullptr);
  assert((test_config.board(3,7))!=nullptr);
  
  // Assert pour tester differents mouvements pour tester isMoveLegal dans les heritages de Piece
  assert((test_config.board(2,4)->isMoveLegal(test_config,2,4,3,3))==false);
  assert((test_config.board(2,4)->isMoveLegal(test_config,2,4,2,6))==true);
  assert((test_config.board(2,4)->isMoveLegal(test_config,2,4,1,5))==true);
  assert((test_config.board(2,4)->isMoveLegal(test_config,2,4,3,5))==false);
  assert((test_config.board(6,2)->isMoveLegal(test_config,6,2,5,1))==true);
  assert((test_config.board(6,2)->isMoveLegal(test_config,6,2,6,0))==false);
  assert((test_config.board(3,3)->isMoveLegal(test_config,3,3,3,0))==true);
  assert((test_config.board(3,3)->isMoveLegal(test_config,3,3,0,6))==false);
  assert((test_config.board(3,3)->isMoveLegal(test_config,3,3,2,4))==true);
  assert((test_config.board(3,3)->isMoveLegal(test_config,3,3,1,1))==true);
  assert((test_config.board(3,7)->isMoveLegal(test_config,3,7,3,3))==true);
  assert((test_config.board(3,7)->isMoveLegal(test_config,3,7,3,2))==false);
  
  cout << " " << endl;
  for (int j = 0; j<8; j++)
  {
    for (int i=0; i <8;i++)
    {
      if (test_config.board(i,j) != nullptr)
      {
        cout << (test_config.board(i,j))->getIsWhite();
      }
      else
      {
        cout << "3";
      }
      cout << (test_config.board(5,5))->getIsWhite();
      if (test_config.board(3,3) == nullptr) { cout << "3,3 est nullptr" << endl;}
      if ((i==2)&&(j==4))
      {
        cout << 2 << " | ";
      }
      else
      {
        bool test = test_config.board(2,4)->isMoveLegal(test_config,2,4,i,j);
        cout << "Case : " << i << "," << j << " = " << test << endl;
  
        if (test_config.board(i,j) == nullptr)
        {
          cout << test << " | " ;
        }
        else
        {
          if (test)
          {
            cout << test << " | ";
          }
          else
          {
            cout << "3" << " | ";
          }
        }
      }
    }
    cout << endl;
  }
  if (config_init.getWhiteToPlay())
  {
    cout << "C'est au joueur blanc de jouer !" << endl;
  }
  else
  {
    cout << "C'est au joueur noir de jouer !" << endl;
  }
  if (kingMate)
  {
    cout << "Le roi est en echec" << endl;
  }
  else
  {
    cout << "Le roi n'est pas en echec" << endl;
  }
  return 0;
}
