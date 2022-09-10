class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;  
        
        for(auto i : s1) {
            map[i]++;
        }
        
        int count = map.size();
        int i = 0, j = 0;
        int k = s1.size();
        
        while(j < s2.size()) {
            if(map.find(s2[j]) != map.end()) { 
                map[s2[j]]--;
                
                if(map[s2[j]] == 0) { 
                    count--;
                }
            }
            
            if(j-i+1 < k) {
                j++;
            }
            
            else if(j-i+1 == k) {
				if(count == 0) {     
					return true;  
				}
                
                if(map.find(s2[i]) != map.end()) {  
                    map[s2[i]]++;
                    
                    if(map[s2[i]] == 1) {
                        count++;
                    }
                }
                
                i++;
                j++;
            }
        }
        return false;
    }
};