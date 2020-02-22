#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll A, B, K; cin >> A >> B >> K;
    cout << max(0LL, A-K) << " " << max(0LL, B - max(K-A,0LL)) << endl;
    return 0;
}
