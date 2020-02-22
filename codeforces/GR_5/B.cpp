#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<vector<int>> idx(n+1);
    priority_queue<pair<int,int>> pq_in;
    REP(i,n) {
        int tmp; cin >> tmp;
        idx[tmp].push_back(i);
    }
    REP(i,n) {
        int tmp; cin >> tmp;
        pq_in.push(make_pair(idx[tmp][0],i));
    }
    int res = 0;
    priority_queue<int,vector<int>,greater<int>> pq_ex;
    while(!pq_in.empty()){
        pair<int,int> p = pq_in.top();pq_in.pop();
        while (!pq_ex.empty()) {
            int exp = pq_ex.top();pq_ex.pop();
            if (exp < p.second) {
                res++;
            }
            else {
                pq_ex.push(exp);
                break;
            }
        }
        pq_ex.push(p.second);
    }
    cout << res << endl;

    return 0;
}
