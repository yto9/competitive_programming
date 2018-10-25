#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    REP(i, N) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }
    cout << pq.top() << endl;
    return 0;
}
