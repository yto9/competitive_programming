#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int a; cin >> a;
    int b; cin >> b;
    cout << ((a%b == 0) ? 0 : b - a%b) << endl;
    return 0;
}
