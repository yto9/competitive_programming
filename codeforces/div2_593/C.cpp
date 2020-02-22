#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> res[300];
    deque<int> rest;
    for (int i = 1; i <= n*n; i++){
        rest.push_back(i);
    }
    while(!rest.empty()){
        REP(i,n) {
            res[i].push_back(rest.front());rest.pop_front();
        }
        if(rest.empty())break;
        REP(i,n) {
            res[i].push_back(rest.back());rest.pop_back();
        }
    }
    REP(i,n) {
        REP(j,n) {
            if (j!=n-1) {
                cout << res[i][j] << " ";
            }
            else{
                cout << res[i][j] << endl;
            }
            
        }
    }
    return 0;
}
