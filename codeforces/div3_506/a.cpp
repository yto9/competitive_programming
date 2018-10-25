#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n, k; cin >> n >> k;
    string t; cin >> t;
    FOR(i, 1, n) {
        REP(j, n - i) {
            if (t[j] != t[i + j]) {
                break;
            }
            if (j == n - i - 1) {
                cout << t;
                REP(m, k - 1) {
                    for (int l = n - i; l < n; l++) {
                        cout << t[l];
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    REP(i, k) {
        cout << t; 
    }
    cout << endl;
    return 0;
}
