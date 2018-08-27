#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    string S;
    int N;
    cin >> S;
    cin >> N;
    string cand[25];
    REP(i, 5) {
        REP(j, 5) {
            cand[i * 5 + j] = S[i];
            cand[i * 5 + j] += S[j];
        }
    }
    cout << cand[N - 1] << endl;
    return 0;
}
