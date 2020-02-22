#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(int argc, char const *argv[])
{

    COMinit();
    string N; cin >> N;
    int K; cin >> K;
    int keta = N.size();
    ll res = 0;
    if (K==1) {
        res += 9 * (keta - 1);
        res += N[0] - '0';
    }
    else if (K==2) {
        if (keta == 1) res = 0;
        else {
            if (keta >= 3) {
                res += COM(keta-1,K) * 9 * 9; //最上位使わないパターン
            }
            res += (N[0] - '1') * (keta-1) * 9;// 最上位のうち1番大きい値以外を使用した場合
            //最上位のうち1番大きい値を使用した場合
            res += N[1] - '0';
            res += 9 * (keta-2);
        }
    }
    else if (K==3) {
        if (keta < 3) {
            res = 0;
        }
        else {
            // 最上位使わないパターン
            if (keta >= 4) {
                res += COM(keta-1,K) * 9 * 9 * 9;
            }
            // 最上位のうち1番大きい値以外を使用した場合
            res += (N[0] - '1') * COM(keta-1, 2) * 9 * 9;
            //最上位のうち1番大きい値を使用した場合
            // 次の0以外のタイミング
            //まだやることあるな。。。
            
        }
    }
    cout << res << endl;
    return 0;
}
