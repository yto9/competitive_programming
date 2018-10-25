#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n, m; cin >> n >> m;
    string a = "";
    string b = "";
    REP(i, 1200/9) {
        a += "45";
        b += "54";
    }
    a += "5";
    b += "5";
    cout << a << endl;
    cout << b << endl;
    return 0;
}
