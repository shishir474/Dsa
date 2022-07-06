
// variation of morre voting algo 11.in arrrays

vector<int> majorityElement(vector<int>& nums) {
        // Boyer moore voting algo
        // for all n, we wil have at max 2 possible nos which have freq greater than n/3 and at min 0 nos
        int n = nums.size();
        
        int num1=-1, num2=-1;
        int c1=0, c2=0;
        
        for(int i=0;i<n;i++){
            if (nums[i] == num1)c1++;
            else if(nums[i] == num2)c2++;
            else if (c1==0){
                num1 = nums[i];
                c1 = 1;
            }
            else if(c2==0){
                num2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        // num1 and num2 could be 2 Majority elements bt we have to check
        int freq = n/3;
        int f1 = 0, f2 = 0;  // freq of num1 and num2
        for(int i=0;i<n;i++){
            if (nums[i]==num1)f1++;
            else if(nums[i]==num2)f2++;
        }
        
        if (f1 > freq && f2 > freq) return {num1,num2};
        if (f1 > freq) return {num1};
        if (f2 > freq) return {num2};
        
        return {};
    }