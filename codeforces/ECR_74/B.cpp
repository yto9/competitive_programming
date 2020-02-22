#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int q; cin >> q;
    REP(test, q) {
        int n,r; cin >> n >> r;
        priority_queue<int> enemy;
        REP(i,n) {
            int tmp; cin >> tmp;
            enemy.push(tmp);
        }
        int res = 0;
        while(!enemy.empty() && enemy.top() > res * r ){
            int bomb = enemy.top(); enemy.pop();
            res++;
            while(!enemy.empty() && bomb == enemy.top()) enemy.pop();
        }
        cout << res << endl;
    }
    return 0;
}
