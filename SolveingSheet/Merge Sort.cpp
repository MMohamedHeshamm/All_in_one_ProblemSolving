#include <vector>
#include<iostream>
using namespace std;


void mergeSubarrays(int low, int mid, int high, vector<int>& nums) {
    if (low >= high) return;

    int l = low, r = mid + 1, k = 0, size = high - low + 1;
    vector<int> sorted(size, 0);

    while (l <= mid && r <= high)
        sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];

    while (l <= mid)
        sorted[k++] = nums[l++];

    while (r <= high)
        sorted[k++] = nums[r++];

    for (k = 0; k < size; k++)
        nums[low + k] = sorted[k];
}

// Merge Sort main function (recursive)
void mergeSort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        mergeSubarrays(start, mid, end, nums);
    }
}

// Function to sort the array (entry point)
vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}