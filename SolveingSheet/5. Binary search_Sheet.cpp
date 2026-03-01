#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}

int main() {
    vector<int> arr = { 1, 3, 5, 7, 9, 11 };

    int target = 7;
    int result = binarySearch(arr, 0, arr.size() - 1, target);

    if (result != -1)
        cout << "The item is Exist : " << result;
    else
        cout << "The item is not Exist!!";

    return 0;
}