#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int A; cin >> A;
    int B; cin >> B;
    for (int i = 1; i <= 3; i++) {
        if (i != A && i!= B) cout << i << endl;
    }
    return 0;
}
