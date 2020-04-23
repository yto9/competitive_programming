#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
ll cal(vector<int> v1, vector<int> v2, vector<int> v3){
    ll res = 0;
    for (auto x: v1) {
        auto itr = lower_bound(v2.begin(), v2.end(),x+1);
        for (; itr != v2.end(); itr++) {
            int dist1_2 = *itr - x;
            auto itr2 = lower_bound(v3.begin(), v3.end(),*itr + 1);
            for (; itr2 != v3.end(); itr2++) {
                if (dist1_2 == *itr2 - *itr) continue;
                res++;
            } 
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin >> N;
    string S; cin >> S;
    vector<int> r;
    vector<int> g;
    vector<int> b;
    REP(i, N) {
        if (S[i] == 'R') r.push_back(i);
        if (S[i] == 'G') g.push_back(i);
        if (S[i] == 'B') b.push_back(i);
    }
    ll res = 0;
    res += cal(r,g,b);
    res += cal(r,b,g);
    res += cal(g,r,b);
    res += cal(g,b,r);
    res += cal(b,r,g);
    res += cal(b,g,r);
    cout << res << endl;
    return 0;
}
