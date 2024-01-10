#include <bits/stdc++.h> 
class Node{
    public:
        Node* links[26];
        int cntEndWith;
        int cntPrefix;
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        void put(char ch, Node* node){
            links[ch-'a']=node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void increaseEnd(){
            cntEndWith++;
        }
        void increasePrefix(){
            cntPrefix++;
        }
        int getEnd(){
            return cntEndWith;
        }
        int getPrefix(){
            return cntPrefix;
        }
        void deleteEnd(){
            cntEndWith--;
        }
        void reducePrefix(){
            cntPrefix--;
        }
    };
class Trie{
    private:
        Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else return;
        }
        node->deleteEnd();
    }
};
