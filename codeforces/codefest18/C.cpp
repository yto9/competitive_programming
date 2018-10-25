#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    int res = 0;
    int pre = 0;
    REP(i,n) {
        if (pre == 1 && a[i]!= a[i-1] && a[i]!= b[i]) {
            pre = 0;
            continue;
        }
        if (a[i] != b[i]) {
            res++;
            pre = 1;
        }
        else pre = 0;
    }
    cout << res << endl;
    return 0;
}
