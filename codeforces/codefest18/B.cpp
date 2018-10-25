#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll n, s; cin >> n >> s;
    ll m = n/2 + 1;
    ll ns = 0;
    ll res = 0;
    priority_queue<ll> pq1;
    priority_queue<ll,vector<ll>,greater<ll>> pq2;
    REP(i, n) {
        ll tmp; cin >> tmp;
        if (tmp < s) {
            pq1.push(tmp);
        }
        else if (tmp > s) {
            pq2.push(tmp);
        }
        else {
            ns++;
        }
    }
    while(pq1.size() + ns < m || pq2.size() + ns < m) {
        if (pq1.size()> pq2.size()){
            ll t = pq1.top(); pq1.pop();
            res += s - t;
            ns++;
        }
        else {
            ll t = pq2.top(); pq2.pop();
            res += t - s;
            ns++;      
        }
    }
    
    // REP(i, n) {
    //     ll tmp; cin >> tmp;
    //     v.push_back(tmp);
    // }
    // sort(v.begin(),v.end());
    // while(v[m] != s){
    //     res += abs(v[m] - s);
    //     v[m] = s;
    //     sort(v.begin(),v.end());
    // }
    cout << res << endl;
    return 0;
}
