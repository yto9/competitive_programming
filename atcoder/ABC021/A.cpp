#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    int count = 0;
    REP(i, 4) {
        if (N & 1 << i){
            count++;
        }
    }
    cout << count << endl;
    REP(i, 4) {
        if (N & 1 << i){
            cout << (1 << i) << endl;
        }
    }
    return 0;
}
