#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n,m,d; cin >> n >> m >> d;
    priority_queue<int,vector<int>,greater<int>> a_pq1;
    vector<pair<int,int>> v(n); //min, idx
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    vector<int> ans(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min, day
    int max_day = 1;
    ans[v[0].second] = max_day;
    pq.push(make_pair(v[0].first, max_day));
    for (int i = 1; i < n; i++) {
        pair<int, int> t = pq.top();
        if (t.first + d < v[i].first) {
            ans[v[i].second] = t.second;
            pq.pop();
            pq.push(make_pair(v[i].first, t.second));
        }
        else {
            ans[v[i].second] = ++max_day;
            pq.push(make_pair(v[i].first, max_day));
        }
    }
    cout << max_day << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if(i != n - 1) cout << " ";
        else cout << endl;
    }
    cout.flush();
    return 0;
}
