#include "ScoreCalculator.h"

int getFrameScore(vector<int>::iterator& , vector<int>::iterator );
int popNextBall(vector<int>::iterator&, vector<int>::iterator);
int scoreFromNextTwoBalls(vector<int>::iterator, vector<int>::iterator);
int scoreFromNextBall(vector<int>::iterator, vector<int>::iterator);
int scoreFromNthLastBall(vector<int>::iterator, vector<int>::iterator, int);

vector<int> ScoreCalculator::score(vector<int> frames)
{
	vector<int>::iterator nextBallItr{ frames.begin() };

	vector<int>::iterator endItr{ frames.end() };

	vector<int> scores{};
	int cumulativeScore{ 0 };
	const int MAX_NUMBER_OF_FRAMES{ 10 };

	while (nextBallItr != endItr && scores.size < MAX_NUMBER_OF_FRAMES) {

		cumulativeScore += getFrameScore(nextBallItr, endItr);

		scores.push_back(cumulativeScore);
	}

	return  scores;
}

int getFrameScore(vector<int>::iterator& nextBallItr, vector<int>::iterator endItr)
{
	const int STRIKE{ 10 };
	const int SPARE{ 10 };

	int firstBall{ popNextBall(nextBallItr, endItr) };

	if (STRIKE == firstBall) {
		return firstBall + scoreFromNextTwoBalls(nextBallItr, endItr);
	}
	
	int secondBall{ popNextBall(nextBallItr, endItr) };

	if (SPARE == (firstBall + secondBall)) {
		return firstBall + secondBall + scoreFromNextBall(nextBallItr, endItr);
	}

	return firstBall + secondBall;
}

int popNextBall(vector<int>::iterator& nextBallItr, vector<int>::iterator endItr)
{
	int nextBall{ 0 };

	if (nextBallItr != endItr) {
		nextBall = *nextBallItr++;
	}
	return nextBall;
}

int scoreFromNextTwoBalls(vector<int>::iterator nextBallterator, vector<int>::iterator endScoresIterator)
{
	return 	scoreFromNthLastBall(nextBallterator, endScoresIterator, 1) + scoreFromNthLastBall(nextBallterator, endScoresIterator, 0);
}

int scoreFromNextBall(vector<int>::iterator nextBallterator, vector<int>::iterator endScoresIterator) {
	return scoreFromNthLastBall(nextBallterator, endScoresIterator, 0);
}

int scoreFromNthLastBall(vector<int>::iterator nextBallterator, vector<int>::iterator endScoresIterator, int n) {
	if (distance(nextBallterator, endScoresIterator) > n) {
		return *(nextBallterator+n);
	}

	return 0;
}

