#include<ostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
/*
	ʹ�ù�ϣ����map����vector�г��ֵ���
	ֻҪĿ����=target-nums[i]
	���ҵ�����֮��=target���Ƕ���������
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
