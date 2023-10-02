#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class letterNode {
    public:
    int count;
    char letter;
    letterNode(char letter, int count):letter(letter),count(count){}
};

class comp {
    public:
    bool operator()(letterNode* l1, letterNode* l2){
        if(l1->count==l2->count)return l1->letter>l2->letter;
        return l1->count<l2->count;
    }
};

string solve(string str){
    priority_queue<letterNode*,vector<letterNode*>,comp>maxHeap;
    unordered_map<char,int>freqMap;
    for(unsigned int i=0;i<str.size();i++){
        freqMap[str[i]]+=1;
    }
    for(auto &elem:freqMap){
        maxHeap.push(new letterNode(elem.first,elem.second));
    }
    string ans;
    while(!maxHeap.empty()){
        letterNode *node = maxHeap.top();
        maxHeap.pop();
        int count = node->count;
        char letter = node->letter;
        for(unsigned int i=0;i<count;i++)ans.push_back(letter);
    }
    return ans;
}

int main(){

    string str = "scaleracademy";
    cout << solve(str) << endl;
    return 0;
}