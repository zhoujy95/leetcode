#pragma once

class Trie {
public:
    Trie(): children(26, nullptr), isEnd(false){

    }
    
    void insert(string& word) {
        Trie* trie = this;
        for(char &ch : word){
            int index =ch-'a';
            if(!trie->children[index]){
                trie->children[index] = new Trie();
            }
            trie = trie->children[index];           
        }
        trie->isEnd = true;
    }

    bool dfs(const string & word, int start) {
        if (word.size() == start) {
            return true;
        }
        Trie* node = this;
        for (int i = start; i < word.size(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            node = node->children[index];
            if (node == nullptr) {
                return false;
            }
            if (node->isEnd) {
                if (dfs(word, i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(string word) {
        Trie* trie = searchPrefix(word);
        return trie != nullptr && trie->isEnd;
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }
private:
    Trie* searchPrefix(const string& prefix){
        Trie* trie = this;
        for(const char &ch : prefix){
            int index =ch-'a';
            if(trie->children[index]){
                trie = trie->children[index];
            }else{
                return nullptr;
            }
        }
        return trie;
    }

    vector<Trie*> children;
    bool isEnd;
};
