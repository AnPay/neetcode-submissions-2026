class Word{
    public:
        Word* children[26];
        bool isEOW;

        Word(){
            for(int i =0;i<26;i++)
                children[i]=NULL;
            isEOW=false;
        }
};
class WordDictionary {
public:
    Word* root;
    WordDictionary() {
        root=new Word();
    }
    
    void addWord(string word) {
        Word* temp = root;
        for(char ch : word)
        {
            int idx = ch-'a';
            if(temp->children[idx]==NULL)
            {
                temp->children[idx]= new Word();
               // temp = temp->children[idx];
            }
            temp = temp->children[idx];
        }   
        temp->isEOW=true; 
    }
    
    bool dfs(Word* node, string& word, int idx)
    {
        if(idx == word.length())
            return node->isEOW;
        if(word[idx]!='.')
        {

            if(node->children[word[idx]-'a']==NULL)
                return false;
            else
                 return dfs(node->children[word[idx]-'a'],word,idx+1);
        }
        else{
            for(int i =0;i<26;i++)
            {
                if(node->children[i]!=NULL)
                    if (dfs(node->children[i],word,idx+1))
                        return true;
            }
            return false;
        }
    }
    bool search(string word) {
        return dfs(root,word,0);
    }
};
