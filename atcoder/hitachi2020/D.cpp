#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, T; cin >> N >> T;
    map<ll, priority_queue<ll, vector<ll>, greater<ll>>> mp; //key順
    REP(i, N) {
        ll a, b; cin >> a >> b;
        mp[a].push(b);
    }
    map<ll, ll> a0_mp; //  start_time, waiting_time
    ll last_start_time = T;
    while (!mp[0].empty()) {
        ll b = mp[0].top(); mp[0].pop();
        a0_mp[last_start_time - b]= b;
        last_start_time -= b;
    }
    ll cur_t = 1;
    ll ans = 0;
    while (cur_t < T) {
        ll waiting_time = T; // Tは取り敢えず無理
        ll mp_key = -1;// pq管理用
        //貪欲
        for(auto m: mp) {// ちょっと計算量が気になるが、そもそも回れる回数的に行けるのでは
            if (m.first == 0) continue; // a_i == 0 は後回し
            if (m.first * cur_t + m.second.top() <= waiting_time) { // `<=`が重要
                waiting_time = m.first * cur_t + m.second.top();
                mp_key = m.first;
            }
        }
        //a_i == 0との照合
        if (!a0_mp.empty()) {
            auto itr = a0_mp.lower_bound(cur_t);
            if (itr->second <= waiting_time) { // 今後はa0のみ
                while (itr->first < cur_t){
                    itr++;
                }
                ans += distance(itr, a0_mp.end());
                cout << ans << endl;
                return 0;
            }
            else if(cur_t + waiting_time <= T) {
                ans++;
                cur_t += waiting_time;
                mp[mp_key].pop();
                if (mp[mp_key].empty()) mp.erase(mp_key);
            }
            else {
                break;
            }
        }
        else {
            if(cur_t + waiting_time <= T) {
                ans++;
                cur_t += waiting_time;
                mp[mp_key].pop();
                if (mp[mp_key].empty()) mp.erase(mp_key);
            }
            else {
                break;
            }
        }
        cur_t++; //次の店へ
    }
    cout << ans << endl;
    return 0;
}
