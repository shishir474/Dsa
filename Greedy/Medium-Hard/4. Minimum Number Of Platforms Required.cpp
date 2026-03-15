Given arrival and departure times of all trains that reach a railway station, 
find the minimum number of platforms required for the railway station so that no train waits.
     We are given two arrays which represent arrival and departure times of trains that stop.

 Input: n = 6 
arr[] = {0900, 0945, 0955, 1100, 1500, 1800}
dep[] = {0920, 1200, 1130, 1150, 1900, 2000}

sorting arrivals and departure arrays. Take 2 pointer i and j and perform steps for mergin 2 sorted arrays.

                          i
{0900, 0945, 0955, 1100, 1500, 1800}
  
        j
{0920, 1130, 1150, 1200, 1900, 2000}

cnt = 3


Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.

When the 1st train arrives, I just need 1 platform 
p1 - [0900 - 0920]

idx = 1 
Next train arrives at 0945. Do I need a platform no 2? No I dont need because [0900 - 0920] will depart at 0920 from platform 1.
Hence p1 can be reused 
p1 = [0945 - 1200]

idx =2 This one is going to arrive at 0955. Can it arrive at platform No 1? No it cannot because there already is a train from 0945 to 1200 
p1 = [0945 - 1200]
p2 = [0955 - 1130]

idx = 3
This train arrives at 1100
can it go to platform no 1? No 
can it go to platform no 2? No 

p1 = [0945 - 1200]
p2 = [0955 - 1130]
p3 = [1100 - 1150]

idx = 4
This train arrives at 1500 
All of the three platforms will be empty at this point. This one can go to any platform. Assuming it went to p1 
p1 = [1500 - 1900]
p2 = [0955 - 1130]
p3 = [1100 - 1150]

idx = 5
This train arrives at 1800 
This one can go to platform 2 or 3. Assuming it went to p2
p1 = [1500 - 1900]
p2 = [1800 - 2000]
p3 = [1100 - 1150]


So if we look at the entire day schedule, whats the max no of platforms we needed? 
At max if we have 3 platforms, we can have all the trains arriving & departing.

Do we need a 4th platform? 4 will also work, but that will be overkill because whats the use of the 4th platform? 
The question is asking minimum no of platforms that will be able to accomodate all the trains

Over here, I can say 3 platforms will be enough, because at the worst case, there are 3 trains which are intersecting in terms of arrival time & in terms of departure time.


***************
Brute force:

Because the arrival times and departure times, if you carefully notice for idx 1,2,3 are intersecting at some point. That is why we needed 3 platforms to accomodate these 3 trains (1,2,3)

So If I figure out the maximum no of intersections -- I think that will be doable 

So what I''ll do is, I''ll pick the 1st train (as part of extremen naive solution). Is this train intersecting with anyone else?
No. So this train will require at max 1 platform.

arr[] = {0900, 0945, 0955, 1100, 1500, 1800}
dep[] = {0920, 1200, 1130, 1150, 1900, 2000}

Lets take 2nd train. Is this train intersecting with anyone else?
yes, with train 2 and 3 & thus we need 3 platforms.

Similarly if you take 3rd train. It is intersecting with 2nd and 4th train 
& 4th train is intersecting with 2nd and 3rd train 

So by seeing this, what I can say is -- at max the number of intersections that I did see was 3. Thats it -- done & dusted.

Intersection scenarios - 4 cases possilbe
           arr              dep
            .----------------.
        .----------.                    -- arriving before, departing mid 
        .-------------------------.     -- arriving before, departing later 
                .--------------------.  -- arrived mid, departing later 
               .---------.              -- arrived mid, departing mid


So we'll have to 4 cases when you are considering a case of intersection 

I''ll be given the arrival time and departure time. What do I need to do? 
Just need to find the max intersection at any point. So maybe I can keep a max_cnt = 0
I''ll start from the 1st platform(super simple) and I''ll go on till the last one & I''ll start checking how many intersections does it have.
For the train itself, it will require a platform. So we can keep the cnt as 1.
We'll start comparing j = i+1 go up till n - 1 & I''ll have the intersection check.
If it is intersecting, we'll do a cnt++ & whenever there is a cnt++ or maybe after this we can do max_cnt = max(max_cnt, cnt)
Thats it. We can end both the for loops and at the end of the day what we can do is we can end up returning the max count and that will be the maximum rather the minimum number of platforms required to accommodate all the n trains.

again this is a Brute Force we can definitely optimize, slightly here and there but this is going to be the extreme naive solution that comes to my brain and if I implement this what will be the TC: a O(n) for outer for loop, 
near about O(n) for inner for loop.  so can I say that the time complexity will be somewhere around n^2.
I definitely can and can I say that the space complexity will be somewhere around O(1) because not using any external space.

** NOTE: Brute force is incorrect **

int f(vector<int> &arr, vector<int> &dep){
    int max_cnt = 0;
    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = i; j < n; j++){
            if(isIntersecting(arr[i],dep[i],arr[j],dep[j])){
                cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        }
    }

    return max_cnt;
}

***********************************************************
NOTE: This is partially right in the brute force because what we have to do is we have to count the maximum number of trains that can be present at the station at a particular time , suppose if you have 5 trains and 1 train is intersecting with all the other 4 , so it
does not mean that we might need 4 platforms because the maximum number of intersection is 4 for that big train , but its possible that the other train donot intersect with each other , in that case we will be needing only 2 platforms

0900                                                               1200
.------------------------------------------------------------------.
.----------.   .--------------.  .-----------.  .------------------.
           930 945          1015 1030      1100  1105.            1200 
***********************************************************

We need to optimise this algorightm.
this is a clear indication that the algorithm that we are looking for will be somewhere around nlogn or a O(N)


