class Solution {
public:
    static bool cmp(string a,string b) {
        int id1 = a.find(' ')+1;
        int id2 = b.find(' ')+1;
        bool c1 = a[id1]>='a' && a[id1]<='z';
        bool c2 = b[id2]>='a' && b[id2]<='z';
        if(!c1 && !c2)return false;
        if(c1 && !c2)return true;
        if(!c1 && c2)return false;
        return a.substr(id1)<b.substr(id2);
    }


    vector<string> reorderLogFiles(vector<string>& logs) {
        sort(logs.begin(),logs.end(),cmp);
        return logs;
    }
};
