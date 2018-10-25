#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int search = M/N;
    while(search > 0) {
        int M2 = M;
        M2 -= search * N;
        if(M2 % search == 0) break;
        search--;
    }
    cout << search << endl;
    return 0;
}
