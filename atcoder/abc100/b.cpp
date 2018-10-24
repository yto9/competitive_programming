#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int d,n;
    cin >> d >> n;
    if (n == 100) cout << int((n + 1) * pow(100,d)) << "\n";
    else cout << int(n * pow(100,d)) << "\n";
    return 0;
}
