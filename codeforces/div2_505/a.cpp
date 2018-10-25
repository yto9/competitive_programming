#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<char,int> ump;
    REP(i, n) {
        ump[s[i]]++;
    }
    auto itr = *max_element(ump.begin(),ump.end(),[](const pair<char,int> & p1, const pair<char,int> & p2){
    return p1.second < p2.second;
});
    if (n == 1) cout << "YES" << endl;
    else if (itr.second == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
