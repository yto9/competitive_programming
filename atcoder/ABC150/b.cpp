#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    string S; cin >> S;
    int cnt = 0;
    REP(i, N) {
        if (S[i] == 'A' && i < N - 2 && S[i+1] == 'B' && S[i+2] == 'C') cnt++; 
    }
    cout << cnt << endl;
    return 0;
}
