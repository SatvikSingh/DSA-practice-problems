class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp1 = "", temp2 = "";
        
        for (auto s : word1) {
            temp1 += s;
        }
        
        for (auto s : word2) {
            temp2 += s;
        }
        
        if (temp1 == temp2)
            return true;
        else
            return false;
    }
};