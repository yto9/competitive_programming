#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
vector<string> board;
string dfs(int pos, int move, int h) {
    if (board[h][pos] == 'x') return "";
    if (h == 0) {
        if (move == -1) return "L";
        else if (move == 0) return "S";
        else if (move == 1) return "R";
    }
    else if (board[h][pos] == '.') {
        for (int i = -1; i <= 1; i++) {
            string res = dfs(pos+i, i, h - 1);
            if (res != "") {
                if (move == -1) return "L" + res;
                else if (move == 0) return "S" + res;
                else if (move == 1) return "R" + res;
            }
        } 
    } 
    return "";
}


int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int H,W; cin >> H >> W;
    REP(i, H) {
        string s; cin >> s;
        board.push_back("x"+s+"x");
    }
    string find_word("s");
    string::size_type pos = board.back().find(find_word);
    string res;
    for (int i = -1; i <= 1; i++){
        res = dfs(pos+i,i,H-2);
        if (res != "") break;
    }
    if (res == "") cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}
