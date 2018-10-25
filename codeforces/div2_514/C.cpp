#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

vector<int> dfs(int n) {
    if (n == 1) return {1};
    else if(n == 3) return {1,1,3};
    else {
        vector<int> v(n/2+n%2,1);
        vector<int> v2 = dfs(n/2);
        REP(i, (int)v2.size()){
            v.push_back(v2[i]*2);
        }
        return v;
    }
}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> res = dfs(n);
    REP(i, n) {
        if (i != n-1) cout << res[i] << " ";
        else cout << res[i] << endl;
    }
    return 0;
}
