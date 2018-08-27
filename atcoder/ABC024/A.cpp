#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int A, B, C, K; cin >> A >> B >> C >> K;
    int S, T; cin >> S >> T;
    cout << A*S + B*T - (S + T >= K)*(S + T)*C << endl;
    return 0;
}
