#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	/*
	
		����˵��ʲô�ǻ��Ĵ�����������������һ�����ַ��������� "bob", "level", "noon" �ȵȡ�
		��ô������Ӵ�������һ���ַ����е��Ǹ���Ļ����Ӵ���
		����֪����ͳ����֤���Ĵ��ķ����������������ĶԳ���֤�Ƿ���ȣ�
		��ô�����һ����ִ������⣬��Ҫ��ÿһ���ַ�Ϊ���ģ���������ɢ��Ѱ�һ��Ĵ���
		����㷨��ʱ�临�Ӷ���O(n*n)��
		����Ҫע����ż�����
		���ڻ��Ĵ��ĳ��ȿ����ż������"bob"��������ʽ�Ļ��ģ�
		"noon"����ż����ʽ�Ļ��ģ�������ʽ�Ļ��Ķ�Ҫ������

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