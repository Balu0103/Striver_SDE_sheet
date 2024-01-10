#include<bits/stdc++.h>
class Node{
    public:
    Node* links[26];
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
int countDistinctSubstrings(string &s)
{
    /*set<string> st;
    for(int i=0; i<s.size();i++){
        string ans="";
        for(int j=i;j<s.size();j++){
            ans+=s[j];
            st.insert(ans);
        }
    }
    return st.size()+1;
    */
    Node* root=new Node();
    int count=0;
    for(int i=0;i<s.size();i++){
        Node* node=root;
        for(int j=i;j<s.size();j++){
            if(!node->containsKey(s[j])){
                count++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return count+1;
}
