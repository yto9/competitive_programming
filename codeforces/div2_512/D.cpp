#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> P;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n,m,k; cin >> n >> m >> k;
    ll wh_xy = n*m*2;
    vector<P> p(3);
    if (wh_xy %k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    wh_xy /= k;
    ll wh = n*m;
    cout << "YES" << endl;
    
    p[0] = make_pair(0,0);
    p[1] = make_pair(n,0);
    p[2] = make_pair(0,m);
    P z = make_pair(1,1);
    ll xy = wh - wh_xy;
    ll g = gcd(wh_xy,wh);
    ll A = xy/g;
    vector<ll> v;
    
    if (n > m) {
        for (ll i = min(n,g); i > 0; i--) {
            if (g%i == 0) v.push_back(i); 
        }
        for (int x = min(n,g); )
    }
    else {

    }
    //愚直O(nm)
    // for (int i = 1; i <= m; i++){
    //     for (int j = 1; j <= n; j++) {

    //     }
    // }

    if (wh_xy != wh - z.first*z.second) {
        cout << "NO" << endl;
        return 0;
    }
    REP(i,3) {
        cout << p[i].first << " " << p[i].second << endl;
    } 
    return 0;
}
