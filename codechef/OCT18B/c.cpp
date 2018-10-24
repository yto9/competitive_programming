// BITOBYT
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int T; cin >> T;
    REP(test, T){
        int N; cin >> N;
        int population = pow(2, (N-1)/26);//あふれてる多分
        int mod26 = (N-1) % 26;
        int phase;
        if (mod26 < 2) phase = 0;
        else if (mod26 < 10) phase = 1;
        else phase = 2;
        REP(i, 3) {
            if (i == phase) cout << population;
            else cout << 0;
            if (i != 2) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}
