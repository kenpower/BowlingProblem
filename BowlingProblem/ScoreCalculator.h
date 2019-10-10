#pragma once
#include <vector>

using namespace std;

class ScoreCalculator
{
public:
	static vector<int> score(vector<int> frames);

private:
	static int peekNextBall(vector<int> frames);
	static int peekBallAfterNext(std::vector<int>& frames);
	static int popNextBall(std::vector<int>& frames);
};

