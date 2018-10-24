#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    ll res = 0;
    REP(i,n) {
        int a;
        cin >> a;
        while (a%2 == 0) {
            res++;
            a /= 2;
        }
    }
    cout << res << '\n';
    return 0;
}
