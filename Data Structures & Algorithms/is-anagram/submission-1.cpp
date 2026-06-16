class Solution {
public:
    bool isAnagram(string s, string t) {
            unordered_map<char,int>mpp;
            if(s.size()!=t.size()) return false;
            for(int i=0;i<s.size();i++){
                mpp[s[i]]++;
            }
            for(int i=0;i<t.size();i++){
                mpp[t[i]]--;
            }
            for(auto it:mpp){
                if(it.second!=0) return false;
            }
            return true;
        
    }
};
