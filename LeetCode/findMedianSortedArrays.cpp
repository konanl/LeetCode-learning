#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays_Easy(vector<int>& nums1, vector<int>& nums2) {
		vector<int> vec;
		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j]) vec.push_back(nums1[i++]);
			else vec.push_back(nums2[j++]);
		}
		while (i < nums1.size()) vec.push_back(nums1[i++]);
		while (j < nums2.size()) vec.push_back(nums2[j++]);

		return vec.size() % 2 ? vec[vec.size() / 2] : (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2.0;
 	}

	double findMedianSortedArrays_Faster(vector<int>& nums1, vector<int>& nums2) {

	}
};

