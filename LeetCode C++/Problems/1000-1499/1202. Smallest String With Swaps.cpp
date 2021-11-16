class Solution {
public:
    vector<int> father;
    vector<int> size;
    int Find(int a){
        if (a == father[a]) return a;
        return father[a] = Find(father[a]);
    }
    void Union(int x, int y){
        int a = Find(x), b = Find(y);
        if(a < b)
            swap(a,b);
        size[a]++;
        father[b] = a;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        father.resize(n, 0);
        size = vector<int>(n, 0);
        for(int i = 0; i < n; ++i)
            father[i] = i;
        for(auto & p : pairs)
            Union(p[0],p[1]);
        vector<string> groups(s.length());

        for (int i=0; i<s.length(); i++)
            groups[Find(i)].push_back(s[i]);

        for (auto& v:groups)
            sort(v.begin(), v.end(), greater<char>());

        for (int i=0; i<s.length(); i++) {
            int p = Find(i);
            s[i] = groups[p].back();
            groups[p].pop_back();
        }

        return s;
    }
};
