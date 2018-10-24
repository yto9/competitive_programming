// Minimize Digitsum
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int bfs(ll N, ll D,int val) {
    queue<pair<ll,int>> q;
    q.push({N,0});
    while(!q.empty()) {
        pair<ll,int> n = q.front(); q.pop();
        if (n.first == val) return n.second;
        q.push({n.first+D,n.second+1}); // add
        ll s = 0;// sum
        while(n.first > 0) {
            s += n.first % 10;
            n.first /= 10;
        }
        q.push({s, n.second+1});
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int T; cin >> T;
    REP(test, T) {
        ll N, D; cin >> N >> D;
        set<int> s_mod9;
        int pre = 0;
        s_mod9.insert(N%9);
        while(pre++ != (int)s_mod9.size()) {
            s_mod9.insert((N%9+(D*pre)%9)%9);
        }
        int min_val = 0;
        for (int i = 1; i<=9; i++) {
            if (i == 9) min_val = i;
            if(s_mod9.count(i) == 1) {
                min_val = i;
                break;
            }
        }
        int required_num = bfs(N, D, min_val);
        cout << min_val << " " << required_num << endl;
    }
    // cout.flush();
    return 0;
}
