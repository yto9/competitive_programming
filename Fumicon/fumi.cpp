#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
// typedef pair<int, int> R;
typedef pair<int, int> D;// diff, idx

int main(int argc, char const *argv[])
{
    int N, K; cin >> N >> K;
    //input
    vector<int> a(30001);
    priority_queue<D> gt_p;
    priority_queue<D> lt_p;
    //result
    vector<D> dR(3001);
    vector<D> iR(3001);
    vector<int> v(3001);
    for (int i = 0; i < 3001; i++) {
        dR[i] = make_pair(0,0);
        iR[i] = make_pair(0,0);
        v[i] = 0;
    }
    int th = (int)(N * 0.1);

    REP(i, N) {
        cin >> a[i];
        if (max(a[i]-(i+1),0) > th) gt_p.push(make_pair(max(a[i]-(i+1),0),i + 1));
        else if(max((i+1)-a[i],0) > th) lt_p.push(make_pair(max((i+1)-a[i],0),i + 1));
    }
    int restK = K;
    bool single = true;
    while (restK > 0) {
        while (restK > 500 && single){
            if (gt_p.empty()||lt_p.empty()){
                single = false;
                break;
            }
            D g = gt_p.top();
            gt_p.pop();
            D l = lt_p.top();
            lt_p.pop();
            if (g.second == l.second) continue;
            int diff = min(g.first,l.first);
            if (diff == 0) {
                single = false;
                break;
            }
            dR[K-restK] = make_pair(g.second,g.second);
            iR[K-restK] = make_pair(l.second,l.second);
            v[K-restK] = diff;
            a[g.second] -= diff;
            a[l.second] += diff;
            if (max(g.first, l.first) - diff > th) {
                g.first -= diff;
                l.first -= diff;
                gt_p.push(g);
                lt_p.push(l);
            }
            restK--;
        }
        v[K-restK] = 0;
        iR[K-restK] = make_pair(1,1);
        dR[K-restK] = make_pair(N-1,N-1);
        restK--;
    }
    // while(restK > 0) {
        // if (gt_p.empty()||lt_p.empty()){
            // single = false;
            // break;
        // }
        // D g = gt_p.top(); gt_p.pop();
        // D l = lt_p.top(); lt_p.pop();
        // if (g.second == l.second) continue;
        // if ()
    // }
    REP(i, K) {
        cout << dR[i].first << " " << dR[i].second << " " << iR[i].first << " " << iR[i].second  << " " << v[i] << endl;
    }
    return 0;
}
