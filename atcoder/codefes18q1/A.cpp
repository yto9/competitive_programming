#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int A,B,C,S;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> S;
    if (A+B+C<=S && A+B+C+3>=S) {
        cout << "Yes" << endl;
    }
    else cout<< "No" << endl;
    return 0;
}
