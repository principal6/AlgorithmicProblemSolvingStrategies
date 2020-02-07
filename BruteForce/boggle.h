#pragma once

#include <string>

constexpr int KBoardWidthMax{ 10 };
constexpr int KBoardHeightMax{ 10 };
int g_BoardWidth{ 5 };
int g_BoardHeight{ 5 };
char g_Board[KBoardHeightMax][KBoardWidthMax]
{
	{ 'U', 'R', 'L', 'P', 'M' },
	{ 'X', 'P', 'R', 'E', 'T' },
	{ 'G', 'I', 'A', 'E', 'T' },
	{ 'X', 'T', 'N', 'Z', 'Y' },
	{ 'X', 'O', 'Q', 'R', 'S' }
};

void clearBoard()
{
	g_BoardHeight = 0;
	g_BoardWidth = 0;
	memset(g_Board, 0, sizeof(char) * KBoardHeightMax * KBoardWidthMax);
}

void pushBoard(const std::string& Line)
{
	if (Line.empty()) return;
	if ((int)Line.size() > KBoardWidthMax) return;
	if (g_BoardHeight >= KBoardHeightMax) return;

	if (g_BoardWidth == 0) g_BoardWidth = (int)Line.size();
	if (g_BoardWidth != (int)Line.size()) return;

	for (int i = 0; i < (int)Line.size(); ++i)
	{
		g_Board[g_BoardHeight][i] = Line[i];
	}
	++g_BoardHeight;
}

bool hasWord(int y, int x, const std::string& word)
{
	// range check
	if (y >= 5 || y < 0) return false;
	if (x >= 5 || x < 0) return false;

	// first letter
	if (word.empty()) return false;
	if (g_Board[y][x] != word[0]) return false;

	// last letter
	if (word.length() == 1) return true;

	// go deeper
	for (int dy = -1; dy <= 1; ++dy)
	{
		for (int dx = -1; dx <= 1; ++dx)
		{
			if (hasWord(y + dy, x + dx, word.substr(1)))
			{
				return true;
			}
		}
	}
	return false;
}