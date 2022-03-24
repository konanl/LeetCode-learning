//
// Created by Yan on 2022/3/24.
//
//https://leetcode-cn.com/problems/palindrome-number/comments/

#include <iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        if(x<0){
            return false;
        }else if(x%10 == 0){
            return false;
        }
        int i = x;
        int y;
        int n;
        while(i != 0){  //回文数必然不越界
            n = i % 10;
            y = y*10 + n;
            i /= 10;
        }
        if(x == y){
            return true;
        }else{
            return false;
        }
    }
};
