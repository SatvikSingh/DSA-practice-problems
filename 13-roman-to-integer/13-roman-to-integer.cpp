class Solution {
public:
    int values(char c) {
        if (c == 'I') 
            return 1;
        if (c == 'V') 
            return 5;
        if (c == 'X') 
            return 10;
        if (c == 'L') 
            return 50;
        if (c == 'C') 
            return 100;
        if (c == 'D') 
            return 500;
        if (c == 'M')
            return 1000;
        return 0;
    }
    
     int before(char c) {
        if(c == 'I') 
            return 1;
        if(c == 'V') 
            return 2;
        if(c == 'X') 
            return 3;
        if(c == 'L') 
            return 4;
        if(c == 'C') 
            return 5;
        if(c == 'D') 
            return 6;
        if(c == 'M') 
            return 7;
        return 0;
    }
    
    int romanToInt(string s) {
        int size = s.length();
        int ans = values(s[size-1]);   
        for(int i = size-2; i >= 0; i--) {
            if(before(s[i]) >= before(s[i+1])) {
                ans+=values(s[i]);
            }
            else {
                ans-=values(s[i]);
            }
        }
        return ans;
    }
};