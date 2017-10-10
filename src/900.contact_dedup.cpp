#include<vector>
#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<int> id;
int root(int i) {
    while (i != id[i]) 
        i = id[i];
    return i;
}
bool find(int p, int q) { //check if p and q have the same root
    return root(p) == root(q);
}
void unite(int p, int q) {  //change root of p to point to root of q (smaller)
    int i = root(p);
    int j = root(q);
    if(i > j)
        id[i] = j;
    else
        id[j] = i;
}

void deduplicate(vector<pair<string, vector<string>>>& contacts, //input
                unordered_map<int, vector<string>>& res){ //output
    unordered_map<string, unordered_set<int>> emailIDmap;
    for(int i = 0; i < contacts.size(); ++i) {
        id.push_back(i);
        for(auto email : contacts[i].second)
            emailIDmap[email].insert(i); //id
    }
    for(auto email : emailIDmap) {
        for(auto p : email.second) 
            for(auto q : email.second){
                if(!find(p, q))
                    unite(p, q);
        }
    }
    for(int i = 0; i < contacts.size(); ++i) 
        res[root(i)].push_back(contacts[i].first);   
}

int main() {
    vector<pair<string, vector<string>>> contacts; //contact index id, emails
    contacts.push_back({"C1", {"shuw@fb.com", "shu@gmail.com"}});
    contacts.push_back({"C2", {"bob@fb.com"}});
    contacts.push_back({"C3", {"shu@gmail.com", "shuwu@yahoo.com"}});
    contacts.push_back({"C4", {"shuwu@yahoo.com"}});
    contacts.push_back({"C5", {"bob@fb.com"}});
    contacts.push_back({"C6", {"jamie@fb.com"}});
    unordered_map<int, vector<string>> res;      
    
    deduplicate(contacts, res);
    
    cout<<res.size()<<endl;
    for(auto v : res) {
        for(auto c : v.second)
            cout<<c<<",";
        cout<<endl;
    }
    cout<<"the end"<<endl;
    return 0;   
}
