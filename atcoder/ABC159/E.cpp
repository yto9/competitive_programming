#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int H, W, K; cin >> H >> W >> K;
    vector<string> v;
    vector<vector<int>> ruiseki;
    REP(i, H) {
        string s; cin >> s;
        v.push_back(s);
        vector<int> r;
        r.push_back(s[0]-'0');
        for(int j = 1; j < W; j++) {
            r.push_back(r[j-1] + s[j] - '0');
        } 
        ruiseki.push_back(r);
    }
    vector<int> ans;
    REP(i, 1<<H) {//縦の切り方の状態数
        int pre_tate_line = 0;
        int tmp_num_line = 0;
        bool invalid = false;
        REP(j, W) {
            // bitが立っている間の区間を調べる
            ll cur_field = 0;
            int ii = 0;
            int pre_ii = -1;
            while(ii != H) { //1番下までいったら終わり
                cur_field += v[ii][j];
                if (pre_tate_line != 0) cur_field -= v[ii][pre_tate_line];
                if (i >> ii & 1) {
                    if (cur_field > K) {
                        if (pre_tate_line == j) {// 実現不可
                            invalid = true;
                            break;
                        }
                        else { // 見た一個前に縦線をいれる
                            //このブロック再計算
                            for (int k = ii; k > pre_ii; k--) {
                                cur_field -= ruiseki[k][j-1] - ruiseki[k][pre_tate_line];
                            }
                            if (cur_field > K) {//無理
                                invalid = true;
                                break;
                            }
                            pre_tate_line = j - 1;
                            tmp_num_line++;
                        }
                    }
                    cur_field = 0;//横線が入っているのでリセット
                    pre_ii = ii;
                }
                ii++;
            }
            if (invalid) break;
        }
        if (!invalid) {
            REP(l, H){
                if (i >> l & 1)tmp_num_line++;
            }
            ans.push_back(tmp_num_line);
        }
    }
    auto x = min_element(ans.begin(),ans.end());
    cout << ans[distance(ans.begin(),x)] << endl;
    return 0;
}
