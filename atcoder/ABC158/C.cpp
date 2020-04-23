#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int A, B; cin >> A >> B;
    int res = -1;  
    REP(i, 2000) {//適当
        if (floor(i*0.08) == A && floor(i*0.1) == B){
            res = i;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
