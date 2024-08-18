// # sum - take xor of two number 
// # carry - then take and of two numbers and left shift that by 1
// # Repeat the process until carry becomes 0

// Intuition:
// 1^0 = 1
// 0^1 = 1
// 1^1 = 0
// 0^0 = 0
// in only first two cases we will have 1 in the curr bit.
// Now when we will have carry : Only 1 case when both bits are set and that carry should be added to the left side bit that's why we left shift a&b by 1 pos
// Now how will we determine if we are going to have a carry or not? & operation will tell us if we are going to have a carry or not


class Solution {
public:
    int getSum(int a, int b) {
        int val, carry;
        do {
            val = a^b;
            carry = (a&b)<<1;
            a = val;
            b = carry;
        }
        while(carry != 0);

        return val;
    }
};
    
// TC: O(1)
// SC: O(1)