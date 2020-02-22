#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define VERTEX_MAX 401
#define INF 1000000
#define W 500
#define X 4
typedef long long ll;
ll d[VERTEX_MAX][VERTEX_MAX]; //d[s][d] -> s,d間の最短距離を持つ(ワーシャルフロイド)
ll warshall_next[VERTEX_MAX][VERTEX_MAX]; // warshall_next[i][j] -> i-jの最短路におけるiの次の点
void warshall_floyd(){
    REP(k, VERTEX_MAX) {
        REP(i, VERTEX_MAX) {
            REP(j, VERTEX_MAX) {
                ll pre_dij = d[i][j];
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if (pre_dij != d[i][j]){ // 同じなら少しでも多く経由したい
                    warshall_next[i][j] = warshall_next[i][k];
                }
            }
        }
    }
}

ll dst2op(ll src, ll dst){// 最短でsrcからdstに行くときのsrcの次に経由するノードを返す
    if (src == dst ) return -1;
    return warshall_next[src][dst];
}


struct order {
    ll dst;
    ll id;
    ll issued_time;

    bool operator<(order other) const
    {
        return issued_time < other.issued_time;
    }
};

bool kaeritai(ll nearest, ll rest, ll before_load, ll car_pos) {
    if(before_load == 0) return false;
    if(nearest > d[car_pos][1]*3 || rest * X < before_load ) {
        return true;
    }
    return false;
}


