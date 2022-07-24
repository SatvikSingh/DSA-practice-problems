class Trie {
public:
    unordered_map<string, int> map;
    
    Trie() {
        
    }
    
    void insert(string word) {
        map[word]++;    
    }
    
    bool search(string word) {
        if (map.count(word))
            return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        
        for (auto i : map) {
            string temp = i.first;
            
            if (temp.substr(0, n) == prefix)
                return true;
        }
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */