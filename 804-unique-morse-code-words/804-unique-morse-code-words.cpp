class Solution {
public:
    vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> set;
        string temp = "";
        
        for (auto s : words) {
            for (int i = 0; i < s.length(); i++) {
                temp += code[s[i] - 97];
            }
            set.insert(temp);
            // cout << temp << endl;
            temp = "";
        }

        return set.size();
    }
};