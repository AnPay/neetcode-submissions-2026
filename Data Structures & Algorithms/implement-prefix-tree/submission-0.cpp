class TrieNode {
public:
    TrieNode* children[26];
    bool isEOW;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isEOW = false;
    }
};
class PrefixTree {
public:
    TrieNode* root;  
    PrefixTree() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(char ch : word)
        {
            int idx = ch-'a';
            
            if(crawler->children[idx]==NULL)
            {
                crawler->children[idx]=new TrieNode();
                crawler=crawler->children[idx];
            }
            else
                crawler = crawler->children[idx];
        }    
        crawler->isEOW=true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(char ch : word)
        {
            int idx = ch-'a';
            
            if(crawler->children[idx]==NULL)
            {
               return false;
            }
            else
                crawler = crawler->children[idx];
        }        
        return crawler->isEOW;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        for(char ch : prefix)
        {
            int idx = ch-'a';
            if(crawler->children[idx]==NULL)
            {
               return false;
            }
            else
                crawler = crawler->children[idx];
        }  
        return true;          
    }
};
