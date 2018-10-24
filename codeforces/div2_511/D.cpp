#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    ll res = 0;
    if (n==1||m==1) {
        res += (n*m/6) * 6;
        if (n*m%6==4) res += 2;
        else if (n*m%6==5) res += 4;
    }
    else if (n==2||m==2) {
        if (n*m == 4) res = 0;
        else if(n*m == 6|| n*m == 14) res = n*m - 2;
    }
    else if (n*m == 9) {
        res = n*m -1;
    }
    else if (n*m == 27) {
        res = 24;
    }
    // if (n%6==0||m%6==0) {
    //     res = (n*m)/2;
    // }
    // else if (n%4==0||m%4==0) {
    //     if (n==1||m==1) res = 2;
    //     else res = (n*m)/2; 
    // }
    
    cout << res << endl;
    return 0;
}
