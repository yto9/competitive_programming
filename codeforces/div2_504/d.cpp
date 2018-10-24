#include <bits/stdc++.h>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++) 
#define REP(i, n) for (int i = 0; i < (n); i++)


struct SegmentTree {
    private:
        int n;
        vector<int> node;
    public:
        SegmentTree(vector<int> v) {
            int sz = v.size();
            n = 1; while(n < sz) n *= 2;
            node.resize(2 * n - 1,INT_MAX);
            REP(i, sz) node[i + n - 1] = v[i];
            for(int i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
        }

        void update(int x, int val) {
            x += n - 1;
            node[x] = val;
            while(x > 0) {
                x = (x - 1) / 2;
                node[x] = min(node[2 * x + 1], node[2* x + 2]);
            }
        }

        int getmin(int a, int b, int k=0, int l=0, int r=-1) {
            if (r < 0) r = n;
            if (b <= l || r <= a) return INT_MAX;
            if (a <= l && r <= b) return node[k];
            
            int vl = getmin(a, b, 2*k + 1, l, (l + r) / 2);
            int vr = getmin(a, b, 2*k + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
};

int main(int argc, char const *argv[])
{
    int n, q; cin >> n >> q;
    vector<int> v;
    int l[200001];
    int r[200001];
    REP(i, q + 1) {
        l[i] = n + 1;
        r[i] = 0;
    }
    bool wild = false;
    REP(i, n) {
        int tmp; cin >> tmp;
        if (tmp == 0) {
            tmp = INT_MAX;
            wild = true;
        }
        else {
            l[tmp] = min(l[tmp], i);
            r[tmp] = max(r[tmp], i);
        }
        v.push_back(tmp);
    }
    if(wild == false && r[q] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    SegmentTree seg(v);
    REP(i, q) {
        if (r[q - i] == 0) continue;
        if (q - i != seg.getmin(l[q - i], r[q - i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    int pre = 
    REP(i, n) {
        if(r[q] == 0 && v[i] == INT_MAX && wild) {
            v[i] = q;
            wild = false;
        }
        cout << v[i];
    }
    return 0;
}
