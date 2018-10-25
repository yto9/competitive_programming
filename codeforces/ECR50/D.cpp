#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n, m;
    ll a[300001],b[300001];
    cin >> n;
    a[0] = b[0] = 0;
    for(int i = 1; i<=n; i++) {
        ll tmp; cin >> tmp;
        a[i] = a[i-1] + tmp;;
    }
    cin >> m;
    for(int i = 1; i<= m; i++) {
        ll tmp; cin >> tmp;
        b[i] = b[i-1] + tmp;
    }
    if(a[n] != b[m]) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 1,j = 1; i <= n && j <= m;) {
        if(a[i] == b[j]) {
            res++;
            i++;
            j++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    cout << res << endl;
    return 0;
}