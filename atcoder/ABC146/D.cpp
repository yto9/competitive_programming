#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> pii;
int res[100000];
vector<pii> v_e[100001];//隣の頂点、辺番号

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    map<int,int> mp_v;// 頂点、次数
    REP(i, N-1) {
        pii tmp; cin >> tmp.first >> tmp.second;
        v_e[tmp.first].push_back(make_pair(tmp.second,i+1));
        v_e[tmp.second].push_back(make_pair(tmp.first,i+1));
        mp_v[tmp.first]++;
        mp_v[tmp.second]++;
    }
    REP(i,N){
        res[i] = 0;
    }
    priority_queue<pii> pq; // 次数、頂点
    REP(i,N){
        pii ver_x;
        ver_x.first = mp_v[i+1];
        ver_x.second = i+1;
        pq.push(ver_x);
    }
    auto to = pq.top();
    int K = to.first;
    while(!pq.empty()){
        pii p = pq.top();pq.pop();
        int cur_to = K;
        vector<int> used;
        for (auto x:v_e[p.second]){//その頂点における辺たち
            if(res[x.second] != 0) {//既に使われているものを集める
                used.push_back(res[x.second]);
            }         
        }
        for(auto x:v_e[p.second]){
            if(res[x.second] == 0) {
                for(int co = cur_to; co > 0; co--){
                    auto resul = find(used.begin(),used.end(),co);
                    if (resul == used.end()) {
                        res[x.second] = co;//色付け
                        used.push_back(co);
                        cur_to = --co;
                        break;
                    }
                }
            }
        }
    }
    cout << K << endl;
    for(int i = 1; i < N; i++){
        cout << res[i] << endl;
    }
    return 0;
}
