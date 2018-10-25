#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

bool close[1001];
vector<int> p;

int rec(int idx, vector<int> hole) { //1 <= idx <= n
    if (close[idx]) return idx;
    auto itr = find(hole.begin(), hole.end(), idx);
    if(itr == hole.end()){
        hole.push_back(idx); 
        return rec(p[idx],hole);
    }
    else {
        for (; itr != hole.end();itr++) {
            close[*itr] = true;
        }
        return idx;
    }
}
int main(int argc, char const *argv[])
{   
    
    int n; cin >> n;
    
    p.push_back(0);
    REP(i,n) {
        int tmp; cin >> tmp;
        p.push_back(tmp);
        close[i + 1] = false;
    }
    FOR(i, 1, n+1){
            vector<int> hole;
            cout << rec(i,hole) << " ";
    }
    cout << endl;
    return 0;
}
