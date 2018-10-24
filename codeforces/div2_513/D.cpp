#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<pair<int,int>> L, R;
    ll res = n;
    REP(i, n){
        int tmp_l, tmp_r;
        cin >> tmp_l >> tmp_r;
        n += tmp_l + tmp_r;
        if (tmp_l != tmp_r) {
            L.push(make_pair(tmp_l, tmp_r));
            R.push(make_pair(tmp_r, tmp_l));
        }
        else {
            res -= tmp_l;
        }
    }
    while() {
        pair<int, int> l = L.top();
        pair<int, int> r = R.top();
        while (l > r) {
            L
        }
    }
    
    return 0;
}
