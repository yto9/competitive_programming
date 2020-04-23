#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    priority_queue<ll, vector<ll>, greater<ll>> pq_a;
    priority_queue<ll, vector<ll>, greater<ll>> pq_b;
    priority_queue<ll, vector<ll>> pq_c;
    REP(i, A) {
        ll tmp; cin >> tmp;
        pq_a.push(tmp);
    }
    REP(i, B) {
        ll tmp; cin >> tmp;
        pq_b.push(tmp);
    }
    REP(i, C) {
        ll tmp; cin >> tmp;
        pq_c.push(tmp);
    }
    // それぞれX個Y個に絞る
    while((ll)pq_a.size()!= X) pq_a.pop();
    while((ll)pq_b.size()!= Y) pq_b.pop();
    //貪欲
    while(!pq_c.empty()) {
        ll min_a = pq_a.top();
        ll min_b = pq_b.top();
        ll max_c = pq_c.top(); pq_c.pop();
        if (min(min_a,min_b) >= max_c) break;
        if (min_a <= min_b) {
            pq_a.pop();
            pq_a.push(max_c);
        }
        else {
            pq_b.pop();
            pq_b.push(max_c);
        }
    }
    ll res = 0;
    while (!pq_a.empty())
    {
        res += pq_a.top();pq_a.pop();
    }
    while (!pq_b.empty())
    {
        res += pq_b.top();pq_b.pop();
    }
    
    
    cout << res << endl;
    return 0;
}
