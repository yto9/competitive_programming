#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
// ll mod_pow(ll x, ll n, ll mod){//x^n % mod
//     if (n == 0)
//         return 1;
//     ll res = mod_pow(x * x % mod, n / 2, mod);
//     if (n & 1)
//         res = res * x % mod;
//     return res;
// }
typedef pair<int,int> p;// idx, josu
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int q; cin >> q;
    vector<p> vl;
    vector<p> vr;
    vector<p> Q;//L,R
    vector<int> ID;
    int L = 0;
    int R = 0;
    REP(i, q) {
        string s; cin >> s;
        int id; cin >> id;
        if (s[0] == 'L') {
            vl.push_back(make_pair(id,L++));
        }
        else if (s[0] == 'R') {
            vr.push_back(make_pair(id,R++));
        }
        else if (s[0] == '?'){
            ID.push_back(id);
            Q.push_back(make_pair(L,R));
        }
        
    }
    sort(vl.begin(),vl.end());
    sort(vr.begin(),vr.end());
    REP(i, (int)Q.size()){
        auto litr = lower_bound(vl.begin(),vl.end(),make_pair(ID[i], 0));
        auto ritr = lower_bound(vr.begin(),vr.end(),make_pair(ID[i], 0));            
        int res;
        if (ritr != vr.end()) {
            p pr = *ritr;
            if (pr.first == ID[i]) res = min((Q[i].second-1) - pr.second, Q[i].first + pr.second);
            else {
                p pl = *litr;
                res = min((Q[i].first-1) - pl.second, Q[i].second + pl.second);
            }
        }
        else {
            p pl = *litr;
            res = min((Q[i].first-1) - pl.second, Q[i].second + pl.second);
        }
        cout << res << endl;
    }
    return 0;
}
