#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> point;
typedef pair<int,point> state;
priority_queue<state> q_s;
int visited[100][100] = {0} ;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int H, W; cin >> H >> W;
    vector<string> board;
    REP(i, H) {
        string tmp; cin >> tmp;
        board.push_back(tmp);
    }
    REP(i, H) {
        REP(j, W) {
            visited[i][j] = -1000;
        }
    }
    point goal = make_pair(H-1,W-1);
    q_s.push(make_pair(-(board[goal.first][goal.second] == '#'),goal)); visited[goal.first][goal.second] = 0;
    while (!q_s.empty()){
        state cur_s = q_s.top(); q_s.pop();
        point cur_p = cur_s.second;
        if (cur_p.first == 0 && cur_p.second == 0) {
            cout << -cur_s.first << endl;
            break;
        }
        if (board[cur_p.first][cur_p.second] == '#') {
            if (cur_p.first != 0) {
                point up = make_pair(cur_p.first - 1, cur_p.second);
                if (visited[up.first][up.second] < cur_s.first) {
                    q_s.push(make_pair(cur_s.first, up));//ここが重い
                    visited[up.first][up.second] = cur_s.first;
                }
            }
            if (cur_p.second != 0) {
                point left = make_pair(cur_p.first, cur_p.second - 1);
                if (visited[left.first][left.second] < cur_s.first) {
                    q_s.push(make_pair(cur_s.first, left));//ここが重い
                    visited[left.first][left.second] = cur_s.first;
                }
            }
        }
        else if (board[cur_p.first][cur_p.second] == '.'){
            if (cur_p.first != 0) {
                point up = make_pair(cur_p.first - 1, cur_p.second);
                if (visited[up.first][up.second] < cur_s.first - (board[up.first][up.second] == '#')) {
                    q_s.push(make_pair(cur_s.first - (board[up.first][up.second] == '#'), up));//ここが重い
                    visited[up.first][up.second] = cur_s.first - (board[up.first][up.second] == '#');
                }
            }
            if (cur_p.second != 0) {
                point left = make_pair(cur_p.first, cur_p.second - 1);
                if (visited[left.first][left.second] < cur_s.first - (board[left.first][left.second] == '#')) {       
                    q_s.push(make_pair(cur_s.first - (board[left.first][left.second] == '#'), left));//ここが重い
                    visited[left.first][left.second] = cur_s.first - (board[left.first][left.second] == '#');
                }
            }           
        }
    }
    
    return 0;

}
