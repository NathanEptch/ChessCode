#include <iostream>
#include <string>

#include "Piece.h"
#include "Configuration.h"

using namespace std;

Piece::Piece()
{}

Piece::Piece(int V, string N, bool white)
{
  valuePiece = V;
  nomPiece = N;
  isWhite = white;
  isMoved = false;
}

Piece::~Piece()
{
}

bool Piece::getIsWhite() const
{
  return isWhite;
}

void Piece::setIsWhite(const bool white)
{
  isWhite = white;
}

int Piece::getValuePiece() const
{
  return valuePiece;
}

bool Piece::getIsMoved() const
{
  return isMoved;
}

void Piece::setIsMoved(const bool moved)
{
  isMoved = moved;
}

string Piece::getNomPiece()
{
  return nomPiece;
}

bool Piece::moveVertical(const Configuration &C, const int posXInit, const int posYInit,
                       const int posXFinal, const int posYFinal) const
{
  if (C.board(posXInit, posYInit) == nullptr)
  {
    return false;
  }
  if ((C.board(posXFinal, posYFinal)!=nullptr) && ((C.board(posXInit, posYInit))!=nullptr))
  {
    if (((C.board(posXFinal, posYFinal))->getIsWhite()) == ((C.board(posXInit, posYInit))->getIsWhite()))
    {
      return false;
    }
  }
    if ((posXInit != posXFinal) && (posYInit != posYFinal))
    {
      return false;
    }
    if (posXInit == posXFinal)
    {
      int j = posYInit;
      while (posYFinal != j)
      {
        if ((C.board(posXInit, j) != nullptr) && (posYInit != j))
        {
          return false;
        }
        if (posYInit > posYFinal)
        {
          j -= 1;
        }
        else
        {
          j += 1;
        }
      }
    }
    else if (posYInit == posYFinal)
    {
      int i = posXInit;
      while (posXFinal != i)
      {
        if ((C.board(i, posYInit) != nullptr) && (posXInit != i))
        {
          return false;
        }
        if (posXInit > posXFinal)
        {
          i -= 1;
        }
        else
        {
          i += 1;
        }
      }
    }
  return true;
}

bool Piece::moveDiagonal(const Configuration& C,const int posXInit,const int posYInit,
  const int posXFinal,const int posYFinal) const
{
  if (C.board(posXInit, posYInit) == nullptr)
  {
    return false;
  }
  if ((C.board(posXFinal, posYFinal) != nullptr) && (C.board(posXInit, posYInit)) != nullptr)
  {
    if (((C.board(posXFinal, posYFinal))->getIsWhite()) == ((C.board(posXInit, posYInit))->getIsWhite()))
    {
      return false;
    }
  }
    if (abs(posXInit - posXFinal) != abs(posYInit - posYFinal))
    {
      return false;
    }
    int i = posXInit;
    int j = posYInit;
    while (i != posXFinal)
    {
      if ((C.board(i,j) != nullptr) && (posXInit != i))
      {
        return false;
      }
      if (posXInit < posXFinal)
      {
        i += 1;
      }
      else
      {
        i -= 1;
      }
      if (posYInit < posYFinal)
      {
        j += 1;
      }
      else
      {
        j -= 1;
      }
    }
  return true;
}

bool Piece::isMoveLegal(const Configuration& C, const int posXInit, const int posYInit, const int posXFinal, const int posYFinal) const
{
  return false;
}


bool Piece::isMoveCastle(const Configuration& C,const int posXInit,const int posYInit,
const int posXFinal,const int posYFinal) const
{
  if ((C.board(posXInit,posYInit)!=nullptr)&&(abs(posXInit-posXFinal)==2)&&(posYInit-posYFinal==0))
  {
    if (posXInit-posXFinal > 0)
    {
      if (C.board(0,posYInit)!=nullptr)
      {
        if ((!(C.board(0,posYInit)->getIsMoved())) && (!(C.board(posXInit,posYInit)->getIsMoved())))
        {
          for (int i=0; i<3; i++)
          {
            if (C.board(1+i,posYInit)!=nullptr)
            {
              return false;
            }
          }
          return true;
        }
      }
    }
    else
    {
      if (C.board(7,posYInit)!=nullptr)
      {
        if ((!(C.board(7,posYInit)->getIsMoved())) && (!(C.board(posXInit,posYInit)->getIsMoved())))
        {
          for (int i=0; i<2; i++)
          {
            if (C.board(6-i,posYInit)!=nullptr)
            {
              return false;
            }
          }
          return true;
        }
      }
    }
  }
  return false;
}

bool Piece::isMoveGetKingCheck(Configuration C ,const int x, const int y,
const int i, const int j)
{
  cout << "je suis dedans " << endl;
  if (C.board(x,y)!= nullptr)
  {
    Piece *p;
    p = C.board(i,j);
    C.setBoard(i,j, C.board(x,y));
    C.setBoard(x,y,nullptr);
    bool inCheck = C.isKingCheck();

    if (inCheck)
    {
      C.setBoard(x,y,C.board(i,j));
      C.setBoard(i,j,p);
      p = nullptr;
      return true;
    }
    else
    {
      C.setBoard(x,y,C.board(i,j));
      C.setBoard(i,j,p);
      p = nullptr;
      return false;
    }
  }
  cout << "La case de depart ne comprends pas de piece dans moveCheck" << endl;
  return false;
}
