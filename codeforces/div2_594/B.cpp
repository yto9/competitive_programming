#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n; cin >> n;
    priority_queue<ll> pq;
    REP(i,n) {
        ll tmp; cin >> tmp;
        pq.push(tmp);
    }
    ll s = pq.size() / 2 + (pq.size() % 2);
    ll res_x = 0;
    REP(i,s) {
        ll t = pq.top(); pq.pop();
        res_x += t;
    }
    ll res_y = 0;
    while (!pq.empty()){
        ll t = pq.top(); pq.pop();
        res_y += t;
    }
    cout << res_x * res_x + res_y * res_y << endl;
    return 0;
}
