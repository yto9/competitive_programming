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
    REP(i, (int)S.size()) {
        S[i] = 'A' + (S[i] - 'A' + N) % 26;
    }
    cout << S << endl;
    return 0;
}
