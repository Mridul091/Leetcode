class TrieNode{
    public:
    char data;
    TrieNode ** children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++)
            children[i] = NULL;
        isTerminal = false;
    }
};
   
class Trie {
public:
    TrieNode *root;
 Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        return search(root,word);
    }
    
    bool startsWith(string prefix) {
        return startsWith(root, prefix);
    }
    private:
    void insert(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index]!=NULL ){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert(child, word.substr(1));
    }
    bool search(TrieNode* root, string word){
        if(word.size()==0){
            if(root->isTerminal == true)
            	return true;
            else return false;
        }
        int index = word[0] - 'a';
        
        if(root->children[index]!=NULL)
            return search(root->children[index],word.substr(1));
        else return false;
    }
    bool startsWith(TrieNode* root, string word){
        if(word.size()==0) return true;
        
        //Induction
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else return false;
        
        return startsWith(child, word.substr(1));
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */