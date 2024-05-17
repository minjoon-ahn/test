#include <iostream>
#include <string>
using namespace std;

class Baseball {
public:
	void guess(const string& str) {
		if (!isValidInput(str)) {
			throw invalid_argument("Invalid input");
		}
	}
private:
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