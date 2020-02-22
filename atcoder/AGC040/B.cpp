#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
struct lr
{
    int l;
    int r;
    bool operator < (const lr& rhs) const {
        return (r-l) > (rhs.r - rhs.l);
    }
};


int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    priority_queue<lr> pq_lr;
    int N; cin >> N;
    REP(i,N){
        lr tmp; cin >> tmp.l >> tmp.r;
        pq_lr.push(tmp);
    }
    return 0;
}
