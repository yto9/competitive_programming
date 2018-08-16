#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int M, D; cin >> M >> D;
    cout << ((M%D == 0)? "YES": "NO")<< endl;
    return 0;
}
