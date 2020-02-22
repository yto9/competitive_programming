#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N, M, V, P; cin >> N >> M >> V >> P;
    vector<ll> vll;
    REP(i, N) {
        ll tmp; cin >> tmp;
        vll.push_back(tmp);
    }
    sort(vll.begin(), vll.end(), greater<ll>());
    ll lb = -1, ub = N;
    while (ub - lb > 1) {//クリアできたらそれより元の配点が大きいものは全部可能性がある <-二分探索
        ll target_idx = (lb + ub) / 2;
        ll boader_value = vll[P-1];
        ll rest = M * V;
        ll target_value = vll[target_idx];
        //targetへは全員投票
        target_value += M; rest -= M;
        if (rest <= 0 && boader_value <= target_value) {
            lb = target_idx;
            continue;
        }
        //あとはboaderを出来るだけ上げないように
        //boaderが上がらない安牌
        rest -= M * ((P-1) + (N-1 - target_idx));
        if (rest <= 0 && boader_value <= target_value) {
            lb = target_idx;
            continue;
        }
        if (boader_value > target_value) {
            ub = target_idx;
            continue;
        }
        //boaderも上がるがターゲットに比べれば薄められる操作
        vector<ll> boader2target_v(target_idx-(P-1));
        copy(vll.begin()+P-1,vll.begin()+target_idx,boader2target_v.begin());
        ll sukima = 0;
        for(auto x: boader2target_v) {
            sukima+=x;
        }
        sukima += rest;
        if (sukima > target_value * (target_idx - (P-1))) ub = target_idx;
        else lb = target_idx;
    }
    
    cout << ub << endl;
    return 0;
}
