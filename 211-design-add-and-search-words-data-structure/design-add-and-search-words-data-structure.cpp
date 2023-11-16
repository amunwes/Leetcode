class WordDictionary {
private:

    struct Node {
        bool isWord = false;
        Node* children[26];
    };


    Node* buildNode(){// helper method to build the default node
        Node* root = new Node();
        root-> isWord = false;
        for (int i = 0; i<26; i++){
            root->children[i] = NULL;
        }
        return root;
    }

    Node* root;

public:
    WordDictionary() {
        root = buildNode();
    }
    
    void addWord(string word) {
       Node* curr = root;
        for (char ch : word){
            int index = ch - 'a'; // convert char to int 0-25
            if (!curr->children[index]){//if NULL
                curr->children[index] = buildNode();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {// needs to be changed to accept .
        Node* curr = root;
        int index = 0;
        bool result = false;
        checkNode(curr, index, word, result);
        return result;
    }
    // this means i gotta build a recursive search function. 
    // it needs to check if the letter exists and if it does continue. 
    // if it doesnt then return false.
    // if it reaches the end return the bool flag.
    void checkNode(Node* curr, int index, string& word, bool& result){
        if(result)// if result is ever true we wanna just get outta there and end execution as fast as we can.
            return;
        if(index == word.size()){
            result = curr->isWord; // if we reached the end of the string check if its a word.
            return;
        }
        if(word[index] == '.'){// if current char is .
            for (int i = 0; i<26; i++){ // go through all the children
                if(curr->children[i] != NULL){// if a child isnt NUll check nodes after it.
                    checkNode(curr->children[i], index + 1, word, result);
                    if (result)
                        return;
                }  
            }
            return;
        }
        int ind = word[index] - 'a';
        if (!curr->children[ind]){// if NULL back out
            return;
        }else{
            checkNode(curr->children[ind], index + 1, word, result);
            return;
        }

    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */