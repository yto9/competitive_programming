#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
typedef long long ll;

vector <int> v[3];
ll dfs() {

}
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    cout << dfs(0,n,m) << endl;
    return 0;
}
