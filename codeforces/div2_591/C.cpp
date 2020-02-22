#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int q; cin >> q;
    REP(i, q) {
        int n; cin >> n;
        priority_queue<ll,vector<ll>> h_l_q;
        vector<pair<ll,ll>> pro;
        ll k;
        REP(j, n) {
            ll tmp;
            cin >> tmp;
            h_l_q.push(tmp);
        }
        REP(t, 2) {
            ll per, nd; cin >> per >> nd;
            pro.push_back(make_pair(per,nd));
        }
        sort(pro.begin(),pro.end());
        cin >> k;
        priority_queue<ll,vector<ll>> La;
        priority_queue<ll,vector<ll>> Sa;
        La.push(0);
        Sa.push(0);
        for(int ans = 1; ans <= n; ans++) {
            ll cur = h_l_q.top(); 
            if(ans % pro[0].second == 0 && ans % pro[1].second == 0) {
                h_l_q.pop();
                Sa.push(cur);
                ll s_to_l = Sa.top(); Sa.pop();
                La.push(s_to_l);
                ll to_both = La.top(); La.pop();
                k += (s_to_l - cur) * pro[0].first / 100;
                k += (to_both - s_to_l) * pro[1].first / 100;
                k -= to_both * (pro[0].first + pro[1].first) / 100;
            }
            else if(ans % pro[0].second == 0) {
                h_l_q.pop();
                Sa.push(cur);
                k -= cur * pro[0].first / 100;
            }
            else if(ans % pro[1].second == 0) {
                h_l_q.pop();
                Sa.push(cur);
                ll s_to_l = Sa.top(); Sa.pop();
                La.push(s_to_l);
                k += (s_to_l - cur) * pro[0].first / 100;
                k -= s_to_l * pro[1].first / 100;
            }
            if (k <= 0) {
                cout << ans << endl;
                break;
            }
            else if(ans == n) {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
