#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> inventory({"apples", "bananas", "oranges", "pears"});
    vector<string> shipment({"kiwis", "grapes", "bananas"});
    vector<string> s_o({"apples", "oranges"});

    
    cout << "Current inventory:" << endl;
    for (const string& item : inventory) {
        cout << item << endl;
    }

   
    cout << "\nShipment:" << endl;
    for (const string& item : shipment) {
        cout << item << endl;
    }

    
    cout << "\nSold out:" << endl;
    for (const string& item : s_o) {
        cout << item << endl;
    }

    vector<string> combine = inventory;
    combine.insert(combine.end(), shipment.begin(), shipment.end());

    
    for (const string& item : s_o) {
        combine.erase(remove(combine.begin(), combine.end(), item), combine.end());
    }

   
    cout << "\nUpdated inventory):" << endl;
    for (const string& c_invet : combine) {
        cout << c_invet << endl;
    }

    return 0;
}
