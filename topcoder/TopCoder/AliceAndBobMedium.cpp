// BEGIN CUT HERE

// END CUT HERE
#line 5 "AliceAndBobMedium.cpp"
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
class AliceAndBobMedium {
	public:
	int count(vector <int> a) {
		int N = (int)a.size();
		int res = 0;
		int x = 0;
		for (int i = 0; i < N; i++) x ^= a[i];
		if (x == 0) return 0;
		else {
			for (auto num: a) {
				if (x < num) {
					res++;
				}
			}
			return res;
		}
	}
};

vector<int> getVector() {
    int size; cin >> size;
    vector<int> v(size); 
    for (int i = 0; i < size ; i++) {
        cin >> v[i];
    }
    return v;
}

int main(int argc, char const *argv[])
{
    // TrucksAndCouriers tac;
	AliceAndBobMedium aabm;
    vector<int> a = getVector();
	int ret = aabm.count(a);
    // vector<string> ret = tac.planShipping(truckFixed, truckVariable, warehouseX, warehouseY,
                            //  warehouseItem, warehouseQuantity, customerX, customerY, customerItem);
    cout << ret << endl;
    return 0;
}