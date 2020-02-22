#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll res = 0;
    if (N%2==0) {
        N /= 2;
        ll d = 5;
        REP(i,25){
            res += N/d;
            d *= 5;
        }
    }
    cout << res << endl;
    return 0;
}
