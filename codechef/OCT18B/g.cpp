// SURCHESS
#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int memo[207][207];
int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<string> board(N);
    REP(i,N) {
        cin >> board[i];
    }
    int Q; cin >> Q;
    vector<int> c(Q);
    REP(i, Q) {
        cin >> c[i];
    }
    REP(i, 201) {
        REP(j, 201) {
            memo[i][j] = 0;
        }
    } 
    int lma = min(M,N);
    vector<pair<int,int>> pq_size; // cost, size
    int finit = 1;
    for (int i = 1; i <= lma; i++) {// possible length //O(NMNMN)
        int min_cost = 30000;
        for (int ts = 0; ts <= N - i; ts++ ) {
            for (int ls = 0; ls <= M - i; ls++) {
                //i * i 探索
                int current_cost = 0;
                int gyakuL = 0;
                // for (int te = ts; te < ts + i; te++) {
                for (int te = ts; te < ts + i; te++) {
                    int le = ls + i - 1;
                    if (te == ts + i - 1) {
                        for (le = ls + i - 1; le >= ls; le--) {
                            if ((le - ls) % 2 == 0 && (te - ts) % 2 == 0) {
                                if (board[te][le] != '0') gyakuL++;
                            }
                            else if ((le - ls) % 2 == 1 && (te - ts) % 2 == 0) {
                                if (board[te][le] != '1') gyakuL++;
                            }
                            else if ((le - ls) % 2 == 0 && (te - ts) % 2 == 1) {
                                if (board[te][le] != '1') gyakuL++;
                            }
                            else if ((le - ls) % 2 == 1 && (te - ts) % 2 == 1) {
                                if (board[te][le] != '0') gyakuL++;
                            }
                        }
                    } 
                    else {
                        if ((le - ls) % 2 == 0 && (te - ts) % 2 == 0) {
                            if (board[te][le] != '0') gyakuL++;
                        }
                        else if ((le - ls) % 2 == 1 && (te - ts) % 2 == 0) {
                            if (board[te][le] != '1') gyakuL++;
                        }
                        else if ((le - ls) % 2 == 0 && (te - ts) % 2 == 1) {
                            if (board[te][le] != '1') gyakuL++;
                        }
                        else if ((le - ls) % 2 == 1 && (te - ts) % 2 == 1) {
                            if (board[te][le] != '0') gyakuL++;
                        }
                    }
                    

                }
                memo[ts][ls] += gyakuL;
                min_cost = min(min_cost, min(memo[ts][ls], i * i - memo[ts][ls]));
            }
        }
        pq_size.emplace_back(make_pair(min_cost,i));
        if (i == lma) finit = min_cost;
    
    }
    
    REP(i, Q) {
        if (finit <= c[i]) {
            cout << lma << endl;
        }
        else {
            auto itr = upper_bound(pq_size.begin(), pq_size.end(), make_pair(c[i],30000));
            auto cont = *itr;
            if (cont.first == c[i]) cout << cont.second << endl;
            else {
                itr--;
                auto cont = *itr;
                cout << cont.second << endl;
            }
        }
    }
    return 0;
}
