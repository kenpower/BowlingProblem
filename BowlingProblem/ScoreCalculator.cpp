#include "ScoreCalculator.h"
#include <stack>

vector<int> ScoreCalculator::score(vector<int> frames)
{
	std::reverse(frames.begin(), frames.end());

	vector<int> scores{};

	while (!frames.empty()) {

		int frameTotal = popNextBall(frames);

		bool strike = false;
		if (10 == frameTotal) {
			frameTotal += peekNextBall(frames);
			frameTotal += peekBallAfterNext(frames);
		}
		else{
			frameTotal += popNextBall(frames);
			if (10 == frameTotal)
				frameTotal += peekNextBall(frames);
		}

		scores.push_back(frameTotal);
	}

	return  scores;
}

int ScoreCalculator::popNextBall(std::vector<int>& frames)
{
	int nextBall{ 0 };
	if (!frames.empty()) {
		nextBall = frames.back();
		frames.pop_back();
	}
	return nextBall;
}

int ScoreCalculator::peekBallAfterNext(std::vector<int>& frames)
{
	if (frames.size() >= 2) {
		return frames.end()[-2];
	}
	return 0;
}

int ScoreCalculator::peekNextBall(vector<int> frames) {
	if(!frames.empty())
	 return frames.back();

	return 0;
}

