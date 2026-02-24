#include <iostream>
#include <vector>
using namespace std;

// Complete Search (Backtracking) to generate all subsets of a given set
void completeSearch(vector<int>& arr, vector<int>& current, int index) {

    if (index == arr.size()) {
		// print the current subset
        cout << "{ ";
        for (int i = 0; i < current.size(); i++)
            cout << current[i] << " ";
        cout << "}" << endl;
        return;
    }

	// option 1 : choose the current element
    current.push_back(arr[index]);
    completeSearch(arr, current, index + 1);

	// option 2 : don't choose the current element
    current.pop_back();
    completeSearch(arr, current, index + 1);
}

//int main() {
//
//    vector<int> arr = { 1, 2, 3 };
//    vector<int> current; // subset مؤقت
//
//    completeSearch(arr, current, 0);
//}



//-------------------------------------------------



