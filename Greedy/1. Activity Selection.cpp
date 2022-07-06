There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)


There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

  public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(const pair<int,int>& p1,const pair<int,int>& p2){
        return p1.second < p2.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),compare);
        
        int lastFinishTime=v[0].second, ans=1;
        for(int i=1;i<n;i++){
            if(v[i].first > lastFinishTime){
                ans++;
                lastFinishTime=v[i].second;
            }
        }
        
        return ans;
    }

    maximise the number of activities, so sort krdo finish time ke basis pe so that more no. of jobs can be performed


SIMILAR PROBLEM

Find maximum meetings in one room

There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers

Examples: 

Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} 
Output : 1 2 4 5 
First meeting [1, 2] 
Second meeting [3, 4] 
Fourth meeting [5, 7] 
Fifth meeting [8, 9]

sol. finish time ke basis pe sort krdo and count the no of meetings possible. First meeting will always take place start checking from 2nd meeting onwards