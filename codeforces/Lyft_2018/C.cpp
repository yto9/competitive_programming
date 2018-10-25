#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
// ll mod_pow(ll x, ll n, ll mod){//x^n % mod
//     if (n == 0)
//         return 1;
//     ll res = mod_pow(x * x % mod, n / 2, mod);
//     if (n & 1)
//         res = res * x % mod;
//     return res;
// }
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<pair<int,int>> board; // number, position
    set<int> lose_next; // position(0-index) keep the pos alice win
    REP(i,n) {
        int number; cin >> number;
        board.push(make_pair(number,i));
    }
    lose_next.insert(board.top().second);
    board.pop();
    while (!board.empty()){
        auto alice_pos = board.top(); board.pop();
        bool lose = true;
        // for(auto dest_pos: lose_next) {//O(n^2) 
            // if (abs(dest_pos - alice_pos.second) % alice_pos.first == 0) {
                // lose = false;
                // break;
            // }
            // else continue;
        // }
        int l = alice_pos.second - alice_pos.first;
        int r = alice_pos.second + alice_pos.first;
        while(0<=l) {
            if(lose_next.find(l)!=lose_next.end()){
                lose = false;
                break;
            };
            l -= alice_pos.first;
        }
        while(r<n) {
            if(lose_next.find(r)!=lose_next.end()){
                lose = false;
                break;
            };
            r += alice_pos.first;
        }
        if (lose) lose_next.insert(alice_pos.second);
    }
    // sort(lose_next.begin(),lose_next.end());
    // int idx = 0;// lose_nextはemptyではない少なくともnumber == n の時
    auto itr = lose_next.begin();
    REP(i, n) {
        if (itr == lose_next.end()) {
            cout << "A";
        }
        else if (i == *itr) {
            cout << "B";
            itr++;
        }
        else {
            cout << "A";
        } 
    }
    cout << endl;
    return 0;
}