arr[] = {0900, 0945, 0955, 1100, 1500, 1800}
dep[] = {0920, 1200, 1130, 1150, 1900, 2000}


So how do I optimize this now in the real world what I''ll do is I''ll go outside the railway station and I''ll start observing as the time passes by so I see that the train number one arrives at 9:00. 
This is the first time that we see something happening so the train number one will arrive and it will take the platform number one or whatever platform we can assign it.
As the clock ticks by. what is the next time that you see 9:20. At 0920 again something is happening and that is the train number one leaving.

Platform is empty what is the next time 9:45 is when the train number two arrives.
As the clock ticks by, 9:55 the train number three arrives. As the clock passes by 11:00 the train number four arrives. as the as the clock passes by what is the next 11:30

0900 0920 0945 0955 1100 1130 1150 1200 1500 1800 1900 2000
A.    D    A    A    A    D    D   D     A     A     D   D 

Throughout the journey, you did see that at max we required 3 platforms. 
So what am I doing? I''m standing & observing as the time passes by. SO can I sort everything according to time, then it will be easy.

So if I sort everything according to time, what will happen is, I''ll get something like
(0900,A) (0920,D) (0945,A) (0955,A) (1100,A) (1130,D) (1150,D) (1200,D) (1500,A) (1800,A) (1900,D) (2000,D)

I can keep a cnt variable intialized with 0, because when I arrived at the railway station, the cnt will be 0.
0900 is the first train arrives, it will require a platform, cnt++
At 0920, we have a departure, so one platform released, cnt--; 
At 0945, we have a arrival, so we need 1 platform, cnt++;
At 0955, we have a arrival, so we need 1 platform, cnt++;
At 1100, we have a arrival, so we need 1 platform, cnt++;
At 1130, we have a departure, so one platform released, cnt--; 
At 1150, we have a departure, so one platform released, cnt--; 
At 1200, we have a departure, so one platform released, cnt--; 
At 1500, we have a arrival, so we need 1 platform, cnt++;
At 1800, we have a arrival, so we need 1 platform, cnt++;
At 1900, we have a departure, so one platform released, cnt--; 
At 2000, we have a departure, so one platform released, cnt--; 

Eventually throughout the journey, the max cnt that we'll figure out is 3, hence we need 3 platforms.


NOTE: 
What I can typically do is, combine the arrival & departure and putting them into a 3rd array. But this will require an external space.

I can do this in the same array -- no extra space needed. Because what I require is time in sorted fashion.

I''m not concerned with arrivals and departures staying together. This means I can individaully sort arrival[] and departure[] and initialise cnt = 0;
Take 2 pointers i=0 and j=0 for arrivals and departures


int maxi = 0, cnt = 0;
sort(arrivals.begin(), arrivals.end());
sort(departures.begin(), departures.end());
int i = 0, j = 0;
while(i < n && j < n){  // 
    if(arrrival[i] <= departure[j]) {
        cnt++; i++;
    }
    else {
        cnt--; j++;
    }
    maxi = max(maxi, cnt);
}

return maxi;

// This while loop is 2*n we are iterating in 2 arrays sometimes in arr, sometimes in departure

TC: nlogn + nlogn + 2*n
SC: O(1). -- I''m distorting the input array.
If we dont want to distort the input array, we can follow the other approach -- create a 3rd array and store the arrival and departure in it.



*********************************************************************************

NOTES: 

Minimum no of platforms required is essentially the max no of intersections that we have at any point in time. Those many platforms will be required. 

Intersection scenarios - 4 cases possilbe
           arr              dep
            .----------------.
        .----------.                    -- arriving before, departing mid 
        .-------------------------.     -- arriving before, departing later 
                .--------------------.  -- arrived mid, departing later 
               .---------.              -- arrived mid, departing mid

0900                                      T1                                                            1200
.------------------------------------------------------------------.
    T2.                    T3.                    T4                       T5
.----------.   .--------------.  .-----------.  .------------------.
           930 945          1015     1030      1100  1105.            1200 
ans = 2

I need to find max no of intersections at a given point and that will be your ans. Here it is 2.

The sol which I thought -- I was finding the max no of interactions amongst trains. For instance, T1 has intersections with 4 trains, but that doesn't mean we need 4 platforms. These interesections are happending at different instance. To be more precise, I'm interested in knowing the max no of itneresections that are happening at a given time, which is 2 here in this case.


Now how can I find the max no of interesections at a given time. Lets traverse on time in increasing order
At 0900 T1 arrivaes cnt++ ->  cnt = 1
At 0900 T2 arrives cnt++ ->  cnt = 2
At 0930 T2 departs cnt-- ->  cnt = 1
At 0945 T3 arrives cnt++ ->  cnt = 2
At 1015 T3 departs cnt-- ->  cnt = 1
At 1030 T4 arrives cnt++ ->  cnt = 2
At 1100 T4 departs cnt-- ->  cnt = 1
At 1105 T5 arrives cnt++ ->  cnt = 2
At 1200 T5 departs cnt-- ->  cnt = 1

The max value of cnt during the entire day was 2, this gives us the max no of intersections that is happening at any given time. Hence 2 platforms is required to accomodate all trains.

You just need to traverse on the time array and know whether the time is arrival or departure. Create 3 rd array -- insert all elements from arrival & departure. Sort the array on time. Added 'A' & 'D' to differentiate whether the time is arrival or departure
(arr[i], 'A') (dep[i], 'D')

Other sol is sort both arrival & departure array. and use the logic of merging 2 sorted arrays. 
Take 2 pointers i = 0, j = 0 for arrival and departure.
But this approach will distort the input array. ---- Let the interviewer know about this)

*********************************************************************************