ll score(ll t, ll dst, vector<order> v_loads) {
    ll res = 0;
    for (auto x: v_loads) {
        if (x.dst == dst) {
            res += 100000000 - (t - x.issued_time)*(t - x.issued_time);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    //handle input
    bool Tlast = false;
    map<int,order> mv_O;
    REP(i, VERTEX_MAX) {
        REP(j, VERTEX_MAX) {
            d[i][j] = INF;
            if (i == j && i != 0) {
                d[i][j] = 0;
            }
            warshall_next[i][j] = j;
        }
    }
    ll num_V, num_E; cin >> num_V >> num_E;
    REP(i, num_E) {
        ll tmp_u, tmp_v, tmp_d; cin >> tmp_u >> tmp_v >> tmp_d;
        d[tmp_u][tmp_v] = tmp_d;
        d[tmp_v][tmp_u] = tmp_d;
    }
    vector<ll> f;
    f.push_back(0);// 1-indexにしたい
    REP(i, num_V) {
        ll tmp; cin >> tmp;
        f.push_back(tmp);
    }
    //全点対最短経路
    warshall_floyd();
    ll car_pos = 1;
    ll op = -1;
    ll final_goal = -1;
    ll next_dst_d = 0;
    queue<int> q_op;
    vector<order> v_loads;
    ll T; cin >> T;
    ll before_load;
    vector<ll> visted_path[T];//最後のは未到かも
    ll max_score_exec = -1;
    REP(t, T) {
        ll num_O; cin >> num_O;
        REP(i, num_O) {
            order tmp; cin >> tmp.id >> tmp.dst;
            tmp.issued_time = t;
            mv_O.insert(make_pair(tmp.id,tmp));
            before_load++;
        }
        ll num_P; cin >> num_P;
        REP(i, num_P) {//car_pos = 1の時しか入らない
            ll tmp_o_id; cin >> tmp_o_id;
            v_loads.push_back(mv_O[tmp_o_id]);
            before_load = 0;
        }
        // op勘案
        if (car_pos == 1) {
            // どこに行くか判定
            ll min_d = INF;
            ll min_dst = 1;
            ll max_wating = 0;
            ll max_dst = 1;
            for (auto o: v_loads) {
                min_d = min(min_d, d[1][o.dst]);
                if (min_d == d[1][o.dst]) min_dst = o.dst;
                max_wating = max(max_wating, t-o.issued_time);
                if (max_wating == t-o.issued_time) max_dst = o.dst;
            }
            final_goal = min_dst;
            if (!Tlast && max_wating > W) final_goal = max_dst;//(めっちゃ待つ人をいつ回収すべきか？)
            op = dst2op(car_pos ,final_goal);
            if (Tlast && max_score_exec != INF) {//500s未満、状態数はv_loadsのpermutationあるが深さ優先で時間制限とかで切れる？
                ll num_exec = (ll)v_loads.size();
                ll max_score = -1;
                ll T_spart = t;
                REP(exec,num_exec){
                    vector<order> tmp_loads(v_loads.size());
                    copy(v_loads.begin(),v_loads.end(),tmp_loads.begin());
                    t = T_spart;
                    ll cur_score = 0;
                    car_pos = 1;
                    //とりあえず全部を候補に行ってみる
                    visted_path[exec].push_back(v_loads[exec].dst);
                    final_goal = v_loads[exec].dst;
                    op = dst2op(car_pos,final_goal);
                    t += d[car_pos][op];
                    //それ以降は最近に配る
                    for(;t<T;t += d[car_pos][op]){//頂点につく毎に
                        car_pos = op;
                        cur_score += score(t,car_pos,tmp_loads);
                        tmp_loads.erase(remove_if(tmp_loads.begin(),tmp_loads.end(), [&car_pos](order o) { return o.dst == car_pos; }),tmp_loads.end());
                        if (car_pos == final_goal){
                            ll min_d = INF;
                            ll min_dst = 1;
                            for (auto o: tmp_loads) {
                                min_d = min(min_d, d[car_pos][o.dst]);
                                if (min_d == d[car_pos][o.dst]) min_dst = o.dst;
                            }
                            final_goal = min_dst;
                            visted_path[exec].push_back(final_goal);
                        }
                        op = dst2op(car_pos,final_goal);
                    }
                    max_score = max(max_score,cur_score);
                    if (max_score == cur_score) max_score_exec = exec;
                }
                car_pos = 1;
                t = T_spart;
            }
            else {    
                if (op != -1) REP(i,d[car_pos][op]) q_op.push(op);
                next_dst_d = d[car_pos][op];
                if (min_dst == 1) {
                    q_op.push(-1);
                    next_dst_d = 1;
                }
            }
        }
        else if (car_pos > 0) {
            //どこ行くか判定
            if (final_goal == car_pos) {
                //ここを基本的には近いゴールに配達し、帰巣本能が強くなったら帰る感じにする
                ll min_d = INF;
                ll min_dst = 1;
                for (auto o: v_loads) {
                    min_d = min(min_d, d[car_pos][o.dst]);
                    if (min_d == d[car_pos][o.dst]) min_dst = o.dst;
                }
                final_goal = min_dst;
                if (kaeritai(min_d, (ll)v_loads.size(), before_load, car_pos)) final_goal = 1;
                if (!Tlast && T*0.95 < t + d[car_pos][1]) {
                    Tlast = true;
                    final_goal = 1;
                }
                op = dst2op(car_pos,final_goal);
                REP(i, d[car_pos][op]) q_op.push(op);
                next_dst_d = d[car_pos][op];
            }
            else {
                op = dst2op(car_pos,final_goal);
                REP(i, d[car_pos][op]) q_op.push(op);
                next_dst_d = d[car_pos][op];
            }
        }
        else {// エッジ上にいいる
            ;
        }
        
        if (max_score_exec != -1 && max_score_exec != INF) {// spart時の店舗訪れ用
            // Tlast = false; modified
            final_goal = visted_path[max_score_exec][0];
            op = dst2op(car_pos,final_goal);
            REP(i,d[car_pos][op]) q_op.push(op);
            next_dst_d = d[car_pos][op];
            max_score_exec = INF;
        }
        // command出力
        op = q_op.front(); q_op.pop();
        cout << op << endl;
        next_dst_d--;
        if(next_dst_d == 0) {
            if(op !=-1) car_pos = op;
            else {//op==-1
                ;
            }
        }
        else car_pos = -1;
        //
        string verdict; cin >> verdict;
        ll num_A; cin >> num_A;
        REP(i, num_A) {
            ll tmp; cin >> tmp;
            // 荷降ろし
            v_loads.erase(remove_if(v_loads.begin(),v_loads.end(), [&tmp](order o) { return o.id == tmp; }),v_loads.end());
        }
    }
    return 0;
}
