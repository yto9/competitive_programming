#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll N, K; cin >> N >> K;
    ll res = 0;
    if (K % 2 == 0) {
        res += (N/(K/2) - N/K) * (N/(K/2) - N/K) * (N/(K/2) - N/K); 
    }
    res += (N/K) * (N/K) * (N/K);
    cout << res << endl;
    return 0;
}
