#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    double L; cin >> L;
    double x = L/3;
    cout << fixed << setprecision(7) << x * x * x << endl;
    return 0;
}
