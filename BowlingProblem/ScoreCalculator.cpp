#include "ScoreCalculator.h"

int getNextFrameScore(deque<int>& frames);
int takeNextBall(deque<int>&);
int scoreFromNextTwoBalls(deque<int> const&);
int scoreFromNextBall(deque<int> const&);
int scoreFromNthNextBall(deque<int> const&, int);
bool isAStrike(int);
bool isASpare(int);

vector<int> ScoreCalculator::score(vector<int> const& ballScores)
{
	deque<int> scoreForEachBall(ballScores.begin(), ballScores.end());

	vector<int> scores{};
	int cumulativeScore{ 0 };
	int frameCount{ 0 };

	while (!scoreForEachBall.empty() && frameCount <10) {

		frameCount++;

		cumulativeScore += getNextFrameScore(scoreForEachBall);

		scores.push_back(cumulativeScore);
	}

	return scores;
}

int getNextFrameScore(deque<int>& scoreForEachBall)
{
	int firstBall{ takeNextBall(scoreForEachBall) };

	if (isAStrike(firstBall)) {
		return firstBall + scoreFromNextTwoBalls(scoreForEachBall);
	}
	
	int twoBallScore = firstBall + takeNextBall(scoreForEachBall);

	if (isASpare(twoBallScore)) {
		return twoBallScore + scoreFromNextBall(scoreForEachBall);
	}

	return twoBallScore;
}

bool isAStrike(int ballScore) {
	int scoreForAStrike{ 10 };
	return scoreForAStrike == ballScore;
}

bool isASpare(int ballScore) {
	int scoreForASpare{ 10 };
	return scoreForASpare == ballScore;
}

int takeNextBall(deque<int>& scoreForEachBall)
{
	int nextBall{ 0 };
	if (!scoreForEachBall.empty()) {
		nextBall = scoreForEachBall.front();
		scoreForEachBall.pop_front();
	}
	return nextBall;
}

int scoreFromNextTwoBalls(deque<int> const& scoreForEachBall)
{
	return scoreFromNthNextBall(scoreForEachBall, 0) + scoreFromNthNextBall(scoreForEachBall, 1);
}

int scoreFromNextBall(deque<int> const& scoreForEachBall) {
	return scoreFromNthNextBall(scoreForEachBall, 0);
}

int scoreFromNthNextBall(deque<int> const& scoreForEachBall, int n) {
	if (scoreForEachBall.size() > n) {
		return scoreForEachBall[n];
	}
	return 0;
}

