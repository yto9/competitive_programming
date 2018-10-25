#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> board(10);
vector<pair<int,int>> v_robot;
vector<char> d_robot;
string res;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int w = 19;
    int h = 10;
    for (int i = 0; i < 10; i++) {
        string line;
        cin >> line; cin.ignore();
        board[i] = line;
    }
    
    // for (int i = 0; i < 10; i++) {
        // for (int j = 0; j < 19; j++) {
            // if (board[i][j] != '#') {
                // res += to_string(j) + " " + to_string(i) + " R ";
            // }
        // }
    // }
    int robotCount;
    cin >> robotCount; cin.ignore();
    for (int i = 0; i < robotCount; i++) {
        int x;
        int y;
        string direction;
        cin >> x >> y >> direction; cin.ignore();
        v_robot.push_back(make_pair(x,y));
        d_robot.push_back(direction[0]);
    }
    
    for(int i = 0; i < robotCount; i++) {
        int l = 0;
        int r = 0;
        int t = 0;
        int b = 0;
        int x = v_robot[i].first;
        int y = v_robot[i].second;
        //torus　no toki　doushiyo
        while(x+l > 0 && board[y][x + l - 1] != '#') l--;
        while(x+r < w-1 && board[y][x + r + 1] != '#') r++;
        while(y+t > 0 && board[y + t - 1][x] != '#') t--;
        while(y+b < h-1 && board[y + b + 1][x] != '#') b++;
        //torus pattern
        if (x + l == 0 && board[y][x + l + w - 1] !=  '#') {
            l += w - 1;
            while(x + l > x + 1 && board[y][x + l - 1] != '#') l--;
        }
        if (x + r == w - 1 && board[y][x + r - w + 1] !=  '#') {
            r -= w - 1;
            while(x + r < x - 1 && board[y][x + r + 1] != '#') r++;
        }
        if (y + t == 0 && board[y + t + h - 1][x] !=  '#') {
            t += h - 1;
            while(y + t > y + 1 && board[y + t -1][x] != '#') t--;
        }
        if (y + b == h - 1 && board[y + b - h + 1][x] !=  '#') {
            b -= h - 1;
            while(y + b < y - 1 && board[y + b + 1][x] != '#') b++;
        }
        if (r != l) {
            res += to_string(x+l) + " " + to_string(y) + " R ";
            res += to_string(x+r) + " " + to_string(y) + " L ";
        }
        if (t != b) {
            res += to_string(x) + " " + to_string(y+t) + " D ";
            res += to_string(x) + " " + to_string(y+b) + " U ";
        }
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    res.pop_back();
    cout << res << endl;
}