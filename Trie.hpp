#program once
class Trie {
public:
    Trie(): childern(26, nullptr), isEnd(false){

    }
    
    void insert(string word) {
        Trie* trie = this;
        for(char &ch : word){
            int index =ch-'a';
            if(!trie->childern[index]){
                trie->childern[index] = new Trie();
            }
            trie = trie->childern[index];           
        }
        trie->isEnd = true;
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
            if(trie->childern[index]){
                trie = trie->childern[index];
            }else{
                return nullptr;
            }
        }
        return trie;
    }

    vector<Trie*> childern;
    bool isEnd;
};
