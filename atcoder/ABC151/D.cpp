#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> po;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int H, W;
vector<string> board;
ll bfs(int i, int j) {
    vector<string> visited(board.size());
    copy(board.begin(),board.end(),visited.begin());
    queue<po> que;
    queue<int> dist;    
    visited[i][j] = '#';
    REP(k, 4){
        po next = po(i+dx[k],j+dy[k]);
        if (next.first>=0&&next.first<H&&next.second>=0&& next.second <W && visited[next.first][next.second] == '.') {
            visited[next.first][next.second] = '#';
            que.push(next);
            dist.push(1);
        }
    }
    ll d;
    while(!que.empty()){
        po cur = que.front(); que.pop();
        d = dist.front(); dist.pop();
        REP(k, 4){
            po cur_n = po(cur.first+dx[k],cur.second+dy[k]);
            if (cur_n.first>=0&&cur_n.first<H&&cur_n.second>=0&& cur_n.second <W && visited[cur_n.first][cur_n.second] == '.') {
                visited[cur_n.first][cur_n.second] = '#';
                que.push(cur_n);
                dist.push(d+1);
            }
        }
    }
    return d;
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H){
        string s; cin >> s;
        board.push_back(s);
    }
    ll res = 0;
    REP(i, H) {
        REP(j, W) {
            if (board[i][j]=='.')
            res = max(res, bfs(i,j));
        }
    }
    cout << res << endl;
    return 0;
}
