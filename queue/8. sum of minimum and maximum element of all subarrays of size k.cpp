Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 3
Output : 18


// stores max element of all subarrays of size k
vector<int> mx;
deque<int> q;
int i;
for(i=0;i<k;i++){
    while(!q.empty() and arr[i]>=arr[q.back()]){
        q.pop_back();
    }
    q.push_back(i);
}
for(;i<n;i++){
    mx.push_back(q.front());
    while(!q.empty() and q.front()<=i-k){
        q.pop_front();
    }
    while(!q.empty() and arr[i]>=arr[q.back()]){
        q.pop_back();
    }
    arr.push_back(i);
}

for(int i=0;i<mx.size();i++) cout<<mx[i]<<endl;


 
// stores min element of all subarrays of size k
vector<int> mn;
deque<int> q1;
for(i=0;i<k;i++){
    while(!q1.empty() and arr[i]<=arr[q1.back()]){
        q1.pop_back();
    }
    q1.push_back(i);
}
for(;i<n;i++){
    mn.push_back(arr[q1.front()]);
    while(!q1.empty() and q1.front()<=i-k){
        q1.pop_front();
    }
    while(!q1.empty() and arr[i]<=arr[q1.back()]){
        q1.pop_back();
    }
    q1.push_back(i);
}
mn.push_back(arr[q1.front()]);

for(int i=0;i<mx.size();i++) cout<<mn[i]<<endl;