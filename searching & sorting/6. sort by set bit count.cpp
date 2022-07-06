Given an array of integers, sort the array (in descending order) according to count of set bits in 
binary representation of array elements. 

Note: For integers having same number of set bits in their binary representation, sort according to 
their position in the original array i.e., a stable sort.


__builtin_popcount(a) inbuilt function which returns set bit count in a 

class Solution{
    public:
    static bool cmp(int a,int b){
        int d1=__builtin_popcount(a), d2=__builtin_popcount(b);
        return d1>d2;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,cmp);
    }
};