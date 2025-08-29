arr[] = {2, 3, -2, 4}
ans = 6

You have to return the max product of the subarray 


Extremely Naive solution;

int maxi = INT_MIN;
for(int i = 0; i < n; i++){
    for(int j = i; j < N; j++){
        // subarray is from [i..j]
        for(int k = i; k <=j ;k++){
            prod = prod * arr[k];
            maxi = max(maxi, prod);
        }
    }
}

TC: O(n^3)  -- somewhere around n^3, not exactly n^3
SC: O(1)


Everytime you just multiply a new number. Do you actually need to run thru the entire subarray. 
No you dont need to. If we can just store a prod variable initialised with 1 and everytime you get the new value as j is moving, you get the new product by multiplying with arr[j]

with this the complexity has been trimeed down to n^2

int maxi = INT_MIN;

for(int i = 0; i < n; i++){
    int prod = 1;
    for(int j = i; j < N; j++){
        prod = prod * arr[j];
        ans = max(ans, prod);
    }
}

TC: O(n^2)
SC: O(1)


--------------------------------------------
2 optimal approaches 

1st Solution: observatoins based.

What if arr has all +ve element?  you just mul them all  
What if it has even negatives and rest all positives? again, you just mul them all  
what if you have odd negatives and rest all positives? 
    [3, 2, -1, 4, -6, 3, -2, 6] 

    Obvioulsy you dont want to multiply them all since you have got odd negatives, so overal result will become -ve. Instead I would want to ignore one negative value 
    One thing to observer here is 
    whatever you are taking -- it is either prefix or its either suffix.

    If you ignore -1 {3,2} & {4, -6, 3, -2, 6}
    If you igonre -6 {3, 2, -1, 4} & {3, -2, 6}
    If you ignore -2 {3, 2, -1, 4, -6, 3} & {6}


    So we figured out that our ans will either be in the prefix mul or in the suffix mul.


What if the arr has zeroes?
    No matter how big the mul is, if there is a 0, the final res will be 0

    {-2, 3, 4, -1, 0, -2, 3, 1, 4, 0, 4, 6, -1, 4}
    
    There is no sense in taking 0s -- so we basially partition our arr into multiple subarrays without 0
    and then whatever is the max amongst each of those, that will be my ans 
    {-2, 3, 4, -1}, {-2, 3, 1, 4}, {4, 6, -1, 4}

    so max product amogst these 3 subarrays will be my ans

// ans is essentially maximum of prefix mul or suffix mul
int maxi = INT_MIN;
int prod = 1;
// max of prefix multiplicatoin
for(int i = 0; i < n; i++){
    if(arr[i] == 0){
        prod = 1; continue;             // reset the value of prod because we are starting off new subarray
    }
    // prefix_mul
    prod = prod * arr[i];
    maxi = max(maxi, prod);
}
// maxi stores the max value in the prefix multiplication


prod = 1;
for(int i = n-1; i>= 0; i--){
    if(arr[i] == 0){
        prod = 1; continue;             // reset the value of prod because we are starting off new subarray
    }
    prod = prod * arr[i];
    maxi = max(maxi, prod);
}
// maxi stores max value amongst prefix_mul and suffix_mul

return maxi;


2 for loops for calculating the prefix and suffix mul 
TC: O(2*n) = O(N)
SC: O(1)


Better code:
once you go from the front to find the prefix mul 
and once you go from the back to find the suffix mul 

I can actually do this in one go 

// calculating the prefix and suffix mul in one go
int maxi = INT_MIN;

int pre = 1, suff = 1;
for(int i = 0; i < n; i++){
    if(pre == 0) pre = 1;             // if prefix becomes 0, turn it back to 1 (we are starting new subarray)
    if(suff == 0) suff = 1;             // if suffix becomes 0, turn it back to 1 (we are starting new subarray)
    pre = pre * arr[i];
    suff = suff * arr[n - 1 - i];
    maxi = max({maxi, pre, suff});
}

return maxi;

TC: O(N)        -- much much better than the previous solution 
SC: O(1)