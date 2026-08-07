class Solution {
public:
    
    int maxConsecutiveAnswers(string answerKey, int k) {
       int countT=0,countF=0,left=0,right=0;
       int maxlen=0;
       int n=answerKey.size();
       while(right<n){
            if(answerKey[right]=='F')countF++;
            else countT++;
            while(min(countF,countT)>k){
                if(answerKey[left]=='F')countF--;
                else countT--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
       }
       return maxlen;
    }
};