struct Node {
    int isLeaf = 0;
    vector<int> node;
    Node(){
        node.resize(10);
        fill(begin(node), end(node), -1);
    }
};
struct Trie{
    vector<Node> trie;
    Trie(){
        trie.emplace_back();
    }
    void add_string(string s)
    {
        int root = 0;
        for(char c: s)
        {
            int index = c-'0';
            if(trie[root].node[index] == -1)
            {
                trie[root].node[index] = trie.size();
                trie.emplace_back();
            }
            root = trie[root].node[index];
        }
        trie[root].isLeaf++;
    }
    int maxLength(string s)
    {
        int root = 0, cnt = 0;
        for(char c: s)
        {
            int index = c-'0';
            if(trie[root].node[index]==-1) return cnt;
            else
            {
                ++cnt;
                root = trie[root].node[index];
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        struct Trie t;
        int ans = 0;
        for(auto it: arr1)
        {
            string s = to_string(it);
            t.add_string(s);
        }
        for(auto it: arr2)
        {
            string s = to_string(it);
            ans = max(ans, t.maxLength(s));
        }
        return ans;
    }
};