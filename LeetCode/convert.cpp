#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    string convert(string s, int numRows){
        if(numRows == 1){
            return s;
        }
        int sSize = int(s.size());
        int storeSize = min(sSize, numRows);
        vector<string> store(storeSize);
        bool change = false;
        int loc = 0;
        string result;

        for(int index=0;index<sSize;index++){
            store[loc].push_back(s[index]);
            if(loc == numRows - 1 || loc == 0){
                change = !change;
            }
            loc += change?1:-1;
        }

        for(int index=0;index<storeSize;index++){
            result += store[index];
        }
        return result;
    }
};

