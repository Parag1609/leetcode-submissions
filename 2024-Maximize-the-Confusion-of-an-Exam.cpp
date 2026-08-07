class Solution {
public:
    int maxHelper(string answerKey, int k,char ch) {
        int n=answerKey.length();
        int flipcount=0;
        int left=0,right=0;
        int maxlen=0;

        while(right<n){
            if(answerKey[right]==ch)flipcount++;
            
            while(flipcount>k){
                if(answerKey[left]==ch)flipcount--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int flipT= maxHelper(answerKey,k,'T');
        int flipF= maxHelper(answerKey,k,'F');
        return max(flipT,flipF);
    }
};