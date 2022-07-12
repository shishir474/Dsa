Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
If there exists multiple such starting points, then the function must return the first one out of those. (return -1 otherwise)

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1

Solution 1:

TC; O(n), SC:O(1);
class Solution{
  public:
    Best solution:
    if we know there is dificit of d litres of petrol we will store that bcoz if we visit it again that value is not gonna change
    int tour(petrolPump p[],int n)
    {
        int start=0;
        int balance=0, deficit=0;
        for(int i=0;i<n;i++){
            balance+=p[i].petrol - p[i].distance;
            if(balance < 0){
                deficit+=balance;
                start = i+1;
                balance = 0;
            }
        }
        
        if(balance+deficit>=0) return start;
        return -1;
    }
};




solution 2:

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    bool isSafe(int j, petrolPump p[]){
        if(p[j].petrol>=p[j].distance) return true;
        return false;
    }
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int j=-1;
        for(int i=0;i<n;i++){
            if(p[i].petrol>=p[i].distance){
                j=i; break;
            }
        }
        
        if(j==-1) return -1;
        
        int front=j;
        while(front<n){
            if(isSafe(front,p)){
                int rear=(front+1)%n;
                int balance=p[front].petrol-p[front].distance;
                bool notPossible = false;
                
                while(rear!=front){
                    if(balance+p[rear].petrol >= p[rear].distance){
                        balance = balance+p[rear].petrol - p[rear].distance;
                        rear = (rear+1)%n;
                    }
                    else{
                        notPossible=true;
                        break;
                    }
                }
                
                if(!notPossible) return front;
                
                if(rear > front){
                    front = rear + 1;
                }
                else{
                    front++;
                }
            }
            else{
                front++;              
            }
  
        }
        
        return -1;
       
    }
};

NOTE: Imp point that is used in this solution is 
if travel is not possible from front, then travel will also not be possible from front+1,front+2,..,uoto rear. Hence do front=rear+1
front is contributing some +ve balance >=0 to front+1. So if we start from front+1, it will be now more difficult to travel, since the contribution has now become 0
  front           rear rear+1
    |   | | | | |  |
so if Travel not possible from front,then start next time from rear+1
This solution visits each index twice, so better way is if we visit each pump once
we will start from 0
Idea is if at any point balance which is p[i].petrol - p[i].distance becomes < 0. We will add store this in deficit indicating we have this much amt shortage & will shift start to i+1(since we cant start from any oint between the currentstart and i inclusive)
if at last balance+deficit >= 0 return start
else return -1


Solution 3:
Brute force: start from each index and check O(n^2)