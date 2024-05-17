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
			return; // ���ܰ� �߻��ϸ� �׽�Ʈ�� ����
		}
		FAIL() << "Expected: Invalid input"; // ���ܰ� �߻����� ������ �׽�Ʈ ����
	}
};
TEST_F(BaseballFixture, IllegalInput) {
	assertIllegalInput("1234");
	assertIllegalInput("12a");
	assertIllegalInput("abc");
}