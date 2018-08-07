#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int R;
    cin >> R;
    if (R < 1200)
        cout << "ABC\n";
    else if (R < 2800)
        cout << "ARC\n";
    else
        cout << "AGC\n";
    return 0;
}
