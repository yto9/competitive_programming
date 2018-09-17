#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string A; cin >> A;
    string B; cin >> B;
    cout << ((A.size() > B.size()) ? A : B) << endl;
    return 0;
}
