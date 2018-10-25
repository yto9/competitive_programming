#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> dire;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    pair<bool,int> a[502][502]; // visited?, num_of_coin
    pair<int,int> pos;
    dire d[4] = {
        {0,1},{1,0},{0,-1},{-1,0}
    };
    int H, W; cin >> H >> W;
    for (int j = 1; j <= H; j++) {
        for (int i = 1; i <= W; i++) {
            cin >> a[j][i].second;
            a[j][i].first == false;
        }
    }
    for(int i = 0; i <= W+1; i++) {
        a[0][i].first = true;
        a[H+1][i].first = true;
    }
    for(int j = 0; j <= H+1; j++) {
        a[j][0].first = true;
        a[j][W+1].first = true;
    }
    pos = {1,1};
    int di = 0;
    bool grab = false;
    vector<pair<pair<int,int>,pair<int,int>>> v;
    while (1){
        a[pos.first][pos.second].first = true;
        pair<int, int> next;
        next.first = pos.first + d[di].first;
        next.second = pos.second + d[di].second;
        if (a[next.first][next.second].first == true) {
            di = (di + 1)% 4;
            next.first = pos.first + d[di].first;
            next.second = pos.second + d[di].second;
            if (a[next.first][next.second].first == true) break;
        }
        if (a[pos.first][pos.second].second % 2 == 1) {
            v.push_back(make_pair(pos, next));
            a[next.first][next.second].second++;
        } 
        pos = next;
    }
    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second.first << " " << v[i].second.second << endl;
    }
    return 0;
}
