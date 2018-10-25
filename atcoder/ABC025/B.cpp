#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N, A, B; cin >> N >> A >> B;
    int dest = 0;
    REP(i, N) {
        string s; cin >> s;
        int d; cin >> d;
        if (d < A) d = A;
        else if (B < d) d = B;
        if (s == "West") dest += d;
        else if (s == "East") dest -= d;
    }
    if (dest > 0) cout << "West " << dest << endl;
    else if (dest < 0) cout << "East " << -dest << endl;
    else cout << 0 << endl;
    return 0;
}
