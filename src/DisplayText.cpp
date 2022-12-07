#include <iostream>

#include "Configuration.h"
#include "DisplayText.h"
#include "Piece.h"

using namespace std;

DisplayText::DisplayText()
{
}

DisplayText::~DisplayText()
{
}

void DisplayText::displayConfig(Configuration &C)
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (C.board(i, j) != nullptr)
            {
                if (C.board(i, j)->getIsWhite())
                    cout << " " << C.board(i, j)->getNomPiece() << "blanc |";

                else
                    cout << " " << C.board(i, j)->getNomPiece() << " noir |";
            }
            else
                cout << "    " << 0 << "   |";
        }

        cout << endl;
    }
}
