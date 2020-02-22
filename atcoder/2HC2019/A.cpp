#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define VERTEX_MAX 401
#define INF 1000000
#define W 500
#define X 4
#define DUP 1000
#define POSSIBLE_MAX_EXEC 70
#define UNREACH_EXEC 20
typedef long long ll;
typedef pair<ll,ll> pii;//  t,dst_idx

struct order {
    ll dst;
    ll id;
    ll issued_time;

    bool operator<(order other) const
    {
        return issued_time < other.issued_time;
    }
};
ll d[POSSIBLE_MAX_EXEC][VERTEX_MAX][VERTEX_MAX]; //d[s][d] -> s,d間の最短距離を持つ(ワーシャルフロイド)
ll warshall_next[POSSIBLE_MAX_EXEC][VERTEX_MAX][VERTEX_MAX]; // warshall_next[i][j] -> i-jの最短路におけるiの次の点
void warshall_floyd(int idx){
    REP(k, VERTEX_MAX) {
        REP(i, VERTEX_MAX) {
            REP(j, VERTEX_MAX) {
                ll pre_dij = d[idx][i][j];
                d[idx][i][j] = min(d[idx][i][j], d[idx][i][k] + d[idx][k][j]);
                if (pre_dij != d[idx][i][j]){ // 同じなら少しでも多く経由したい
                    warshall_next[idx][i][j] = warshall_next[idx][i][k];
                }
            }
        }
    }
}

ll dst2op(ll src, ll dst, int idx){// 最短でsrcからdstに行くときのsrcの次に経由するノードを返す
    if (src == dst ) return -1;
    return warshall_next[idx][src][dst];
}

