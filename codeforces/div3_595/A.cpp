#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int q; cin >> q;
    REP(test,q) {
        int n; cin >> n;
        priority_queue<int>  pq;
        REP(i,n) {
            int tmp; cin >> tmp;
            pq.push(tmp);
        }
        int pre = 1000;
        int res = 1;
        while(!pq.empty()) {
            int cur = pq.top();pq.pop();
            if (pre - cur > 1) {
                pre = cur;
            }
            else {
                res = 2;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
