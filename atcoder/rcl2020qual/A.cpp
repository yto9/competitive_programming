#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> monomino;
int valuable = 6;
monomino field[150][8];
int desire_color[125];
int current_top[8] = {0}; // x -> y map
int N, W, K, V; 
int green (int target_color, int rest_turn, int current_base, vector<int> already_use) { // x colで実現する
    int target_line = 1000;
    REP(i, K) {
        if (current_base + i == 125) break;
        if (desire_color[current_base + i] == -1) {
            desire_color[current_base + i] = target_color;
            target_line = current_base + i;
            break;
        }
        else if (desire_color[current_base + i] == target_color) {
            target_line = current_base + i;
            break;
        }
        else {
            continue;
        }
    }
    int kouho_x = -1;
    REP(x, W-1) {// W-1は使わない
        if (count(already_use.begin(),already_use.end(),x)) continue;
        if (current_top[x] == target_line) return x;
        if (kouho_x < current_top[x] && target_line > current_top[x]) kouho_x = x;
    }
    if (kouho_x == -1) return -1;
    if (rest_turn <= target_line - current_top[kouho_x]) return kouho_x;
    return -1; // 無理
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    cin >> N >> W >> K >> V; // 本データは N=1000, W = 8, K = 6, V = 8
    REP(x, W) {
        REP(y, N/W) {
            field[y][x] = monomino(0,0);
        }
    }
    REP(i, 125) {
        desire_color[i] = -1;
    }
    vector<monomino> v;
    queue<monomino> next_valuable;
    queue<int> next_valuable_turn;
    REP(i, N) {
        monomino tmp; cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
        if(tmp.second >= valuable) {
            next_valuable.push(tmp);
            next_valuable_turn.push(i);
        }
    }
    vector<int> output;
    int current_base = 0; // おける最低
    int current_idx = 0; //　何ターン目か
    while (!next_valuable.empty()) {
        vector<int> vv; // use before
        vv.push_back(W-1);
        monomino next_target = next_valuable.front();
        REP(i, K) {//　どの段で何色を狙うか
            if (current_base + i == 125) break;
            if (desire_color[current_base + i] >= 0 && desire_color[current_base + i] != next_target.first) continue; 
            else if (desire_color[current_base + i] == -1) {
                desire_color[current_base + i] = next_target.first;
                break;
            }
            else { // desired_color[current_base + i] == next_target
                break;
            }
        }
        if (green(next_target.first, next_valuable_turn.front() - current_idx, current_base, vv) == -1) { //ターン不足でどうしようもない
                next_valuable.pop();
                next_valuable_turn.pop();
                continue;
        }
        if (v[current_idx].second >= valuable) { //ちゃんとdesireに置く必要があるやつ
            REP(x, W) {
                if (current_top[x] != 125 && desire_color[current_top[x]] == v[current_idx].first) {
                    field[current_top[x]++][x] = v[current_idx];
                    output.push_back(x); break;
                }
                // desiredに置けなかった場合(TODO:)
                if (x == W-1) {
                    int bottom_x = 10;
                    int bottom_y = 125; 
                    REP(x, W) {
                        if (current_top[x] != 125 && desire_color[current_top[x]] == v[current_idx].first) {
                            field[current_top[x]++][x] = v[current_idx];
                            output.push_back(x);
                            break;
                        }
                        if (bottom_y >= current_top[x]) {
                            bottom_y = current_top[x];
                            bottom_x = x;
                        } 
                        if (x == W-1) {
                            field[current_top[bottom_x]++][bottom_x] = v[current_idx];
                            output.push_back(bottom_x);
                        }
                    }                    
                    // field[current_top[x]++][x] = v[current_idx];
                    // output.push_back(x); break;
                }
            }
        }
        else { //valuableじゃないやつ n個先のvaluable を置きやすくする
            int use_col = green(next_target.first, next_valuable_turn.front() - current_idx, current_base, vv);
            if (use_col >= 0) {
                if (desire_color[current_top[use_col]] != next_target.first) { //次置くのに足りてないからかさまし
                    field[current_top[use_col]++][use_col] = v[current_idx];
                    output.push_back(use_col);
                }
                else {
                    vv.push_back(use_col);
                    use_col = green(next_target.first, next_valuable_turn.front() - current_idx, current_base, vv);
                    if (use_col == -1) { //ターン不足でどうしようもない
                        next_valuable.pop();
                        next_valuable_turn.pop();
        int bottom_x = 10;
        int bottom_y = 125;
        REP(x, W) {
            if (current_top[x] != 125 && desire_color[current_top[x]] == v[current_idx].first) {
                field[current_top[x]++][x] = v[current_idx];
                output.push_back(x);
                break;
            }
            if (bottom_y >= current_top[x]) {
                bottom_y = current_top[x];
                bottom_x = x;
            } 
            if (x == W-1) {
                field[current_top[bottom_x]++][bottom_x] = v[current_idx];
                output.push_back(bottom_x);
            }
        }
                        // field[current_top[W-1]++][W-1] = v[current_idx];
                        // output.push_back(W-1);
                    }
                    else {
                        field[current_top[use_col]++][use_col] = v[current_idx];
                        output.push_back(use_col);
                    }
                }
            }
        }
        int tmp_base = 1000;
        REP(i, W) {   
            tmp_base = min(current_top[i], tmp_base);
        }
        current_base = tmp_base;
        current_idx++;
        if(current_idx == N) break;
    }
    for(int i = current_idx; i < N; i++) {
        int bottom_x = 10;
        int bottom_y = 125;
        REP(x, W) {
            if (desire_color[current_top[x]] == v[i].first) {
                field[current_top[x]++][x] = v[i];
                output.push_back(x);
                break;
            }
            if (bottom_y >= current_top[x]) {
                bottom_y = current_top[x];
                bottom_x = x;
            } 
            if (x == W-1) {
                field[current_top[bottom_x]++][bottom_x] = v[i];
                output.push_back(bottom_x);
            }
        }
    }
    for (auto x: output) {
        cout << x << endl;
    }
    return 0;
}
