#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    map<int, int> mp;
    int N; cin >> N;
    REP(i, N) {
        int tmp; cin >> tmp;
        mp[tmp]++;
    }
    if (mp.size() == N) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
