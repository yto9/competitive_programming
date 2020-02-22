#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef pair<int,int> point;
int N;
char field[40][40];
map<point,int> m_b;
map<point,char> m_res;
char ud_lr[2][2] = {{'U','D'},{'L','R'}};
map<char,char> m_inv = {
    {'U','D'},
    {'D','U'},
    {'L','R'},
    {'R','L'}
};
map<char,int> m_ud_lr_idx = {
    {'U', 1},
    {'D', 1},
    {'L', 0},
    {'R', 0}
};
map<char, point> m_delta = {
    {'U', make_pair(-1,0)},
    {'D', make_pair(1,0)},
    {'L', make_pair(0,-1)},
    {'R', make_pair(0,1)}
};
int D = 20;//goalからの枝の分裂数
int turn = 10;//robotの死なない保証ターン数
void extend(point goal);
void extend(point goal, char direction, int depth) { // 'B'にぶつかるまでgoalに向かうdirectionの逆向きの矢印を描く depthは'B'にぶつかるので法線に伸びた回数
    if (depth > D) return;
    point cur_p;
    cur_p.first = (goal.first + N + m_delta[direction].first ) % N;
    cur_p.second = (goal.second + N + m_delta[direction].second ) % N;
    char cur = field[cur_p.first][cur_p.second];
    if (cur == 'B') {
        REP(i,2) {
            extend(goal,ud_lr[m_ud_lr_idx[direction]][i],depth+1);
        }
        return;
    }
    if (cur == direction || cur == m_inv[direction]) return;
    if (cur == 'U' || cur == 'D' || cur == 'L' || cur == 'R'){
        ;
    }
    else{
        field[cur_p.first][cur_p.second] = m_inv[direction];
        m_res[make_pair(cur_p.first,cur_p.second)] = m_inv[direction];
    }
    return extend(cur_p, direction, depth);
}

void extend(point goal) { // goalに向かう上下左右の矢印を描く
    char dest = field[goal.first][goal.second];
    if (dest == 'G' || dest == 'U' || dest == 'D' || dest == 'L' || dest == 'R') {
        REP(i,2) {
            REP(j,2) {
                extend(goal, ud_lr[i][j],0);
            }
        }
    }
    return;
}




int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int M, B; cin >> N >> M >> B; // N=40, M=100, B=300で固定
    point Gyx; cin >> Gyx.first >> Gyx.second;
    field[Gyx.first][Gyx.second] = 'G';
    vector<point> r_p(M);
    vector<char> r_i(M);
    REP(i,M) {
        cin >> r_p[i].first >> r_p[i].second >> r_i[i];
    }
    REP(i,B) {
        point tmp;
        cin >> tmp.first >> tmp.second;
        m_b[tmp] = 0;
        field[tmp.first][tmp.second] = 'B';
    }
    // fieldを更新しつつm_resに表札を詰める
    extend(Gyx);
    
    cout << m_res.size() << endl;
    for (auto x: m_res) {
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    return 0;
}
