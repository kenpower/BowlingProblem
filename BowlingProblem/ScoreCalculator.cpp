#include "ScoreCalculator.h"

int getFrameScore(deque<int>& frames);
int takeNextBall(deque<int>&);
int scoreFromNextTwoBalls(deque<int> const&);
int scoreFromNextBall(deque<int> const&);
int scoreFromNthNextBall(deque<int> const&, int);

vector<int> ScoreCalculator::score(vector<int> const& ballScores)
{
	deque<int> balls(ballScores.begin(), ballScores.end());

	vector<int> scores{};
	int currentscore{ 0 };
	int frameCount{ 0 };

	while (!balls.empty() && frameCount <10) {

		frameCount++;

		currentscore += getFrameScore(balls);

		scores.push_back(currentscore);
	}

	return  scores;
}

int getFrameScore(deque<int>& balls)
{
	const int STRIKE{ 10 };
	const int SPARE{ 10 };

	int firstBall{ takeNextBall(balls) };

	if (STRIKE == firstBall) {
		return firstBall + scoreFromNextTwoBalls(balls);
	}
	
	int secondBall{ takeNextBall(balls) };

	if (SPARE == (firstBall + secondBall)) {
		return firstBall + secondBall + scoreFromNextBall(balls);
	}

	return firstBall + secondBall;
}

int takeNextBall(deque<int>& balls)
{
	int nextBall{ 0 };
	if (!balls.empty()) {
		nextBall = balls.front();
		balls.pop_front();
	}
	return nextBall;
}

int scoreFromNextTwoBalls(deque<int> const& balls)
{
	return scoreFromNthNextBall(balls, 0) + scoreFromNthNextBall(balls, 1);
}

int scoreFromNextBall(deque<int> const& balls) {
	return scoreFromNthNextBall(balls, 0);
}

int scoreFromNthNextBall(deque<int> const& balls, int n) {
	if (balls.size() > n) {
		return balls[n];
	}
	return 0;
}

