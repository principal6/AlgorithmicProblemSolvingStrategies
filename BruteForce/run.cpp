#include <cstdio>

//#define BOGGLE
//#define PICNIC
#define BOARDCOVER

// ####################
// ####################

#ifdef BOGGLE
#include "boggle.h"

int main()
{
	// |===========|===========|===========|===========|
	// | [BOARD]   | (1, 1)    | (2, 0)	   | (1, 2)	   |
	// | 		   | "PRETTY"  | "GIRL"	   | "REPEAT"  |
	// |===========|===========|===========|===========|
	// | U R L P M | . . . . . | . . L . . | . . . P . |
	// | X P R E T | . P R . T | . . R . . | . . R E . |
	// | G I A E T | . . . E T | G I . . . | . . A . . |
	// | X T N Z Y | . . . . Y | . . . . . | . T . . . |
	// | X O Q R S | . . . . . | . . . . . | . . . . . |
	// |===========|===========|===========|===========|

	clearBoard();
	pushBoard("URLPM");
	pushBoard("XPRET");
	pushBoard("GIAET");
	pushBoard("XTNZY");
	pushBoard("XOQRS");

	printf((hasWord(2, 0, "GIRL")) ? "true" : "false");

	return 0;
}
#endif // BOGGLE

#ifdef PICNIC
#include "picnic.h"

int main()
{
	// |====================================================|===========================================|===========|
	// | [INPUT DESCRIPTION]								| [INPUT]									| [OUTPUT]	|
	// |====================================================|===========================================|===========|
	// | Test case count									| 3											| 1			|
	// | CASE #0	Student count / Friend-pair count		| 2 1										| 3			|
	// |			Friend-pairs (a / b)					| 0 1										| 4			|
	// | CASE #1	Student count / Friend-pair count		| 4 6										| 			|
	// |			Friend-pairs (a / b)					| 0 1 1 2 2 3 3 0 0 2 1 3					| 			|
	// | CASE #2	Student count / Friend-pair count		| 6 10										| 			|
	// |			Friend-pairs (a / b)					| 0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5	| 			|
	// |====================================================|===========================================|===========|

	int TestCaseCount{};
	scanf_s("%d", &TestCaseCount);

	std::vector<int> vCaseCounts{};
	for (int iTestCase = 0; iTestCase < TestCaseCount; ++iTestCase)
	{
		int StudentCount{}, PairCount{};
		scanf_s("%d %d", &StudentCount, &PairCount);

		std::vector<std::pair<int, int>> vPairs{};
		for (int iPair = 0; iPair < PairCount; ++iPair)
		{
			int A{}, B{};
			scanf_s("%d %d", &A, &B);

			vPairs.emplace_back(std::make_pair(A, B));
		}

		int CaseCount{};
		countCases(StudentCount, vPairs, CaseCount);
		vCaseCounts.emplace_back(CaseCount);
	}

	for (const auto& CaseCount : vCaseCounts)
	{
		printf("%d\n", CaseCount);
	}

	return 0;
}
#endif // PICNIC

#ifdef BOARDCOVER
#include "boardcover.h"

int main()
{
	//	|===========================|===============|===============|
	//	| [INPUT DESCRIPTION]		| [INPUT]		| [OUTPUT]		|
	//	|===========================|===============|===============|
	//	| Test case count			| 3				| 0				|
	//	| CASE #0	Height / Width	| 3 7			| 2				|
	//	|			BOARD			| #.....#		| 1514			|
	//	|							| #.....#		|				|
	//	|							| ##...##		|				|
	//	| CASE #1	Height / Width	| 3 7			|				|
	//	|			BOARD			| #.....#		|				|
	//	|							| #.....#		|				|
	//	|							| ##..###		|				|
	//	| CASE #2	Height / Width	| 8 10			|				|
	//	|			BOARD			| ##########	|				|
	//	|							| #........#	|				|
	//	|							| #........#	|				|
	//	|							| #........#	|				|
	//	|							| #........#	|				|
	//	|							| #........#	|				|
	//	|							| #........#	|				|
	//	|							| ##########	|				|
	//	|===========================|===============|===============|

	int TestCaseCount{};
	scanf_s("%d", &TestCaseCount);

	std::vector<int> vCounts{};
	for (int iTestCase = 0; iTestCase < TestCaseCount; ++iTestCase)
	{
		int Height{}, Width{};
		scanf_s("%d %d", &Height, &Width);

		clearBoard();
		for (int y = 0; y < Height; ++y)
		{
			char Line[KBoardWidthMax]{};
			scanf_s("%s", Line, KBoardWidthMax);
			pushBoard(Line);
		}

		int Count{};
		countCases(Count);
		vCounts.emplace_back(Count);
	}

	for (const auto& Count : vCounts)
	{
		printf("%d\n", Count);
	}

	return 0;
}

#endif // BOARDCOVER
