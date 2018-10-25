// CHSERVE
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int T; cin >> T;
    REP(test, T) {
        ll P1, P2, K; cin >> P1 >> P2 >> K;
        string next = (((P1 + P2) / K) % 2) ? "COOK": "CHEF";
        cout << next << endl; 
    }
    return 0;
}
