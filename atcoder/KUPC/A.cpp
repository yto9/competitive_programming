#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> s(N);
    vector<int> a(N);
    int res = 0;
    REP(i, N) {
        cin >> s[i];
    }
    REP(i, N) {
        cin >> a[i];
    }
    REP(i, N) {
        res = max(res, s[i] * a[i]);
    }
    cout << res << endl;
    return 0;
}
