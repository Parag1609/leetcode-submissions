class Solution {
public:
    int solve(int start, int end, string& word, int k) {
        int segmentlen = end - start + 1;
        int ans = 0;
        for (int distinct = 1; distinct <= 26; distinct++) {
            int windowlen = distinct * k;
            if (windowlen > segmentlen)
                break;

            vector<int> freq(26, 0);
            int left = start;
            int charwithfreqk = 0;
            for (int right = start; right <= end; right++) {
                char ch = word[right];
                if (freq[ch - 'a'] == k) {
                    charwithfreqk--;
                }
                freq[ch - 'a']++;
                if (freq[ch - 'a'] == k) {
                    charwithfreqk++;
                }

                if (right - left + 1 > windowlen) {
                    char ab = word[left];
                    if (freq[ab - 'a'] == k) {
                        charwithfreqk--;
                    }
                    freq[ab - 'a']--;
                    if (freq[ab - 'a'] == k) {
                        charwithfreqk++;
                    }
                    left++;
                }
                if (right - left + 1 == windowlen)
                    ans += (charwithfreqk == distinct);
            }
        }
        return ans;
    }
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        if (k > n)
            return 0;
        int start = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || abs(word[i] - word[i - 1]) > 2) {
                count += solve(start, i - 1, word, k);
                start = i;
            }
        }
        return count;
    }
};