class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int i=0,j=0,satisfied=0,maxcustomers=0;

        while(j<n){
            satisfied+=grumpy[j]==1?customers[j]:0;
            while(j-i+1>minutes){
                satisfied-=grumpy[i]==1?customers[i]:0;
                i++;
            }
            maxcustomers=max(maxcustomers,satisfied);
            j++;
        }
        for(int x=0;x<n;x++){
            maxcustomers+=grumpy[x]==1?0:customers[x];
        }
        return maxcustomers;
    }
};