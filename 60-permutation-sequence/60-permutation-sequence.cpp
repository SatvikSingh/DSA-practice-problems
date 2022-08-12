class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> temp;
        int fact = 1;
        string ans = "";
        k = k-1;
        
        for (int i = 1; i < n; i++) {
            fact = fact*i;
            temp.push_back(i);
        }
        temp.push_back(n);
        
        while (true) {
            ans += to_string(temp[k/fact]);
            temp.erase(temp.begin() + (k/fact));
            if (temp.size() == 0)
                break;
            k = k % fact;
            fact = fact / temp.size();
        }
        
        return ans;
    }
};