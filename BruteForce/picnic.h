#pragma once

#include <vector>
#include <algorithm>

static constexpr int KStudentCountMax{ 10 };
bool bIsMatched[KStudentCountMax]{};

void Match(int A, int B) { bIsMatched[A] = bIsMatched[B] = true; }
void DeMatch(int A, int B) { bIsMatched[A] = bIsMatched[B] = false; }

bool IsNoOneMatched(int A, int B) { return !(bIsMatched[A] || bIsMatched[B]); }
bool IsEveryoneMatched(int StudentCount)
{
	for (int iStudent = 0; iStudent < StudentCount; ++iStudent)
	{
		if (!bIsMatched[iStudent]) return false; 
	} 
	return true;
}

void countCases(int StudentCount, const std::vector<std::pair<int, int>>& vPairs, int& CaseCount, int PairOffset = 0)
{
	if (IsEveryoneMatched(StudentCount))
	{
		++CaseCount;
		return;
	}

	// offset is needed in order to avoid duplication!
	for (int iPair = PairOffset; iPair < (int)vPairs.size(); ++iPair)
	{
		const auto& Pair{ vPairs[iPair] };
		if (IsNoOneMatched(Pair.first, Pair.second))
		{	
			Match(Pair.first, Pair.second);

			countCases(StudentCount, vPairs, CaseCount, iPair + 1);

			DeMatch(Pair.first, Pair.second);
		}
	}
}