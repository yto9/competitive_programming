//損小利大で考えるとボラティリティが高いところで如何にトレード出来るか <- coin　と タガログを両方持っているべき？
// 出現頻度からPを類推すべき？そして多い側に寄せておくべき？
// ドルコスト平均法的に半々に寄せる?
// y < 0.999x なら交換する意味ある
// 1/2000のfee(spread)がどの程度のものなのか検証*0.9995
// coinに戻せなかったら悲劇笑
// Z自体は10を中心に対称な分布になるはず(i-> N =>10に収束するはず)
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define EPS 1e-10
typedef long long ll;

bool judge_collect(int rest, int buy, int sell, double tugreks) {
    double expect_Y = (1+100)/2;
    int needs =  tugreks / rest + 1;
    double urenai = ((double) sell)/(buy+sell);
    while(urenai > EPS && rest > 0) {
        urenai *= urenai;
        rest--;
    }
    if (rest == 0) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    int T; cin >> T;
    REP(test, T) {
        int N; cin >> N;
        double coins = 10;
        double tugreks = 0;
        int freq[3] = {0};
        REP(i, N) {
            double th = max(30.0/i,0.005);
            int t;
            double Y, Z;
            cin >> t >> Y >> Z;
            if (i < 30) {
                if (t == 2) {
                    int pos = min(Y,(coins - tugreks)/2);
                    cout << pos << endl;
                    coins -= pos;
                    tugreks += pos * 0.9995;
                    continue;
                }
            }
            if (N-i < 75) {//終盤はとりあえずtugreksを残さないこと優先
                if (judge_collect(N-i, freq[1], freq[2], tugreks)) {
                    if (t == 1) {
                        cout << min(Y,tugreks) << endl;
                        tugreks -= min(Y,tugreks);
                    }
                    continue;
                }
            }
            double postion = 0;
            if (t == 1) {// tugreks -> coins
                if (Z < 10 - th) {
                    postion = max(Y, tugreks);
                }
                coins += postion * (1-0.0005);
                tugreks -= postion; 
            }
            else if (t == 2) {// coins -> tugreks
                if (Z > 10 + th) {
                    postion = max(Y, coins);
                }
                tugreks += postion * (1-0.0005);
                coins -= postion;
            }
            freq[t]++;
            cout << 0 << endl;
        }
    }
    return 0;
}
