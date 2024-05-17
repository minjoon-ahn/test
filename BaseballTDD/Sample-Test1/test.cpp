#include "pch.h"
#include "../BaseballTDD/baseball.cpp"

class BaseballFixture : public ::testing::Test {
public:

	Baseball baseball;

	void assertIllegalInput(const string& str) {
		try {
			baseball.guess(str);
		}
		catch (const invalid_argument& e) {
			return; // 예외가 발생하면 테스트는 성공
		}
		FAIL() << "Expected: Invalid input"; // 예외가 발생하지 않으면 테스트 실패
	}
private:
	string question;
};
TEST_F(BaseballFixture, IllegalInput) {
	assertIllegalInput("1234");
	assertIllegalInput("12a");
	assertIllegalInput("abc");
}

TEST_F(BaseballFixture, NoMatch) {
	baseball.SetQuestion("123");
	auto result = baseball.guess("456");
	ASSERT_EQ(0, result.strike);
	ASSERT_EQ(0, result.ball);
}

TEST_F(BaseballFixture, Strike2) {
	baseball.SetQuestion("123");
	auto result = baseball.guess("124");
	ASSERT_EQ(2, result.strike);
	ASSERT_EQ(0, result.ball);
}


TEST_F(BaseballFixture, Strike1Ball2) {
	baseball.SetQuestion("123");
	auto result = baseball.guess("132");
	ASSERT_EQ(1, result.strike);
	ASSERT_EQ(2, result.ball);
}