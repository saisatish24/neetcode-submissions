class TrieNode{
    public: 
       bool isTerminal;
       TrieNode* children[26];

       TrieNode(){
        for ( int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
       }
};


class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for ( char ch : word){
            int idx = ch - 'a';

            if (curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isTerminal = true;
        
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for ( char ch : word){
            int idx = ch - 'a';

            if (curr->children[idx] == NULL){
                return false; 
            }
            curr = curr->children[idx];

        }
        return curr->isTerminal;
        
    }
    
    bool startsWith(string prefix) {
         TrieNode* curr = root;

        for ( char ch : prefix){
            int idx = ch - 'a';

            if (curr->children[idx] == NULL){
                return false; 
            }
            curr = curr->children[idx];

        }
        return true;
        
    }
};
