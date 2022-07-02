class Trie {
private:
    Trie* children[26];
    bool isEnd;

public:
    Trie() {
        this->isEnd = false;
        for(int i=0;i<26;i++){
            this->children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie *curr = this;
        for(int i=0;i<word.size();i++){
            int ch = word[i]-'a';
            if(curr->children[ch]==nullptr){
                curr->children[ch] = new Trie();
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
        
    }
    
    bool search(string word) {
        Trie *curr = this;
        for(int i=0;i<word.length();i++){
            int ch = word[i]-'a';
            curr = curr->children[ch];
            if(curr==nullptr) return false;
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *curr = this;
        for(int i=0;i<prefix.size();i++){
            int ch = prefix[i]-'a';
            curr = curr -> children[ch];
            if(curr==nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */