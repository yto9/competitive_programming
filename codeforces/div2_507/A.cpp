#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n, a, b; cin >> n >> a >> b;
    vector<int> v(n);
    int cost = 0;
    REP(i, n) {
        cin >> v[i];
    }
    REP(i, n/2) {
        if(v[i] + v[n - (i+1)] == 0) {
            continue;
        }
        else if (v[i] + v[n - (i+1)] == 1) {
            cout << -1 << endl;
            return 0;
        }
        else if (v[i] + v[n - (i+1)] == 2) {
            if (v[i] != 1) cost += a;
        }
        else if (v[i] + v[n - (i+1)] == 3) {
            cost += b;
        }
        else { // 4
            cost += 2 * min(a, b);
        }
    }
    if (n % 2 == 1) {
        if (v[n/2] == 2) cost += min(a,b);
    } 
    cout << cost << endl;
    return 0;
}
