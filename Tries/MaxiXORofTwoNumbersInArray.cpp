class TrieNode{
    public:
        TrieNode* links[2];
        bool containsKey(int bit){
            return (links[bit]!=NULL);
        } 
        void put(int bit, TrieNode* node){
            links[bit]=node;
        }
        TrieNode* get(int bit){
            return links[bit];
        }
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root=new TrieNode();
        }
    public:
        void insert(int num){
            TrieNode* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit, new TrieNode());
                }
                node=node->get(bit);
            }
        }
        int getMax(int num){
            TrieNode* node=root;
            int maxi=0;
            for(int i=31;i>=0;i--){
                int bit= (num >> i) & 1;
                if(node->containsKey(1-bit)){
                    maxi=maxi | (1<<i);
                    node=node->get(1-bit);
                }
                else node=node->get(bit);
            }
            return maxi;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it:nums){
            trie.insert(it);
        }
        int ans=0;
        for(auto it:nums){
            ans=max(ans, trie.getMax(it));
        }
        return ans;

    }
};
