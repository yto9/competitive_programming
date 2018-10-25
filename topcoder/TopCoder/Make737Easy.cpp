// BEGIN CUT HERE

// END CUT HERE
#line 5 "Make737Easy.cpp"
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Make737Easy {
	public:
	int count(string S) {
		int res = 0;
		int N = (int)S.size();
		int s3[400] = {};
		// int s7[N] = {};
		vector<int> i7;
		if (S[0] == '3') s3[0] = 1;
		else if (S[0] == '7') i7.push_back(0);
		for (int i = 1; i < N; i++) {
			if (S[i] == '3') s3[i]+=s3[i-1] +1;
			else if (S[i] == '7') {
				s3[i] = s3[i-1];
				i7.push_back(i);
			}
		}
		for (int i = 0; i < (int)i7.size(); i++) {
			for (int j = i + 1; j < (int)i7.size(); j++) {
				res += s3[i7[j]] - s3[i7[i]];
			}
		}
		return res;
	}
};


int main(int argc, char const *argv[])
{
    Make737Easy m737e;
    string s;
	cin >> s;
    // cin >> truckVariable;
    // vector<int> warehouseX = getVector();
    // vector<int> warehouseY = getVector();
    // vector<int> warehouseItem = getVector();
    // vector<int> warehouseQuantity = getVector();
    // vector<int> customerX = getVector();
    // vector<int> customerY = getVector();
    // vector<int> customerItem = getVector();
    // vector<string> ret = tac.planShipping(truckFixed, truckVariable, warehouseX, warehouseY,
                            //  warehouseItem, warehouseQuantity, customerX, customerY, customerItem);
	int ret = m737e.count(s);
	cout << ret << endl;
    return 0;
}