class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int onescount=0, flipcount=0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='0'){
                if (onescount==0) continue;
                else
                    flipcount++;
            }
            else{
                onescount++;
            }
            
            if (flipcount > onescount) // update flip count 
                flipcount = onescount; // we will flip ones instead of flipping zeroes 
        }
        
        return flipcount;
    }
};

// so keep on moving until you haven't encoutered a zero and one_count > 0
// at this point you will have to perform a flip
// if at any point flip count(which indicates perform this many flips 0 to 1s to make it monotonically increasing) > one_count
// its better to flip 1s to 0's instead of flipping 0s to 1s
