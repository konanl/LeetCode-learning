#include<ostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
/*
	使用哈希容器map储存vector中出现的数
	只要目标数=target-nums[i]
	则找到两数之和=target的那对数的索引
*/ 
public:
	vector<int> twoSum(vector<int>& nums, int target){
		map<int, int> mm;
		for (int i = 0; i < nums.size(); i++) {
			int find = target - nums[i];
			if (mm.count(find) != 0) {
				return vector<int> {nums[find], i};
			}
			return vector<int>();
		}
	}
};
