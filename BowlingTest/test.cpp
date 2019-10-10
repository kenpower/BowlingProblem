#include "pch.h"
#include "../BowlingProblem/ScoreCalculator.h"
using namespace std;


TEST(ScoreCalculator, ScoreOnBallZero) {

	vector<int> frames{ 0 };

	vector<int> score = ScoreCalculator::score(frames);

	EXPECT_EQ(1, score.size());
	EXPECT_EQ(0, score[0]);
}


TEST(ScoreCalculator, ScoreOneBall_5) {

	vector<int> frames{ 5 };

	vector<int> score = ScoreCalculator::score(frames);

	EXPECT_EQ(1, score.size());
	EXPECT_EQ(5, score[0]);
}

TEST(ScoreCalculator, NoBalls) {

	vector<int> frames{ };

	vector<int> score = ScoreCalculator::score(frames);

	vector<int> expected{};

	EXPECT_EQ(expected, score);
}

TEST(ScoreCalculator, Score_6_2) {

	vector<int> frames{ 6, 2};

	vector<int> score = ScoreCalculator::score(frames);

	vector<int> expected{ 8 };

	EXPECT_EQ(expected, score);
}

TEST(ScoreCalculator, Score_6_2_5) {

	vector<int> frames{ 6, 2, 5 };

	vector<int> score = ScoreCalculator::score(frames);

	vector<int> expected{ 8, 5 };

	EXPECT_EQ(expected, score);
}

TEST(ScoreCalculator, Score_6_2_5_4_3) {

	vector<int> frames{ 6, 2, 5, 4, 3 };

	vector<int> score = ScoreCalculator::score(frames);

	vector<int> expected{ 8, 9, 3};

	EXPECT_EQ(expected, score);
}

TEST(ScoreCalculator, Score_6_4_5_Spare) {

	vector<int> frames{ 6, 4, 5};

	vector<int> score = ScoreCalculator::score(frames);

	vector<int> expected{ 15, 5 };

	EXPECT_EQ(expected, score);
}


TEST(ScoreCalculator, Score_10_5_4_Strike) {

	vector<int> frames{ 10, 5, 4 };

	vector<int> score = ScoreCalculator::score(frames);

	vector<int> expected{ 19, 9 };

	EXPECT_EQ(expected, score);
}

