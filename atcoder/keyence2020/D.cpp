#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> card;
vector<card> cardset;
int N; 


int solve(vector<int> target) {// cardset -> targetでの講義単調増加列構築の最小工数を返す
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto x: target) pq.push(x);
    while (!pq.empty()) {
        int saisyou = pq.top(); pq.pop();
        REP(i, N) {
            if (saisyou == target[i]) {
                target.erase(target.begin()+i);
                res += i; break;
            }
        }
    }
    return res;
}

int dfs(int num_ura, vector<int> saiyou, int depth){//表か裏か選ぶ
    int res = -1;
    if (depth == N) {
        return solve(saiyou);
    }
    if (num_ura == 0) { 
        saiyou.push_back(cardset[depth].first);
        int tmp_res = dfs(num_ura, saiyou, depth+1);
        if (tmp_res >= 0) {
            if (res < 0) {
                res = tmp_res;
            }
            else {
                res = min(res,tmp_res);
            }
        }
    }
    else {
        saiyou.push_back(cardset[depth].first);
        int tmp_res = dfs(num_ura, saiyou, depth+1);
        if (tmp_res >= 0) {
            if (res < 0) {
                res = tmp_res;
            }
            else {
                res = min(res,tmp_res);
            }
        }
        saiyou.pop_back();
        saiyou.push_back(cardset[depth].second);
        tmp_res = dfs(num_ura-1, saiyou, depth+1);
        if (tmp_res >= 0) {
            if (res < 0) {
                res = tmp_res;
            }
            else {
                res = min(res,tmp_res);
            }
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    cin >> N;
    vector<int> omote;
    vector<int> ura;
    REP(i, N) {
        int tmp; cin >> tmp;
        omote.push_back(tmp);
    }
    REP(i, N) {
        int tmp; cin >> tmp;
        ura.push_back(tmp);
    }
    REP(i, N) {
        cardset.push_back(card(omote[i],ura[i]));
    }
    vector<int> saiyou;
    int res = 10000000;
    for (int i = 0; i < N; i+=2) {
        res = min(res,dfs(i,saiyou,0));
    }
    cout << res << endl;
    return 0;
}
