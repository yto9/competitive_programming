#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll K; cin >> K;
    vector<ll> ans;
    queue<ll> runrun;
    for (int i = 1; i < 10; i++) runrun.push(i);
    while (ans.size() <= 100000)
    {
        ll cur = runrun.front(); runrun.pop();
        ans.push_back(cur);
        ll first_keta = cur % 10;
        if(first_keta == 0) {
            runrun.push(cur*10+first_keta);
            runrun.push(cur*10+first_keta + 1);
        }
        else if (first_keta == 9) {
            runrun.push(cur*10+first_keta-1);
            runrun.push(cur*10+first_keta);
        }
        else {
            runrun.push(cur*10+first_keta-1);
            runrun.push(cur*10+first_keta);
            runrun.push(cur*10+first_keta + 1);         
        }
    }
    cout << ans[K-1] << endl;
    return 0;
}
