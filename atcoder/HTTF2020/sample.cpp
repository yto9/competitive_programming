#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<int,int> point;
struct robot
{
    point p;
    char direction;
};
// struct block
// {
//     point p;
// };

// 'U','D','L','R'
char inst[4] = {'U','D','L','R'};
point dir[4] = {make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};
map<char,char> m_inv = {make_pair('U','D'),make_pair('D','U'),make_pair('L','R'),make_pair('R','L')};
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, M, B; cin >> N >> M >> B; // N=40, M=100, B=300で固定
    point Gyx; cin >> Gyx.first >> Gyx.second;
    vector<robot> r(M);
    map<point,int> b;
    map<point, char> m;
    REP(i,M) {
        cin >> r[i].p.first >> r[i].p.second >> r[i].direction;
    }
    REP(i,B) {
        point tmp;
        cin >> tmp.first >> tmp.second;
        b[tmp] = 0;
    }
    // mに表札を詰める
    // ゴールの飛車の位置に来たら最低限捕縛
    // 'D'埋め
    REP(j, 4) {
        point cur = Gyx;
        REP(i, N) {
            cur.first = (cur.first + N + dir[j].first ) % N;
            cur.second = (cur.second + N + dir[j].second ) % N;
            char c = m_inv.at(inst[j]);
            m[make_pair(cur.first,cur.second)] = c;
            map<point,int> tmp_m = b; 
            tmp_m[make_pair(cur.first,cur.second)] = 1;
            if (tmp_m.size() == b.size()) {
                break;
            }
        }
    }
    
    cout << m.size() << endl;
    for (auto x: m) {
        cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    return 0;
}
