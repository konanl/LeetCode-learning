//
// Created by Yan on 2022/3/20.
//
# include<iostream>
using namespace std;

# define INT_MAX  2147483647
# define INT_MIN (-INT_MAX - 1)
class Solution{
public:
    int reverse(int x){
        int y;
        int n;
        while(x != 0){
            n = x%10;
            if(y>(INT_MAX-n)/10 || y<(INT_MIN+n)/10){
                return 0; //overflows
            }
            y = y*10 + n;
            x /= 10;
        }
        return y;
    }
};
