#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

#define MOD 10007
int memo[1000001] = {};//0-initialized
int tri(int n) {
    if (n <= 3 || memo[n] > 0) return memo[n];
    return memo[n] = (tri(n - 3) + tri(n - 2) + tri(n - 1))%MOD;
}
int main(int argc, char const *argv[])
{
    int n; cin >> n;
    memo[3] = 1;
    cout << tri(n) << endl;
    return 0;
}
