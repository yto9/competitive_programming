#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n,L,a; cin >> n >> L >> a;
    int pre = 0;
    int res = 0;
    REP(i, n) {
        int st, length; cin >> st >> length;
        res += (st - pre) / a;
        pre = st + length;
    }
    res += (L - pre) / a;
    cout << res << endl;
    return 0;
}
