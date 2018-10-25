#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    priority_queue <int> pqr;
    REP(i, N) {
        int tmp; cin >> tmp;
        pqr.push(tmp);
    }
    int Pi = 0;
    REP(i, N) {
        int r = pqr.top(); pqr.pop();
        if (i % 2 == 0) Pi += r * r;
        else Pi -= r*r;
    }
    cout << fixed << setprecision(6) << Pi * M_PI << endl;
    return 0;
}
