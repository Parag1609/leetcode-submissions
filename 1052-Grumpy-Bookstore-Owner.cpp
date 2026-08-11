class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int i=0,j=0,satisfied=0,maxcustomers=0;
        for(;j<minutes;j++){
            satisfied+=grumpy[j]*customers[j];
        }
        maxcustomers=satisfied;
        while(j<n){
            satisfied+=grumpy[j]*customers[j];
            satisfied-=grumpy[i]*customers[i];

            maxcustomers=max(maxcustomers,satisfied);
            j++;
            i++;
        }
        for(int x=0;x<n;x++){
            maxcustomers+=(1-grumpy[x])*customers[x];
        }
        return maxcustomers;
    }
};