bool kaeritai(ll nearest, ll rest, ll before_load, ll car_pos, int idx) {
    if(before_load == 0) return false;
    if(nearest > d[idx][car_pos][1]*X || rest * X < before_load ) {
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
    vector<order> v_O;// dst, issued_time
    map<int,ll> m_last_issued_time;
    vector<vector<ll>> sealed_node;
    vector<order> priority_dst;
    vector<ll> tmp_v;
    tmp_v.push_back(0);
    sealed_node.push_back(tmp_v);
    // ワーシャルフロイド法初期化
    REP(idx,POSSIBLE_MAX_EXEC){
        REP(i, VERTEX_MAX) {
            REP(j, VERTEX_MAX) {
                d[idx][i][j] = INF;
                if (i == j && i != 0) {
                    d[idx][i][j] = 0;
                }
                warshall_next[idx][i][j] = j;
            }
        }
    }
    //handle input
    ll num_V, num_E; cin >> num_V >> num_E;
    REP(i, num_E) {
        ll tmp_u, tmp_v, tmp_d; cin >> tmp_u >> tmp_v >> tmp_d;
        REP(idx, POSSIBLE_MAX_EXEC) {
            d[idx][tmp_u][tmp_v] = tmp_d;
            d[idx][tmp_v][tmp_u] = tmp_d;
        }
        vector<ll> emp_v;
        if (tmp_u == 1) {
            emp_v.push_back(tmp_v);
            sealed_node.push_back(emp_v);
        }
        if (tmp_v == 1) {
            emp_v.push_back(tmp_u);
            sealed_node.push_back(emp_v);
        }
    }
    ll T; cin >> T;
    REP(t, T) {
        ll num_O; cin >> num_O;
        REP(i, num_O) {
            order tmp; cin >> tmp.id >> tmp.dst;
            tmp.issued_time = t;
            v_O.push_back(tmp);
            m_last_issued_time[tmp.dst] = max(m_last_issued_time[tmp.dst],tmp.issued_time);
        }
    }

    auto rm_elm = max_element(v_O.begin(),v_O.end(),[](const order& lhs, const order& rhs){
        return lhs.issued_time < rhs.issued_time;
    });
    int around_shop = (int)sealed_node.size();
    REP(idx, around_shop){
        if (idx == 0) continue;
        vector<ll> tmp;
        for(auto x:sealed_node[idx]){
            tmp.push_back(x);
        }
        tmp.push_back(rm_elm->dst);
        sealed_node.push_back(tmp);
    }

    sort(v_O.begin(),v_O.end(),[](const order& lhs, const order& rhs){
        return lhs.issued_time < rhs.issued_time;
    });
    REP(idx, POSSIBLE_MAX_EXEC - (int)sealed_node.size() - UNREACH_EXEC) {
        vector<ll> tv;
        tv.push_back(v_O[idx].dst);
        sealed_node.push_back(tv);
    }

    REP(idx,(int)sealed_node.size()) {//ないほうが点数が良いが。どうなっているのか。。フルマップで最短路を考えるが、通らないって感じかINFはデカすぎなのかな？
        REP(i,VERTEX_MAX) {
            for (auto x: sealed_node[idx]) {
                d[idx][x][i] = 100;
                d[idx][i][x] = 100;
            }
        }
    }

    //全点対最短経路
    REP(idx,(int) sealed_node.size()) {
        warshall_floyd(idx);
    }
    vector<ll> max_final_goals[POSSIBLE_MAX_EXEC];//op のlist
    ll final_answer = 0;
    ll max_score = 0;
    REP(idx,(int) sealed_node.size()) {
        // handle status
        ll car_pos = 1; // vertex_idx
        bool Tlast = false;
        ll last_store_time = 0;
        // orderを時間昇順に
        sort(v_O.begin(),v_O.end());
        //handle steps
        ll current_total_score = 0;
        ll op = -1;
        auto already_load = v_O.begin();
        vector<order> v_loads;
        ll final_goal = -1;
        ll visted_path[T];//最後のは未到かも
        ll max_score_exec = -1;
        REP(t, T) {
            if (car_pos == 1) { // 店にいる時(たまたま通過しうる)
                last_store_time = t;
                order comp_order = {VERTEX_MAX, 0, t};
                auto res = upper_bound(v_O.begin(), v_O.end(), comp_order);
                // 積み込み
                for (auto itr = already_load; itr != res ;itr++){
                    order o;
                    o.issued_time = itr->issued_time;
                    o.dst = itr->dst;
                    o.id = itr->id;
                    v_loads.push_back(o);
                }
                // どこに行くか判定
                ll min_d = INF;
                ll min_dst = 1;
                for (auto o: v_loads) {
                    if (t < DUP && m_last_issued_time[o.dst] > last_store_time) continue; //いらないかも
                    auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                    if (res != sealed_node[idx].end()) continue;
                    min_d = min(min_d, d[idx][1][o.dst]);
                    if (min_d == d[idx][1][o.dst]) min_dst = o.dst;
                }
                if ((int)v_loads.size()> 0 && min_dst == 1) {
                    for (auto o: v_loads) {
                        auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                        if (res != sealed_node[idx].end()) continue;
                        min_d = min(min_d, d[idx][1][o.dst]);
                        if (min_d == d[idx][1][o.dst]) min_dst = o.dst;
                    }
                }
                final_goal = min_dst;
                op = dst2op(car_pos ,final_goal, idx);
                already_load = res;
                if (Tlast && max_score_exec != INF) {
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
                        visted_path[exec] = v_loads[exec].dst;
                        final_goal = v_loads[exec].dst;
                        op = dst2op(car_pos,final_goal, 0);//これは全グラフ
                        t += d[0][car_pos][op];
                        //それ以降は最近に配る
                        for(;t<T;t += d[0][car_pos][op]){//頂点につく毎に
                            if (op != -1) car_pos = op;
                            cur_score += score(t,car_pos,tmp_loads);
                            tmp_loads.erase(remove_if(tmp_loads.begin(),tmp_loads.end(), [&car_pos](order o) { return o.dst == car_pos; }),tmp_loads.end());
                            if (car_pos == final_goal){
                                ll min_d = INF;
                                ll min_dst = 1;
                                for (auto o: tmp_loads) {
                                    min_d = min(min_d, d[0][car_pos][o.dst]);
                                    if (min_d == d[0][car_pos][o.dst]) min_dst = o.dst;
                                }
                                final_goal = min_dst;
                            }
                            op = dst2op(car_pos,final_goal,0);
                        }
                        max_score = max(max_score,cur_score);
                        if (max_score == cur_score) max_score_exec = exec;
                    }
                    car_pos = 1;
                    t = T_spart;
                }
            }
            else if (car_pos > 0) {// 店以外の頂点にいる時
                // 荷降ろし
                current_total_score += score(t,car_pos,v_loads);
                v_loads.erase(remove_if(v_loads.begin(),v_loads.end(), [&car_pos](order o) { return o.dst == car_pos; }),v_loads.end());
                order comp_order = {VERTEX_MAX, 0, t};
                auto res = upper_bound(v_O.begin(), v_O.end(), comp_order);
                ll before_put = distance(already_load,res);
                //どこ行くか判定
                if (final_goal == car_pos) {
                    //ここを基本的には近いゴールに配達し、帰巣本能が強くなったら帰る感じにする
                    ll min_d = INF;
                    ll min_dst = 1;
                    if(max_score_exec != INF) {
                        for (auto o: v_loads) {
                            if (t < DUP && m_last_issued_time[o.dst] > last_store_time) continue;
                            auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                            if (res != sealed_node[idx].end()) continue;
                            min_d = min(min_d, d[idx][car_pos][o.dst]);
                            if (min_d == d[idx][car_pos][o.dst]) min_dst = o.dst;
                        }
                        if ((int)v_loads.size()> 0 && min_dst == 1) {
                            for (auto o: v_loads) {
                                auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                                if (res != sealed_node[idx].end()) continue;
                                min_d = min(min_d, d[idx][car_pos][o.dst]);
                                if (min_d == d[idx][car_pos][o.dst]) min_dst = o.dst;
                            }      
                        }
                    }
                    else {
                       for (auto o: v_loads) {
                            min_d = min(min_d, d[idx][car_pos][o.dst]);
                            if (min_d == d[idx][car_pos][o.dst]) min_dst = o.dst;
                        }                        
                    }
                    final_goal = min_dst;
                    if (kaeritai(min_d, (ll)v_loads.size(), before_put, car_pos,idx)) final_goal = 1;
                    if (!Tlast && T*0.95 < t + d[idx][car_pos][1]) {
                        Tlast = true;
                        final_goal = 1;
                    }
                    op = dst2op(car_pos,final_goal,idx);
                    if(max_score_exec == INF) op = dst2op(car_pos,final_goal,0);
                }
                else {
                    op = dst2op(car_pos,final_goal,idx);
                    if(max_score_exec == INF) op = dst2op(car_pos,final_goal,0);
                }
            }
            if (max_score_exec != -1 && max_score_exec != INF) {//ラストの入り口
                final_goal = visted_path[max_score_exec];
                op = dst2op(car_pos, final_goal,0);
                max_score_exec = INF;
            }

            if (op == -1) {
                max_final_goals[idx].push_back(op);
            }
            else { // opの示すノードまで進む
                if(max_score_exec == INF ){ //ラストスパートだから全マップ
                    for(ll t_next = t + d[0][car_pos][op]; t<T && t<t_next ;t++) {
                        max_final_goals[idx].push_back(op);
                    }
                }
                else {
                    for(ll t_next = t + d[idx][car_pos][op]; t<T && t<t_next ;t++) {
                        max_final_goals[idx].push_back(op);
                    }
                }
                t--;
                car_pos = op;
            }
        }
        cerr << idx << ":" << current_total_score << endl;
        max_score = max(max_score, current_total_score);
        if (max_score == current_total_score) {
            final_answer = idx;
            priority_dst.clear();
            for(auto x: v_loads) {
                priority_dst.push_back(x);
            }
        }
    }

    ll truely_final_answer = final_answer;
    ll idx = final_answer;
    sort(priority_dst.begin(),priority_dst.end(),[](const order& lhs, const order& rhs){
        return lhs.issued_time < rhs.issued_time;
    });
    int clear;
    //優先探索ゴールあり(通路(idx->final_answerを)
    REP(e, UNREACH_EXEC) {
        // handle status
        ll car_pos = 1; // vertex_idx
        bool Tlast = false;
        clear = 0;
        ll last_store_time = 0;
        // orderを時間昇順に
        sort(v_O.begin(),v_O.end());
        //handle steps
        ll current_total_score = 0;
        ll op = -1;
        auto already_load = v_O.begin();
        vector<order> v_loads;
        ll final_goal = -1;
        ll visted_path[T];//最後のは未到かも
        ll max_score_exec = -1;
        REP(t, T) {
            cerr << t << endl;
            if (car_pos == 1) { // 店にいる時(たまたま通過しうる)
                last_store_time = t;
                order comp_order = {VERTEX_MAX, 0, t};
                auto res = upper_bound(v_O.begin(), v_O.end(), comp_order);
                // 積み込み
                for (auto itr = already_load; itr != res ;itr++){
                    order o;
                    o.issued_time = itr->issued_time;
                    o.dst = itr->dst;
                    o.id = itr->id;
                    v_loads.push_back(o);
                }
                // どこに行くか判定
                ll min_d = INF;
                ll min_dst = 1;
                for (auto o: v_loads) {
                    if (t < DUP && m_last_issued_time[o.dst] > last_store_time) continue; //いらないかも
                    auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                    if (res != sealed_node[idx].end()) continue;
                    min_d = min(min_d, d[idx][1][o.dst]);
                    if (min_d == d[idx][1][o.dst]) min_dst = o.dst;
                }
                if ((int)v_loads.size()> 0 && min_dst == 1) {
                    for (auto o: v_loads) {
                        auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                        if (res != sealed_node[idx].end()) continue;
                        min_d = min(min_d, d[idx][1][o.dst]);
                        if (min_d == d[idx][1][o.dst]) min_dst = o.dst;
                    }
                }
                final_goal = min_dst;
                if (clear <= e && clear < (int)priority_dst.size()) {
                    if (t > priority_dst[clear].issued_time) {
                        final_goal = priority_dst[clear].dst;
                        cerr << clear << ":" << e <<":"<<(int) priority_dst.size() << endl;
                        clear++;
                    }
                }
                op = dst2op(car_pos ,final_goal, idx);
                already_load = res;
                if (Tlast && max_score_exec != INF) {
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
                        visted_path[exec] = v_loads[exec].dst;
                        final_goal = v_loads[exec].dst;
                        op = dst2op(car_pos,final_goal, 0);//これは全グラフ
                        t += d[0][car_pos][op];
                        //それ以降は最近に配る
                        for(;t<T;t += d[0][car_pos][op]){//頂点につく毎に
                            if (op != -1) car_pos = op;
                            cur_score += score(t,car_pos,tmp_loads);
                            tmp_loads.erase(remove_if(tmp_loads.begin(),tmp_loads.end(), [&car_pos](order o) { return o.dst == car_pos; }),tmp_loads.end());
                            if (car_pos == final_goal){
                                ll min_d = INF;
                                ll min_dst = 1;
                                for (auto o: tmp_loads) {
                                    min_d = min(min_d, d[0][car_pos][o.dst]);
                                    if (min_d == d[0][car_pos][o.dst]) min_dst = o.dst;
                                }
                                final_goal = min_dst;
                            }
                            op = dst2op(car_pos,final_goal,0);
                        }
                        max_score = max(max_score,cur_score);
                        if (max_score == cur_score) max_score_exec = exec;
                    }
                    car_pos = 1;
                    t = T_spart;
                }
            }
            else if (car_pos > 0) {// 店以外の頂点にいる時
                // 荷降ろし
                current_total_score += score(t,car_pos,v_loads);
                v_loads.erase(remove_if(v_loads.begin(),v_loads.end(), [&car_pos](order o) { return o.dst == car_pos; }),v_loads.end());
                order comp_order = {VERTEX_MAX, 0, t};
                auto res = upper_bound(v_O.begin(), v_O.end(), comp_order);
                ll before_put = distance(already_load,res);
                //どこ行くか判定
                if (final_goal == car_pos) {
                    //ここを基本的には近いゴールに配達し、帰巣本能が強くなったら帰る感じにする
                    ll min_d = INF;
                    ll min_dst = 1;
                    if(max_score_exec != INF) {
                        for (auto o: v_loads) {
                            if (t < DUP && m_last_issued_time[o.dst] > last_store_time) continue;
                            auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                            if (res != sealed_node[idx].end()) continue;
                            min_d = min(min_d, d[idx][car_pos][o.dst]);
                            if (min_d == d[idx][car_pos][o.dst]) min_dst = o.dst;
                        }
                        if ((int)v_loads.size()> 0 && min_dst == 1) {
                            for (auto o: v_loads) {
                                auto res = find(sealed_node[idx].begin(),sealed_node[idx].end(), o.dst);
                                if (res != sealed_node[idx].end()) continue;
                                min_d = min(min_d, d[idx][car_pos][o.dst]);
                                if (min_d == d[idx][car_pos][o.dst]) min_dst = o.dst;
                            }      
                        }
                    }
                    else {
                       for (auto o: v_loads) {
                            min_d = min(min_d, d[idx][car_pos][o.dst]);
                            if (min_d == d[idx][car_pos][o.dst]) min_dst = o.dst;
                        }                        
                    }
                    final_goal = min_dst;
                    if (kaeritai(min_d, (ll)v_loads.size(), before_put, car_pos,idx)) final_goal = 1;
                    if (!Tlast && T*0.95 < t + d[idx][car_pos][1]) {
                        Tlast = true;
                        final_goal = 1;
                    }
                    op = dst2op(car_pos,final_goal,idx);
                    if(max_score_exec == INF) op = dst2op(car_pos,final_goal,0);
                }
                else {
                    op = dst2op(car_pos,final_goal,idx);
                    if(max_score_exec == INF) op = dst2op(car_pos,final_goal,0);
                }
            }
            if (max_score_exec != -1 && max_score_exec != INF) {//ラストの入り口
                final_goal = visted_path[max_score_exec];
                op = dst2op(car_pos, final_goal,0);
                max_score_exec = INF;
            }

            if (op == -1) {
                max_final_goals[(int)sealed_node.size() + e].push_back(op);
            }
            else { // opの示すノードまで進む
                if(max_score_exec == INF ){ //ラストスパートだから全マップ
                    for(ll t_next = t + d[0][car_pos][op]; t<T && t<t_next ;t++) {
                        max_final_goals[(int)sealed_node.size() + e].push_back(op);
                    }
                }
                else {
                    for(ll t_next = t + d[idx][car_pos][op]; t<T && t<t_next ;t++) {
                        max_final_goals[(int)sealed_node.size() + e].push_back(op);
                    }
                }
                t--;
                car_pos = op;
            }
        }
        if (e == 0) cerr << final_answer << endl;
        // cerr << (int)sealed_node.size() + e << ":" << current_total_score << "(" << (int)priority_dst.size() << ")" << endl;
        max_score = max(max_score, current_total_score);
        if (max_score == current_total_score) {
            truely_final_answer = (int)sealed_node.size() + e;
        }
    }

    for(auto op: max_final_goals[truely_final_answer]) {
        cout << op << endl;
    }
    cerr << truely_final_answer << endl;
    return 0;
}
