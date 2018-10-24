// BEGIN CUT HERE

// END CUT HERE
#line 5 "SimpleMathProblem.cpp"
#include <string>
#include <vector>
#include <cmath>

typedef long long ll;
class SimpleMathProblem {
	public:
	int calculate(int a, int b, int c, int m) {
		int res = (int) rSquare(a,pow(b,c), m);
		return res;
	}
	int rSquare(int N, int P, int M) {
		if(P==0) return 1;
    	if(P%2==0){
        ll t = rSquare(N, P/2, M);
        return t*t % M;
    }
    return (int) N * rSquare(N, P-1, M);
	}
};
