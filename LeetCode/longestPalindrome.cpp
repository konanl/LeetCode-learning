#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	/*
	
		首先说下什么是回文串，就是正读反读都一样的字符串，比如 "bob", "level", "noon" 等等。
		那么最长回文子串就是在一个字符串中的那个最长的回文子串。
		我们知道传统的验证回文串的方法就是两个两个的对称验证是否相等，
		那么对于找回文字串的问题，就要以每一个字符为中心，像两边扩散来寻找回文串，
		这个算法的时间复杂度是O(n*n)，
		就是要注意奇偶情况，
		由于回文串的长度可奇可偶，比如"bob"是奇数形式的回文，
		"noon"就是偶数形式的回文，两种形式的回文都要搜索。

	*/
	string longestPalindrome(string s) {

		if (s.length() <= 1) {
			return s;
		}

		int start = 0;
		int max_len = 0;

		int prior_index = 0;
		int next_index = 0;

		for (int i = 0; i < s.length() - 1; ++i) {

			if (s[i] == s[i + 1]) {
				prior_index = i;
				next_index = i;
				searchPalindrome(s, prior_index, next_index, max_len, start);
			}

			prior_index = i;
			next_index = i + 1;
			searchPalindrome(s, prior_index, next_index, max_len, start);
		}
		return s.substr(start, max_len);
	}

	void searchPalindrome(string s, int prior_index, int next_index, int& max_len, int& start) {
		int step = 0;
		while (prior_index - step - 1 >= 0 && next_index + step + 1 < s.length()) {
			if (s[prior_index - step - 1] != s[next_index + step + 1]) break;
			++step;
		}

		int width = prior_index - next_index + 1 + 2 * step;
		while(max_len < width) {
			max_len = width;
			start = prior_index - step;
		}
	}
};