#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, x; cin >> N >> x;
    vector<int> v(N);
    int res = 0;
    REP(i, N) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    REP(i, N) {
        x -= v[i];
        if (x >= 0) {
            res++;
            if (i == N-1 && x > 0) res--;
        }
        else break;
    }
    cout << res << endl;
    return 0;
}
