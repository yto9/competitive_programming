#include <bits/stdc++.h>

using namespace std; 
#define REP(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef pair<ll,ll> P;
void print(const std::vector<ll>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
   	ios::sync_with_stdio(false);
      // 昇順にソート済みの入力
    vector<ll> v2 = {0, 1, 2, 3, 4, 5};
    ll N; cin >> N;
    vector<P> v;
    REP(i, N) {
        ll tmp; cin >> tmp;
        v.push_back(P(tmp,(ll)i));
    }
    do {
        print(v2);
        ll sum = 0;
        for (auto x: v) {
            REP(i, N) {
                if (v2[i] == x.second) {
                    sum += x.first * abs(x.second - i);
                }
            }
        }
        cout << sum << endl;
    } while (std::next_permutation(v2.begin(), v2.end()));
    return 0;
}
