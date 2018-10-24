#include <bits/stdc++.h>
using namespace std;


vector<int> getVector() {
    int size; cin >> size;
    vector<int> v(size); 
    for (int i = 0; i < size ; i++) {
        cin >> v[i];
    }
    return v;
}

vector<int> getVectorwithSize(int size) {
    vector<int> v(size); 
    for (int i = 0; i < size ; i++) {
        cin >> v[i];
    }
    return v;
}

int main(int argc, char const *argv[])
{
    // TrucksAndCouriers tac;
    int truckFixed, truckVariable;
    cin >> truckFixed;
    // cin >> truckVariable;
    // vector<int> warehouseX = getVector();
    // vector<int> warehouseY = getVector();
    // vector<int> warehouseItem = getVector();
    // vector<int> warehouseQuantity = getVector();
    // vector<int> customerX = getVector();
    // vector<int> customerY = getVector();
    // vector<int> customerItem = getVector();
    // vector<string> ret = tac.planShipping(truckFixed, truckVariable, warehouseX, warehouseY,
                            //  warehouseItem, warehouseQuantity, customerX, customerY, customerItem);
    cout << truckFixed;
    return 0;
}