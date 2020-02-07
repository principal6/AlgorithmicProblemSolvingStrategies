#pragma once

#include <string>
#include <vector>

static constexpr int KBoardWidthMax{ 20 };
static constexpr int KBoardHeightMax{ 20 };

int g_BoardWidth{};
int g_BoardHeight{};
char g_Board[KBoardHeightMax][KBoardWidthMax]{};
const int KBlocks[4][2][2]
{
	{
		{ 0, 1 },
		{ 1, 1 }
	},
	{
		{ 1, 0 },
		{ 1, 1 }
	},
	{
		{ 1, 1 },
		{ 0, 1 }
	},
	{
		{ 1, 1 },
		{ 1, 0 }
	}
};

void clearBoard()
{
	g_BoardWidth = 0;
	g_BoardHeight = 0;
	memset(g_Board, 0, sizeof(char) * KBoardHeightMax * KBoardWidthMax);
}

void pushBoard(const std::string& Line)
{
	int LineLength{ (int)Line.size() };
	if (LineLength == 0) return;
	if (LineLength > KBoardWidthMax) return;
	if (g_BoardHeight >= KBoardHeightMax) return;

	if (g_BoardWidth == 0) g_BoardWidth = LineLength;
	if (g_BoardWidth != LineLength) return;

	for (int i = 0; i < LineLength; ++i)
	{
		g_Board[g_BoardHeight][i] = Line[i];
	}
	++g_BoardHeight;
}

int countBlanks()
{
	int Count{};
	for (int y = 0; y < g_BoardHeight; ++y)
	{
		for (int x = 0; x < g_BoardWidth; ++x)
		{
			if (g_Board[y][x] == '.') ++Count;
		}
	}
	return Count;
}

bool fitsBlock(int X, int Y, int BlockID)
{
	if (X < 0 || X >= g_BoardWidth) return false;
	if (Y < 0 || Y >= g_BoardHeight) return false;

	for (int y = Y; y < Y + 2; ++y)
	{
		for (int x = Y; x < Y + 2; ++x)
		{
			if (KBlocks[BlockID][y][x] && g_Board[y][x] == '#') return false;
		}
	}
	return true;
}

void pushBlock(int X, int Y, int BlockID)
{

}

void countCases(int& Count)
{
	if (countBlanks() % 3) return;

	for (int y = 0; y < g_BoardHeight; ++y)
	{
		for (int x = 0; x < g_BoardWidth; ++x)
		{
			for (int iBlock = 0; iBlock < 4; ++iBlock)
			{
				if (fitsBlock(x, y, iBlock))
				{
					pushBlock(x, y, iBlock);


					//popBlock();
				}
			}
		}
	}

}