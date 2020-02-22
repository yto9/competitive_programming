#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int A, B, C; cin >> A >> B >> C;
    if (A == B) {
        if (A != C) {
            cout << "Yes" << endl; return 0;
        }
        else {
            cout << "No" << endl; return 0;
        }
    }
    else if (A == C){
        cout << "Yes" << endl; return 0;
    }
    else {
        if (B == C) {
            cout << "Yes" << endl; return 0;
        }
        else {
            cout << "No" << endl; return 0;
        }
    }
    return 0;
}
