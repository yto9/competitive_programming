#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> pii;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pii> v[16];
    REP(i, N) {
        int tmp; cin >> tmp;
        REP(j, tmp) {
            int x,y; cin >> x >> y;
            v[i].push_back(make_pair(x-1, y));
        }
    }
    int res = 0;
    REP(i, 1 << N) {
        bool flag = true;
        int cnt = 0;
        REP(j, N) {
            flag = true;
            if (i >> j & 1) { //j番目が正直者の場合
                for(auto x: v[j]) {
                    if((i >> x.first) % 2 == 1){ 
                        if (x.second == 1) continue;
                        else {
                            flag = false;
                            break;
                        }
                    }//この集合にたいして正しい証言になっている
                    else {
                        if (x.second == 0) continue;
                        else {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) cnt++;
                else break;
            }
        }
        if (flag) {
            res = max(res, cnt);
            cerr << i <<":true:" << cnt << endl;
        }
        else {
            cerr << i << ":false" << endl;
        }

    }
    cout << res << endl;
    return 0;
}
