#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    map<ll, ll> mpA;
    REP(i, N - 1) {
        ll tmp; cin >> tmp;
        mpA[tmp]++;
    }
    for (int i = 1; i <= N; i++) {
        cout << mpA[i] << endl;
    }
    return 0;
}
