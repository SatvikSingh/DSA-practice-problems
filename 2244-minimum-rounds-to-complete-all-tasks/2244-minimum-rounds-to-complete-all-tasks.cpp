class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size(), count = 0;
        map<int, int> map;
        
        for (int i = 0; i < n; i++) {
            map[tasks[i]]++; 
        }
        
        for (auto i : map) {
            int task_freq = i.second;
            
            if (task_freq < 2)
                return -1;
            
            count += (task_freq+2)/3;
        }
        
        return count;
    }
};