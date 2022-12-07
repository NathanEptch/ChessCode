#include "SaveConfig.h"

SaveConfig::SaveConfig()
{
}

SaveConfig::~SaveConfig()
{
}

pieceColor SaveConfig::getTabID(int i, int j) const
{
    return tabID[i][j];
}

void SaveConfig::setTabID(int i, int j, numPiece type, numPiece color)
{
    tabID[i][j].type = type;
    tabID[i][j].color = color;
}