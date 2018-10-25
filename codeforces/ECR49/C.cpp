#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    REP(k, T){
        int n; cin >> n;
        multiset<int> mst;
        REP(i, n) {
            int tmp; cin >> tmp;
            mst.insert(tmp);
        }
        for (auto itr = mst.begin(); itr != mst.end(); itr++) {
            
        }
    }
    return 0;
}
