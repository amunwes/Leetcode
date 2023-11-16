class Solution {
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

    Node* root = buildNode();
    
    void insert(string word) {
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
    
    void search(vector<vector<char>>& board, int row, int col, int m, int n, Node* root, string word, vector<string>& result){

        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '#'){
            return;
        }
        
        char c = board[row][col];
        Node* node = root->children[c-'a'];
        if(node == NULL)
            return;

        word += board[row][col];

        if(node->isWord){
            result.push_back(word);
            node->isWord = false;
        } 

        board[row][col] = '#';

        search(board, row+1, col, m, n, node, word, result);
        search(board, row-1, col, m, n, node, word, result);
        search(board, row, col+1, m, n, node, word, result);
        search(board, row, col-1, m, n, node, word, result);
        
        board[row][col] = c;

    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0 ; i< words.size(); i++){
            insert(words[i]);
        }
        int m = board.size();
        int n = board[0].size();

        Node* node = root;
        vector<string> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j, m, n, node, "", result);
            }
        }
        
        return result;
    }


};