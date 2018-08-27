#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int A; cin >> A;
    int res = 0;
    REP(i, A) {
        res = max(res, i * (A - i));
    }
    cout << res << endl;
    return 0;
}
