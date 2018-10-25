#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N,K;
    cin >> N >> K;
    int res = (int)(N%K!=0);
    cout << res << "\n";
    return 0;
}
