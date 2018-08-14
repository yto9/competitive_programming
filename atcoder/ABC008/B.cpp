#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int N; cin >> N;
    unordered_map<string, int> mp;
    REP(i, N) {
        string s; cin >> s;
        mp[s]++;
    }
    auto it = *max_element(mp.begin(),mp.end(),[](const pair<string,int> & p1, const pair<string,int> & p2){
        return p1.second < p2.second;
    });
    cout << it.first << endl;
    return 0;
}
