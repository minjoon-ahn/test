#include <iostream>
#include <string>
using namespace std;

struct GuessResult{
	int strike = 0;
	int ball = 0;
};

class Baseball {
public:
	void SetQuestion(const string& str) {
		if (!isValidInput(str)) {
			throw invalid_argument("Invalid input");
		}
		q = str;
	}

	GuessResult guess(const string& str) {
		if (!isValidInput(str)) {
			throw invalid_argument("Invalid input");
		}
		// compare q and str
		GuessResult result;
		for (int i = 0; i < 3; i++) {
			if (q[i] == str[i]) {
				result.strike++;
			}
			else if (q.find(str[i]) != string::npos) {
				result.ball++;
			}
		}
		return result;

	}
private:
	string q;
	bool isValidInput(const string& str) {

		if (str.length() != 3) {
			cout << "Invalid input" << endl;
			return false;
		}

		for (int i = 0; i < 3; i++) {
			if (str[i] < '0' || str[i] > '9') {
				cout << "Invalid input" << endl;
				return false;
			}
		}
		return true;
	}

};