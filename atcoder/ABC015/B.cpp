#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    int A[100];
    int sum = 0;
    int num_p = 0;
    REP(i,N) {
        cin >> A[i];
        if (A[i] > 0) {
            num_p++;
            sum += A[i];
        }
    }
    cout << sum/num_p + (sum%num_p != 0) << endl;

    return 0;
}
