#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n, X; cin >> n >> X;
    int a[20] = {};
    int sum = 0;
    REP(i, n){
        cin >> a[i];
    }
    REP(i, n){
        if (X & (1 << i)) sum += a[i]; 
    }
    cout << sum << endl;
    return 0;
}
