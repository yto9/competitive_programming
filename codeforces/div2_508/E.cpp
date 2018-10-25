#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll s;
    REP(i, 45001) {
        s += i;
        if (s % 2 == 0) continue;
        if (s % 3 == 0) continue;
        cout << s << endl; 
    }
    return 0;
}
