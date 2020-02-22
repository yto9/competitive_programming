#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll H, N; cin >> H >> N;
    ll sum = 0;
    REP(i, N) {
        ll tmp; cin >> tmp;
        sum += tmp;
    }
    if (sum >= H) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
