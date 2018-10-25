#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n;
    ll t;
    cin >> n >> t;
    REP(i, n) {
        ll tmp; cin >> tmp;
    } 
    ll pre = -1;
    vector<ll> v;
    REP(i, n) {
        ll tmp; cin >> tmp;
        if (tmp >= pre) pre = tmp;
        else {
            cout << "No" << endl;
            return 0;
        }
        v.push_back(tmp);
    }
    return 0;
}
