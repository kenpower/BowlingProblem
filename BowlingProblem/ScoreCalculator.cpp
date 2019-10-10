#include "ScoreCalculator.h"
#include <stack>


bool isAStrike(int);
int getFrameScore(std::vector<int>& frames);
int popNextBall(vector<int>&);
int scoreFromNextTwoBalls(vector<int>&);
int scoreFromNextBall(vector<int>&);
int scoreFromNthLastBall(vector<int>&, int);

vector<int> ScoreCalculator::score(vector<int> frames)
{
	std::reverse(frames.begin(), frames.end());

	vector<int> scores{};
	int currentscore{ 0 };
	int frameCount{ 0 };

	while (!frames.empty() && frameCount <10) {

		frameCount++;

		currentscore += getFrameScore(frames);

		scores.push_back(currentscore);
	}

	return  scores;
}

int getFrameScore(std::vector<int>& frames)
{
	const int STRIKE{ 10 };
	const int SPARE{ 10 };

	int firstBall{ popNextBall(frames) };

	if (STRIKE == firstBall) {
		return firstBall + scoreFromNextTwoBalls(frames);
	}
	
	int secondBall{ popNextBall(frames) };

	if (SPARE == (firstBall + secondBall)) {
		return firstBall + secondBall + scoreFromNextBall(frames);
	}

	return firstBall + secondBall;
}

int popNextBall(vector<int>& frames)
{
	int nextBall{ 0 };
	if (!frames.empty()) {
		nextBall = frames.back();
		frames.pop_back();
	}
	return nextBall;
}

int scoreFromNextTwoBalls(vector<int>& frames)
{
	return 	scoreFromNthLastBall(frames, 2) + scoreFromNthLastBall(frames, 1);
}

int scoreFromNextBall(vector<int>& frames) {
	return scoreFromNthLastBall(frames, 1);
}

int scoreFromNthLastBall(vector<int>& frames, int n) {
	if (frames.size() >= n) {
		return frames.end()[-n];
	}

	return 0;
}

