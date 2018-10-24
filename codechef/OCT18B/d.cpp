// HMAPPY
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> C;

bool solve(ll cost, ll M, vector<ll> &a, vector<ll> &b, vector<pair<ll,int>> &v) {// shouldn't copy large vector
    auto lb = lower_bound(v.begin(), v.end(), make_pair(cost + 1,-1)); // if ai*bi <= cost then no need to give candy
    for (auto itr = lb; itr != v.end(); itr++) {
        auto x = *itr;
        M -= (x.first - cost)/b[x.second] + (((x.first - cost)%b[x.second])!=0); // assert cost >= 0
        if (M < 0) return false;
    }
    return true;

}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> a(N);
    vector<ll> b(N);
    vector<pair<ll, int>> v(N); // ai*bi, i 
    REP(i, N) {
        cin >> a[i];
    }
    REP(i, N) {
        cin >> b[i];
        v[i] = make_pair(a[i]*b[i],i);
    }
    sort(v.begin(),v.end());
    ll l = -1; // (l, r]
    ll r = (ll)1e18;
    while(r - l > 1) {
        ll pivot = l + (r - l) / 2;
        if (solve(pivot, M, a, b, v)) r = pivot;
        else l = pivot;
    }
    cout << r << endl;
    return 0;
}
