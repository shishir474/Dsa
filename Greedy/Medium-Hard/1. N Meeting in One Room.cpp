start[] = {0, 3, 1, 5, 5, 8}
end[] =   {5, 4, 2, 9, 7, 9}

You have been given 1 room in which only 1 meeting can take place at a time. 
We have to figure out the max no of meetings that can take place.

-- In order to maximise the no of meetings - we'll prioritize the meetings that are ending first 
-- hence sorting the array on basis of end times 

My intuition will be greedy, I''ll try to take the meetings that are ending faster.

I''ll take a data structure like a vector and will store (start_time, end_time, position)
-- Interviewer might ask for the positions as well

Sorting on the end times 
0           1       2       3        4          5
(1,2,3), (3,4,2), (0,5,1), (5,7,5), (5,9,4), (8,9,6)

cnt = 1;        -- 1st meeting can definitely be taken 
free_time = 2   -- time at which the room becomes free 

I''ll start iterating from the 1st index
i = 1
Can I take this meeting? 
    In order to take this my start time of the current meeting > free_time -- then only I can take this meeting 
    and this is true, so update the free_time to end time of current meeting 
free_time = 4, 
cnt = 2

i = 2;
Can I take this meeting? 
    In order to take this my start time of the current meeting > free_time -- then only I can take this meeting 
    and this is false, so I cannot take this meeting 
free_time = 4, 
cnt = 2

i = 3
Can I take this meeting? 
    In order to take this my start time of the current meeting > free_time -- then only I can take this meeting 
    and this is true, so update the free_time to end time of current meeting 
free_time = 7, 
cnt = 3

i = 4 
Can I take this meeting? 
    In order to take this my start time of the current meeting > free_time -- then only I can take this meeting 
    and this is false, so I cannot take this meeting 
free_time = 7, 
cnt = 3

i = 5 
Can I take this meeting? 
    In order to take this my start time of the current meeting > free_time -- then only I can take this meeting 
    and this is false, so I cannot take this meeting 
free_time = 9, 
cnt = 4

// defined the comparator for custom sorting logic
struct compare{
    bool operator()(const vector<int> &v1, const vector<int> &v2){
        return v1[1] < v2[1];
    }
}
vector<vector<int>> meetings;
for(int i = 0; i < n; i++){     // O(n)
    meetings.push_back({start[i], end[i], i+1});
}

sort(meetings.begin(), meetings.end(), compare);  // O(nlogn)

vector<int> res;        // stores the order of the meetings 

int cnt = 1;
int free_time = meetings[0][1];

for(int i = 1; i < n; i++){  // O(n)
    int start_time = meetings[i][0];
    int end_time = meetings[i][1];
    int pos = meetings[i][2];

    if(start_time > free_time){
        cnt++;
        free_time = end_time;
        res.push_back(pos);
    }

}

cout<<cnt<<endl;
for(auto val: res) cout<<val<<" ";
cout<<endl;

TC: O(2*n + nlogn)
SC: O(n * 3) + O(n)
// O(n * 3) for storing the meetings -- n meetings for each meeting we are storing 3 things 
// O(n) for storing the order -- if asked 