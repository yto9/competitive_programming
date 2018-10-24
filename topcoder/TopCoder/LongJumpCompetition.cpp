// BEGIN CUT HERE

// END CUT HERE
#line 5 "LongJumpCompetition.cpp"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Struct {
    int bibs;
    int round1_length;
    int round2_length;
	int round3_length;
 
    Struct(int gen_idx, int first_length) {
        bibs = gen_idx;
        round1_length = first_length;
		round2_length = -1;
		round3_length = -1;
    }
 
    bool operator<(const Struct& another) const {
		if (round3_length != another.round3_length) return round3_length > another.round3_length;
		else if (round2_length != another.round2_length) return round2_length > another.round2_length;
        else if (round1_length != another.round1_length) return round1_length > another.round1_length;
		else return another.bibs > bibs;
    }

};
class LongJumpCompetition {
	public:
	vector <int> recoverStandings(vector <int> jumpLengths) {
		vector<Struct> v;
		int N = ((int)jumpLengths.size())/3;
		for (int i = 0; i < N; i++) {
			v.push_back(Struct(N - 1 - i, jumpLengths[i]));
		}
	
		sort(v.rbegin(), v.rend());
	
		for (int j = 0; j < N; j++) {
			v[j].round2_length = (v[j].round1_length < jumpLengths[j+N])? jumpLengths[j+N]: v[j].round1_length;
		}
	
		sort(v.rbegin(), v.rend());
	
		for (int k = 0; k < N; k++) {
			int sum = jumpLengths[k+2*N] + v[k].round2_length + v[k].round1_length;
			int ma = max(jumpLengths[k+2*N],max(v[k].round2_length, v[k].round1_length));
			int mi = min(jumpLengths[k+2*N],min(v[k].round2_length, v[k].round1_length));
			v[k].round3_length = ma;
			v[k].round2_length = sum - ma - mi;
			v[k].round1_length = mi;
		}

		sort(v.begin(), v.end());
	
		vector<int> res(N);
		for (int l = 0; l < N; l++) {
			res[l] = v[l].bibs;
		}
	
		return res;
	}
};
