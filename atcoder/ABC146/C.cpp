#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll A, B, X; cin >> A >> B >> X;
    ll N = -1;
    ll target = 1000000000;
    ll keta = 10;
    while(keta >0) {
        if (A*target + B*keta <= X) break;
        keta--;
        target /= 10;
    }
    if (keta == 0) N = 0;
    if (target == 1000000000) N = target;
    else {
        for(ll x = target; x < target*10; x++) {
            if (A*x + B*keta <= X) {
                N = x;
            }
            else break;
        }
    }
    cout << N << endl;
    return 0;
}
