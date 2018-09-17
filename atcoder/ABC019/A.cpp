#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    multiset<int> mst;
    REP(i, 3) {
        int x; cin >> x;
        mst.insert(x);
    }
    auto itr = mst.begin();
    cout << *++itr << endl;
    return 0;
}
