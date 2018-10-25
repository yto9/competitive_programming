    #include <bits/stdc++.h>
     
    using namespace std; 
    #define REP(i, n) for (int i = 0; i < (n); i++)
     
    typedef long long ll;
    typedef pair<ll,ll> P;
    ll MD (P a, P b) {
        return abs(a.first-b.first) + abs(a.second - b.second); 
    }
    int main(int argc, char const *argv[])
    {
        cin.tie(0);
       	ios::sync_with_stdio(false);
        ll N; cin >> N;
        vector<P> p(N);
        vector<P> h(N); // height, idx
        P c;
        REP(i, N) {
            ll x, y, z; cin >> x >> y >> z;
            p[i] = make_pair(x,y);
            h[i] = make_pair(z,i);
            if (N == 1) cout << x << " " << y << " " << z << endl;
        }
        sort(h.rbegin(),h.rend());
        vector<pair<ll,P>> maxH; // h , point
        REP(y, 101) {
            REP(x, 101) {
                c = make_pair(x,y);
                ll H = h[0].first + MD(c, p[h[0].second]);
                bool center = true;
                for (int i = 1; i < N; i++) {
                    int cnt = 0;
                    if (h[i].first==0) cnt++;
                    ll H2 = h[i].first + MD(c,p[h[i].second]);
                    if (h[i].first!=0 && H != H2) {
                        center = false;
                        break;
                    }
                }    
                if (center) {
                    // maxH.push_back(make_pair(H,make_pair(x,y)));
                    cout << x << " " << y << " " << H << endl;
                    return 0;
                }    
            }
        }
        // sort(maxH.rbegin(),maxH.rend());
        // cout << maxH[0].second.first << " " << maxH[0].second.second << " " << maxH[0].first << endl;
        return 0;
    }