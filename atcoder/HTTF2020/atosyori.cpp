#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef pair<int,int> point;
int N;
char field[40][40];
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
int D = 44;//goalからの枝の分裂数
int turn = 300;//robotの死なない保証ターン数(ちょっとウソ)
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
        // m_res[make_pair(cur_p.first,cur_p.second)] = m_inv[direction];
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

int dfs(point start, char dir, int depth) { //一直線に進んでgoal可能なら1000とか？死んだら-にしたいところ
    if (depth > D) return depth;
    point next;
    next.first = (start.first + N + m_delta[dir].first ) % N;
    next.second = (start.second + N + m_delta[dir].second ) % N;
    char next_f = field[next.first][next.second];
    if (next_f == 'B' || next_f == m_inv[dir]) return 0;
    if (next_f == 'U' || next_f == 'D' || next_f == 'L' || next_f == 'R') {
        return 1000 + depth;
    }
    return dfs(next,dir,depth+1);
}

bool atari(point p){
    int num_blocks = 0;
    REP(i,2) {
        REP(j,2) {
            point diff = m_delta[ud_lr[i][j]];
            point next;
            next.first = (p.first + N + diff.first)%N;
            next.second = (p.second + N + diff.second)%N;
            if (field[next.first][next.second] == 'B') {
                num_blocks++;
            }
        }
    }
    return num_blocks == 3;
}

int bury(){ // 埋めた数を返す
    int res = 0;
    REP(i,N) {
        REP(j,N) {
            if(field[i][j] == 'B') continue;
            if(atari(make_pair(i,j))) {
                res++;
                field[i][j] = 'B';
            }
        }
    }
    return res;
}

// bool hazure(point p) {
//     int income = 0;
//     REP(i,2) {
//         REP(j,2) {
//             point diff = m_delta[ud_lr[i][j]];
//             point next;
//             next.first = (p.first + N + diff.first)%N;
//             next.second = (p.second + N + diff.second)%N;
//             if (field[next.first][next.second] == m_inv[ud_lr[i][j]] || field[next.first][next.second] == '') {
//                 income++;
//             }
//         }
//     }
//     return income == 0;
// }

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int M, B; cin >> N >> M >> B; // N=40, M=100, B=300で固定
    REP(i,N) {
        REP(j,N) {
            field[i][j] = ' ';
        }
    }
    point Gyx; cin >> Gyx.first >> Gyx.second;
    field[Gyx.first][Gyx.second] = 'G';
    queue<point> q_r_p;
    queue<char> q_r_i;
    queue<point> ch_p;
    queue<char> ch_i;

    REP(i,M) {
        point tmp_p;
        char tmp_i;
        cin >> tmp_p.first >> tmp_p.second >> tmp_i;
        q_r_p.push(tmp_p);
        ch_p.push(tmp_p);
        q_r_i.push(tmp_i);
        ch_i.push(tmp_i);
    }
    REP(i,B) {
        point tmp;
        cin >> tmp.first >> tmp.second;
        field[tmp.first][tmp.second] = 'B';
    }
    // fieldの当たりを'B'埋めする
    while(bury()>0);
    // fieldを更新しつつm_resに表札を詰める
    extend(Gyx);
    int cnt = 0;
    // robotがゴールの流れに乗るように頑張る
    while(!q_r_p.empty() && cnt < M*turn){
        point cur_r_p = q_r_p.front(); q_r_p.pop();
        char cur_r_i = q_r_i.front(); q_r_i.pop();
        point next_r_p;
        char next_r_i = cur_r_i;
        char cur_f = field[cur_r_p.first][cur_r_p.second];
        if (cur_f == 'U' || cur_f == 'D' || cur_f == 'L' || cur_f == 'R') {
            next_r_i = cur_f;
        }
        next_r_p.first = (cur_r_p.first + N + m_delta[next_r_i].first ) % N;
        next_r_p.second = (cur_r_p.second + N + m_delta[next_r_i].second ) % N;
        char next_f = field[next_r_p.first][next_r_p.second];
        if (next_f == 'B') {
            int great_option = 0;
            int option[2];
            REP(i,2) {
                option[i] = dfs(cur_r_p,ud_lr[m_ud_lr_idx[cur_r_i]][i],1);
            }
            if (option[0] <= option[1]) great_option = 1; 
            char change_d = ud_lr[m_ud_lr_idx[cur_r_i]][great_option]; // ここのロジック(座圧とかのほうがいいんだろうな。。。)
            field[cur_r_p.first][cur_r_p.second] = change_d;
            // m_res[make_pair(cur_r_p.first,cur_r_p.second)] = change_d;
            q_r_p.push(cur_r_p);
            q_r_i.push(change_d);
        }
        else if (next_f == 'U' || next_f == 'D' || next_f == 'L' || next_f == 'R') {
            ;
        } 
        else { //ただ進む
            q_r_p.push(next_r_p);
            q_r_i.push(next_r_i);
        }
        cnt++;
    }
    // 方向転換に実際に使われた矢印を記録する
    int valid_sign[40][40];
    REP(i, N) {
        REP(j, N) {
            valid_sign[i][j] = 0;
        }
    }
    valid_sign[Gyx.first][Gyx.second] = 1;
    // dfsだと1024が上限っぽいのでbfsにしてみる
    int loop_cnt = 0;
    while (!ch_p.empty() && loop_cnt < 10000) { //goalしてないrobotがいると落ちる(終わらない)と思う -> まだ死んでるケースがある。。。
        loop_cnt++;
        point cur_p = ch_p.front();ch_p.pop();
        char cur_i = ch_i.front();ch_i.pop();
        if (valid_sign[cur_p.first][cur_p.second] > 0) continue;//以降は同じ動き
        char next_i = cur_i;
        char cur_f = field[cur_p.first][cur_p.second];
        if (cur_f == 'U'|| cur_f == 'D' || cur_f == 'L' || cur_f == 'R') {
            if (cur_f != cur_i) {
                next_i = cur_f;
                valid_sign[cur_p.first][cur_p.second]++;
            }
        }
        point next_p;
        next_p.first = (cur_p.first + N + m_delta[next_i].first ) % N;
        next_p.second = (cur_p.second + N + m_delta[next_i].second ) % N;
        if (valid_sign[next_p.first][next_p.second] > 0) continue;
        ch_p.push(next_p);
        ch_i.push(next_i);
    }
    
    
    //　残った矢印を数える
    REP(i, N) {
        REP(j, N) {
            if (field[i][j] == 'U' || field[i][j] == 'D' ||field[i][j] == 'L' ||field[i][j] == 'R') { // 'G'が弾かれている
                if (valid_sign[i][j] > 0) {
                    m_res[make_pair(i,j)] = field[i][j];
                }
            }
        }
    }
    cout << m_res.size() << endl;
    for (auto x: m_res) {
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    return 0;
}
