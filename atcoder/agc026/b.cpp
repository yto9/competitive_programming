#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    int T; cin >> T;
    vector<ll> A,B,C,D;
    REP(i, T) {
        ll a,b,c,d; cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    } 
    REP(i, T) {
        if (B[i] > D[i]) {
            cout << "No\n";
            continue; 
        }
        else if (B[i] == D[i]) {
            if (A[i] % B[i] > C[i]) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
            continue;
        }
        else {
            if (A[i] < B[i]) {
                cout << "No\n";
                continue;
            }
            if (A[i] % B[i] > C[i]) {//somosomo roop shinai
                cout << "No\n";
                continue;
            }
            else { //roop ha suru
                if (C[i] >= B[i] - 1) { //somosomo shinenai
                    cout << "Yes\n";
                    continue;
                }
                else {
                    ll s = A[i] % B[i];
                    ll delta = D[i] % B[i];
                    if (delta == 0) {
                        cout << "Yes\n";
                        continue;
                    }
                    if (((B[i] -1) - s) / delta == 0) {
                        cout << "Yes\n";
                        continue;    
                    }
                    else {
                        if (s + ((B[i] -1) - s) / delta * delta >= C[i] + 1){
                            cout << "No\n";
                        }
                        else {
                            cout << "Yes\n";
                        }
                        continue;
                    }   
                    
                }
            }
        }
    }
    return 0;
}
