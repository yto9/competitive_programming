#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int pre;
    int res = 1;
    int count = 0;
    REP(i, n) {
        int tmp; cin >> tmp;
        if (i == 0) {
            pre = tmp;
            count++;
            continue;
        }
        if (tmp <= 2 * pre) {
            count++;
            pre = tmp;
            continue;
        }
        res = max(res, count);
        pre = tmp;
        count = 1;
    }
    res = max(res, count);
    cout << res << endl;
    return 0;
}
