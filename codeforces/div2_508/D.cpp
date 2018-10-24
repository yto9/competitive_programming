#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n; cin >> n;
    vector<ll> v(n);
    bool z = false;
    REP(i, n) {
        cin >> v[i];
        if(v[i] == 0) z = true;
    }
    auto it_max = *max_element(v.begin(),v.end());
    auto it_min = *min_element(v.begin(),v.end());
    ll sum = 0;
    REP(i,n) {
        sum += abs(v[i]);
    }
    if (n == 1) {
        sum = v[0];
    }
    else if (it_max * it_min < 0 || z ) {
        ;
    }
    else {
        if(v[0] < 0) sum -= abs(it_max) * 2;
        else sum -= abs(it_min) * 2;
    }
    cout << sum << endl;
    return 0;
}
