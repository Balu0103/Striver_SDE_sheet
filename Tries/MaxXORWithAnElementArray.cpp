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
        void insert(int num){
            TrieNode* node=root;
            for(int i=31;i>=0;i--){
                int bit= (num>>i)&1;
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
                int bit=(num>>i)&1;
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> offlineQueries;
        for(int i=0;i<q;i++){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i }});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(q,-1);
        int ind=0;
        Trie trie;
        for(int i=0;i<q;i++){
            int mi=offlineQueries[i].first;
            int xi=offlineQueries[i].second.first;
            int qInd=offlineQueries[i].second.second;
            while(ind<n && nums[ind]<=mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qInd]=-1;
            else ans[qInd]=trie.getMax(xi);
        }
        return ans;
    }
};
