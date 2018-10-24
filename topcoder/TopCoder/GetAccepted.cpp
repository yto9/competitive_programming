// BEGIN CUT HERE

// END CUT HERE
#line 5 "GetAccepted.cpp"
#include <string>
#include <vector>

using namespace std;
class GetAccepted {
	public:
	string answer(string question) {
		int num_of_space = 0;
		for (auto c: question) {
			if (c == ' ') num_of_space++;
		}
		if (num_of_space % 2) return "True.";
		else return "False.";
	}
};
