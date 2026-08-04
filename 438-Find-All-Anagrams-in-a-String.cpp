class Solution {
public:
    bool allZero(vector<int>& counter) {
        for (int i = 0; i < 26; i++) {
            if (counter[i] != 0)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        if (k > n) return {};

        vector<int> counter(26, 0);

        for (char c : p)
            counter[c - 'a']++;

        vector<int> ans;

        int i = 0;

        for (int j = 0; j < n; j++) {
            counter[s[j] - 'a']--;

            if (j - i + 1 == k) {
                if (allZero(counter))
                    ans.push_back(i);

                counter[s[i] - 'a']++;
                i++;
            }
        }

        return ans;
    }
};
/*class Solution {
public:
    bool allZero(vector<int>&counter){
        for(int i=0;i<counter.size();i++){
            if(counter[i]!=0)return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>counter(26,0);
        int n=s.size();
        int k=p.size();
        if (k > n) return {};
        for(int i=0;i<k;i++){
            counter[p[i]-'a']++;
        }
        vector<int>result;
        int i,j=0;
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1==k){
                if(allZero(counter)){
                    result.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};*/