#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<ll,ll> P; // Ai, idx
ll dfs(priority_queue<P, vector<P>> pq, ll left, ll right) {
    ll res = 0;
    if (pq.empty()) return res;
    P target = pq.top(); pq.pop();



        res = max(
            dfs(pq, left, right -1) + target.first * abs(target.second - right),
            dfs(pq, left + 1, right) + target.first * abs(target.second - left)
        );
    return res;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    priority_queue<P, vector<P>> pq;
    REP(i, N) {
        ll tmp; cin >> tmp;
        pq.push(P(tmp,i));
    }
    cout << dfs(pq, 0, N-1) << endl;
    return 0;
}
