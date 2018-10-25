#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, T; cin >> N >> T;
    vector<int> cost;
    REP(i, N) {
        int c, t; cin >> c >> t;
        if (t <= T) cost.push_back(c);
    }
    if(cost.empty()) cout << "TLE" << endl;
    else {
        sort(cost.begin(), cost.end());
        cout << cost[0] << endl;
    }
    return 0;
}
