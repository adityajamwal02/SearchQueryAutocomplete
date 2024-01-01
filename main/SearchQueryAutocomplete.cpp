/// Search Query Autocomplete Feature : Search Engine

#include<bits/stdc++.h>
using namespace std;

struct Trie{
    Trie *child[256]={nullptr};
    unordered_set<string> words;

    Trie(){}
};

struct cmp{
    bool operator()(pair<int,string> &a, pair<int,string> &b){
        if(a.first==b.first){
            string temp1=a.second, temp2=b.second;
            int result=temp1.compare(temp2);

        return result<0;
        }
    return a.first>b.first;
    }
};

class autocomplete{

private:
    Trie *root;
    string curr="";
    unordered_map<string,int> mp;
    priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;

public:

    autocomplete(vector<string> &sentences, vector<int> &times){
        root=new Trie();
        for(int i=0;i<sentences.size();i++){
            insertInto(sentences[i]);
            mp[sentences[i]]=times[i];
        }
    }

    void insertInto(string &str){
        Trie* node=root;
        for(auto ch : str){
            if(node->child[ch]==NULL){
                node->child[ch]=new Trie();
            }
            node=node->child[ch];
            (node->words).insert(str);
        }
    (node->words).insert(str);
    }

    vector<string> input(char ch){
        if(ch=='#'){
            insertInto(curr);
            mp[curr]++;
            curr="";
        return {};
        }
        vector<string> result;
        curr+=ch;
        Trie *ptr=root;
        int i=0;
        while(i<curr.size() and ptr->child[curr[i]]!=NULL){
            ptr=ptr->child[curr[i]];
            i++;
        }
        if(i==curr.size()){
            unordered_set<string> st=ptr->words;
            for(auto it : st){
                pq.push({mp[it],it});
                if(pq.size()>3){
                    pq.pop();
                }
            }
            while(!pq.empty()){
                result.push_back(pq.top().second);
                pq.pop();
            }
        reverse(result.begin(),result.end());
        }
    return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for(int i=0;i<n;i++){
            getline(cin,sentences[i]);
            cin>>times[i];
            cin.ignore();
        }
        autocomplete *obj=new autocomplete(sentences,times);
        int q;
        cin>>q;
        cin.ignore();
        for(int i=0;i<q;i++){
            string query, temp="";
            getline(cin,query);
            for(auto &it : query){
                temp+=it;
                vector<string> suggestions=obj->input(it);
                if(it=='#') continue;
                cout<<"Typed: \""<<temp<<"\", Suggestions: \n";
                for(auto &sugg : suggestions){
                    cout<<sugg<<endl;
                }
            }
        }
    }
    return 0;
}
