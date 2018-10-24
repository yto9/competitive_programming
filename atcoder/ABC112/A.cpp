#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N; cin >> N;
    if (N == 1) {
        cout << "Hello World" << endl;
    }
    else if (N == 2) {
        int A, B;
        cin >> A;
        cin >> B;
        cout << A + B << endl; 
    }
    return 0;
}
