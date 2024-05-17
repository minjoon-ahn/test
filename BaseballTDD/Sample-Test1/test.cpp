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
};
TEST_F(BaseballFixture, IllegalInput) {
	assertIllegalInput("1234");
	assertIllegalInput("12a");
	assertIllegalInput("abc");
}