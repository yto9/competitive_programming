#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll res = 0;
    REP(i, N + 1){
        if (i % 3 == 0) continue;
        if (i % 5 == 0) continue;
        res += i;
    }
    cout << res << endl;
    return 0;
}
