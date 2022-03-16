#include<iostream>
#include<algorithm>
using namespace std;
/*
	����һ���ַ���s,�����ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int freq[256] = { 0 };   //��¼����������ÿ���ַ����ֵĴ��� ���==1��������ظ��Ӵ�����
		int l = 0, r = -1;      //��������Ϊs[l...r]
		int res = 0;

		// ����ѭ���� l == 0; r == -1 ����մ��ڿ�ʼ
		// ��l == s.size(); r == s.size()-1 ����մ��ڽ�ֹ
		// ��ÿ��ѭ�����𽥸ı䴰��, ά��freq, ����¼��ǰ�������Ƿ��ҵ���һ���µ�����ֵ

		while (l < s.size()) {
			if (r + 1 < s.size() && freq[s[r + 1] == 0]) {
				r++;
				freq[s[r]]++;
			}
			else {   //r�Ѿ���ͷ || freq[s[r+1]] == 1
				freq[s[l]]--;
				l++;
			}
			res = max(res, r - l + 1);
		}
		return res;
	}
};