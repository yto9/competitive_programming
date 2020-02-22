#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    string s; cin >> s;
    int res = 0;
    if (s == "SUN") res = 7; 
    if (s == "MON") res = 6; 
    if (s == "TUE") res = 5; 
    if (s == "WED") res = 4; 
    if (s == "THU") res = 3; 
    if (s == "FRI") res = 2; 
    if (s == "SAT") res = 1;
    cout << res << endl; 
    return 0;
}
