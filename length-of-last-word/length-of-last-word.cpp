#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), count = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ' ' and count > 0)
                return count;
            if (s[i] != ' ')
                count++;
        }
      return count; 
    }
};