#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    string A, B; cin >> A >> B;
    A += B;
    cout << stoi(A)*2 << endl;
    return 0;
}
