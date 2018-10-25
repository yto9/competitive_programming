#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << min(abs(b - a),10 - abs(b - a)) << endl;
    return 0;
}
