Find the missing and repeating integer

You wil be given an array of n ingeters. This integers will be from 1 to n. You have to find the missing and the repeating integer.

arr[] = {4,2,6,3,1,1}

4 approaches
 

Extreme brute force:

Extreme naive solution that I can think of is, I know one thing for sure that all the integers belongs to range 1 to N 
So what Ill do is , Ill probably loop from 1 and check its count. Ill find out that 1 appears twice, so I can say that 1 is a repeating no 
Then Ill go to 2 and  iterate over the entire array, willl find that it appears once, then check for 3 and so on so forth.

So Ill check for each no from 1 to N and determine its count. If the count is 2 then that is the repeating no, or else if the count is 0, its a missing no.
// check for each no from 1 to n if it is a missing / repeating 
[1, n]

int missing = -1, repeating = -1;
for(int i = 1; i<= n; i++){
    int count = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] == i) count++;
    }
    if(count == 2) repeating  = i;
    else if(count == 0) missing = i;

    if(missing != -1 && repeating != -1) 
        break;
}

What is the time complextiy? Pretty straightforward. We are running 2 nested loops and that will be n^2
TC: O(n^2)
SC: O(1) -- Are we using any extra space? No we are not apart from the 2 variables missing and repeating. And this is going to be constant O(1)

--------------------------------------
Better 
So we have to improve n^2

We are counting right? So whenever something like counting comes up. What is the technique that we use to optimise?
We know that for sure, we use something like hashing.

So here can we hash elements and keep a track of how many times did they appear? We can 

We know one thing for sure that all the nos will be in the range [1,N]. So I can declare a hasharray. We dont need a map for this

int hash[n+1] = {0}
for(int i = 0; i < n; i++){
    hash[arr[i]]++;
}

int missing = - 1, repating = -1;
for(int i =1; i<= n; i++){
    if(hash[i] == 0) missing  = i;
    else if(hash[i] == 2) repeating = i;
    
    if(missing != -1 && repeating != -1) 
        break;
}
return {repeating, missing};

We are iterating from [1,N] twice
TC: O(2*n) = O(n)
SC: O(N)


------------------------------------------------------------------------------

Optimal solution 

We have 2 optimal solutions. First one is purely based on maths, second one uses xor logic (bit complicated)

Ill take 2 variables x -> repating &. y-> missing 
arr = {4,3,6,2,1,1}

Ill essentially calcualte the differnce between the sum of nos in the arr and sum of first n natural nos 

 sum of first n natural nos  = (n * (n + 1) )/ 2

(4 + 3 + 6 + 2 + 1 + 1) - (1 + 2 + 3 + 4 + 5 + 6) 
1 - 5 = -4 

If you will notice this is actually
x - y = -4      -- eqn 1 

In order to solve this equation with 2 variable, I need one more equation. 

Lets find the difference between sum of squares of nos in arr and sum of sqaures of first n natural __STDC_NO_THREADS__

(4^2 + 3^2 + 6^2 + 2^2 + 1^2 + 1^2) - (1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2) 
1^2 - 5^2 = -24
x^2 - y^2 = -24     -- eqn 2 

(x - y) * (x + y) = -24
x + y = -24/(x-y) = 6

2 equations, 2 variables and now you can easily solve them 

2*x = 2
x = 1
y = 5 




while writing int x = a * b where a and b are integers, the way this multiplication is performed is first we multiple a and b and since both are integers, the final res will be stored in an integer temp variable which is then later assinged to x.

If this multiplication value goes out of bounds of integer, then the temp int variable will contain incorrect vallue and the same will reflect in x.
Hence it is important to typecast atleast one operand to long long 


long long s = 0, ss = 0;
for(int i = 0; i < n; i++){
    s += arr[i];
    ss += (long long)arr[i] * (long long)arr[i];        // make sure you convert this to long long to avoid integer overflows
}

long long sum_of_first_n = (n * (n + 1))/ 2;
long long sum_of_squares_of_first_n = (n * (n + 1) * (2*n + 1)) / 6;

long long x_minus_y;
long long diff1 = x_minus_y = s - sum_of_first_n
long long diff2 = ss - sum_of_squares_of_first_n;

long long x_plus_y = diff2/diff1;
long long x = (x_plus_y + x_minus_y)/2;
long long y = x - diff;

return {(int)x, (int)y};        // convert the res back to int while returning


Just ran 1 loop O(N)
TC: O(n)

no extra space being used 


SC: O(1)


-----------------------------------------------------------------------

Optimal Solution -- Using xor   --- pending revisit   (intuition)

arr[] = {4,3,6,2,1,1}

xor all the nos of the array and nos from (1 to n)

x --> repating, y --> missing

(4 ^ 3 ^ 6 ^ 2 ^ 1 ^ 1) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6) = 4

If you will notice properly, this gives us 1 ^ 5 = 4
x ^ y = 4

I know one thing for sure that x and y are different integers, so they are bound to differ at atleast 1 bit position 

1 -> 001
5 -> 101

So I know the differentiating bit is 2 

Summary:
1. Go thru all the nos in the arr and xor with (1^2^..n) = num 
    This num is essentially x ^ y i.e x ^ y = num 
2. Find a differentiating bit in num. Differentiating bit will always provide you 1 
Find the first 1 from the right
(xor between the same bits will always give you 0)
    
3. Once you have found the differentiating bit, group the nos from arr and (1 to n) into 2 parts.
First part will contain all those nos which has 0 at the differentiating bit and the second part will contain nos which has got 1 at the differentiating bit position 

4. Take xor part1, Take xor of part2.
5. You will end up with 2 values (x,y). These are my answers. We just dont know out of them which one is missing & which one is repeating 
Now we need to cross check which one amongst  them is repeating. 
So iterate over the arr and check if x is repeating 


int val = 0;
for(int i = 0; i < n; i++){
    val = val ^ arr[i];
    val = val ^ (i+1);
}

// val = x ^ y
// finding differentiating bit -- look for the rightmost set bit 
int pos = -1;                   /// position of the set bit
for(int i = 0; i < 31; i++){
    if(val&(1<<i)){             // find the first set bit from the right
        pos = i; break;
    }
}


vector<int> part1, part2;       // part1 stores all nos which has 0 at pos position
                                // part2 stores all nos which has 1 at pos

// no need of storing this nos in part1 & par2. In the end we're just calculating the xor of part 1 and part 2
// will use 2 variables zero and one 

int zero = 0, one = 0               // zero stores the xor of all elements that have 0 at pos
                                    // one stores the xor of all elements that have 1 at pos
for(int i = 0; i< n ;i++){
    // check if pos bit is set in arr[i] and (i + 1)
    if(arr[i] & (1<<pos)) one = one ^ arr[i];
    else zero = zero ^ arr[i];

    if((i+1) & (1<<pos)) one = one ^ (i + 1); 
    else zero = zero ^ (i + 1); 
}

// zero and one will finally be our x and y
int x = zero, y = one

// take xor of part1 and part2 ;
// int x = 0, y = 0;
// for(int i = 0; i < part1.size(); i++){
//     x = x ^ part1[i];
// }
// for(int i = 0; i < part2.size(); i++){
//     y = y ^ part2[i];
// }

// verify which amongst x and y is missing and repating 
int count = 0;
for(int i = 0;i < arr.size(); i++){
    if(arr[i] == x) count++;
}
if(count == 2){
    // x repeating, y missing
    return {x,y};
}
else return {y,x};






Why this solution work?

TC: O(n)
SC: O(1)
