#line 5 "CubesOnATable.cpp"
#include <string>
#include <vector>

using namespace std;
class CubesOnATable {
	public:
	vector <int> placeCubes(int surface) {
		vector <int> v;
		if (surface < 5 || surface == 6 || surface == 7) return v;
		if (surface == 8 || surface == 11 || surface == 12 || surface == 16) {
			v.push_back(0);
			v.push_back(0);
			v.push_back(0);
			v.push_back(0);
			v.push_back(1);
			v.push_back(0);
			if (surface == 8) return v;
			if (surface == 11) {
				v.push_back(0);
				v.push_back(2);
				v.push_back(0);
			}
			else if (surface == 12) {
				v.push_back(0);
				v.push_back(0);
				v.push_back(1);
			}
			else {
				v.push_back(9);
				v.push_back(0);
				v.push_back(0);
				v.push_back(9);
				v.push_back(1);
				v.push_back(0);
			}
			return v;
		}
		if (surface % 4 == 1) {
			for (int z = 0; z < surface/4;z++) {
				v.push_back(0);
				v.push_back(0);
				v.push_back(z);
			}
			return v;
		}
		else if (surface % 4 == 2) {
			v.push_back(9);
			v.push_back(0);
			v.push_back(0);
			for (int z = 0; z < surface/4 - 1;z++) {
				v.push_back(0);
				v.push_back(0);
				v.push_back(z);
			}
			return v;
		}
		else if (surface % 4 == 3) {
			v.push_back(9);
			v.push_back(0);
			v.push_back(0);
			v.push_back(0);
			v.push_back(9);
			v.push_back(0);
			for (int z = 0; z < surface/4 - 2;z++) {
				v.push_back(0);
				v.push_back(0);
				v.push_back(z);
			}
			return v;			
		}
		else {
			v.push_back(9);
			v.push_back(0);
			v.push_back(0);
			v.push_back(0);
			v.push_back(9);
			v.push_back(0);
			v.push_back(9);
			v.push_back(9);
			v.push_back(0);
			for (int z = 0; z < surface/4 - 4;z++) {
				v.push_back(0);
				v.push_back(0);
				v.push_back(z);
			}
			return v;				
		}
	}
};


// Powered by FileEdit
// Powered by CodeProcessor
