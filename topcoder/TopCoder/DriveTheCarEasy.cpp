// BEGIN CUT HERE

// END CUT HERE
#line 5 "DriveTheCarEasy.cpp"
#include <string>
#include <vector>
using namespace std;
class DriveTheCarEasy {
	public:
	long long calculateDistance(int S, int N, vector <int> speed_changes, vector <int> moments) {
		long long v = 0;

		for (int i = 1; i < N; i++) {
			v += speed_changes[i];
			int l;
			if (i != 0) l = moments[i] - moments[i-1];
			else l = moments[i];
		}

	}
};
