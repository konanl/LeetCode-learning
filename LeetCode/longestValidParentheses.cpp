//
// Created by Yan on 2022/8/21.
//
#include<ostream>
#include<vector>
#include<string>
#include<stack>


using namespace std;


class Solution{
public:
    int longestValidParentheses(string s){
        int maxans = 0;
        stack<int> stackHelper;
        stackHelper.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stackHelper.push(i);
            }else {
                stackHelper.pop();
                if (stackHelper.empty()) {
                    stackHelper.push(i);
                }else {
                    maxans = max(maxans, i - stackHelper.top());
                }
            }
        }
        return maxans;
    }
};