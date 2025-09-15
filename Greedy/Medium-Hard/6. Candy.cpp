There are n students, each has some ratings. You need to distribute candies to these students such that:
each student gets atleast 1 candy
a student with higher rating than his adjacent student(s) gets more candies than them

ex: arr[0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0]

if I look just towards the left side 
candiesLeft:[1, 2, 3, 1, 1, 1, 1, 2, 3, 4, 1, 1, 1]

This is how the candies distribution will look like if I just look towards the left side

1st person: no person exists on left side -- so give 1 candy
2nd person: 2 > 0 -- so give 1 + 1 = 2 candies
3rd person: 4 > 2 -- so give 2 + 1 = 3 candies
4th person: 3 < 4 -- so give 1 candy
5th person: 2 < 3 -- so give 1 candy
...
The idea is if ratings[i] > ratings[i-1] : then we give him atleast 1 more candy than the person on the left side
else we give him bare minimum 1 candy

Now if I look just towards the right side
candiesRight:[1, 2, 3, 2, 1, 1, 1, 2, 3, 4, 5, 1, 1]

This is how the candies distribution will look like if I just look towards the right side

Last person: no person exists on right side -- so give 1 candy
2nd last person: 0 == 0 -- so give 1 candy
3rd last person: 4 > 0 -- so give 1 + 1 = 2 candies
4th last person: 6 > 4 -- so give 2 + 1 = 3 candies
5th last person: 5 < 6 -- so give 1 candy
...
The idea is if ratings[i] > ratings[i+1] : then we give him atleast 1 more candy than the person on the right side
else we give him bare minimum 1 candy

Since I need to satisfy both left and rigth -- I''ll take the max of candiesLeft[i] and candiesRight[i]
candies[i] = max(candiesLeft[i], candiesRight[i])

vector<int> left(n), right(n);
left[0] = 1;
for(int i = 1; i < n; i++){
    if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
    else left[i] = 1;
}
right[n-1] = 1;
for(int i = n - 2; i >= 0; i--){
    if(ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
    else right[i] = 1;
}
int sum = 0;
for(int i = 0; i < n; i++){
    sum += max(left[i], right[i]);
}
return sum;

TC: O(3n)
SC: O(2n)


--------------------

Optimised solution:
I can compute the right array on the fly while calculating the final ans

vector<int> left(n);
left[0] = 1;
for(int i = 1; i < n; i++){
    if(ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
    else left[i] = 1;
}

// curr signifies the value for the current index 
int right = 1, curr = 1, sum = 0;

// covering the last index 
sum += max(left[n-1], 1);       // right[n-1] is 1, hence taking max(left[n-1], 1) for (n-1)th index 
for(int i = n - 2; i >= 0; i--){
    if(ratings[i] > ratings[i+1]) curr = right + 1;
    else curr = 1;

    // update : curr will become right for the next iteration
    right = curr;
    sum += max(left[i], right);
}    

return sum;

TC: O(2n)
SC: O(n) 


-----------------------------------------------------

Most Optimised solution: Using the concept of slopes 

either its going to be flat surface, or a slope(increasing or decreasing)
For increasing slope: we track the peak(the max value which we acheived on this slope)
For decreasing slope: we track the down(the max down value which we acheived on this slope)
If down > peak: this means the peak value will be replaced with down -- effectively adding (down - peak)

// Insane Optimisation technique

int i = 1, sum = 1;
while(i < n){
    // if its a flat surface
    if(ratings[i] == ratings[i-1]){
        sum+=1; i++; continue;
    }

    // we're starting a slope: can be either increasing or decreasing 
    // increasing slope
    int peak = 1;
    while(i < n && ratings[i] > ratings[i-1]){
        peak++; sum += peak; i++;
    }

    // decreasing slope
    int down = 1;
    while(i < n && ratings[i] < ratings[i-1]){
        sum += down; down++; i++;
    }

    // if down > peak, we replace the peak value in the sum with down -- effectively adding (down - peak)
    if(down > peak){
        sum += (down - peak);
    }
}

return sum;


TC: O(n)    -- From the naked eye it might look like that the TC is n^2, because of nested loops, but each element is processed exactly once. 
SC: O(1)    -- we are not using any extra space


***************************************************************************

NOTES:
1st condition: each student must get atleast 1 candy
2nd condition: For ith student, if his rating is > neighbours ratings -- then ith student must get more candies than his nb

Solution:
step1: find the candy distribution if we just consider the left child 
step1: find the candy distribution if we just consider the right child 
step3: since we need to compare with both left and right childs, assign max(left[i], right[i]) candies to ith child. This ensures that both left and right childs are satisfied.

3 for loops: for constructing left[], right[] and final ans computation
TC: O(3n) SC: O(2n) left[] and right[]

-------------------------------------------------
Optimisation 1:
We can get rid of right[] by performing the calculations on the fly.
construct the left[]
For right part, take 2 variables curr & right. curr signifies the candies which will be assigned to ith child given that we are only considering right child for comparison
right signifies the candies assigned to i+1 th child 

2 for loops: for constructing left[], and for computing right & final ans
TC: O(2n) 
SC: O(n) left[]
-------------------------------------------------

Optimisation 2: Using slopes concept 
Jot every value in the form of slopes. Now either it will be a flat line, increasing slope or decreasing slope.

If its a flat surface ie ratings[i] == ratings[i-1], we assign 1 candy and move to i+1 

if its not flat -- then it has to be a slope
increasing slope: we track the peak value which is acheived during this journey
decreasing slope: we track the down value which is acheived during this journey. We are assigning down =1,2... on decreasing slope which is not right if we see from distribution perspective. But since we dont care about the distribution and are only concerned with summation of candies assigned -- this will work
if down > peak: then it means the downward slope is greater than increasing slope, and thus the peak element should be assigned down candies -- which effectively means adding down - peak more candies since we already assigned peak.


***************************************************************************