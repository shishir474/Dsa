MAXIMISE ARRAY SUM AFTER K NEGATIONS:

Given an array of integers of size N and a number K., Your must modify array arr[] exactly 
K number of times. Here modify array means in each operation you can replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this operation in such a way that after K operations, the sum of the array must be maximum.


Example 1:

Input:
N = 5, K = 1
arr[] = {1, 2, -3, 4, 5}
Output:
15
Explanation:
We have k=1 so we can change -3 to 3 and
sum all the elements to produce 15 as output.


SOL.
iMPORTANT POINT TO NOTE IS WE CAN APPLY THE OPERATION ON AN ELEMENT ANY NO. OF TIMES WE WANT.
IF K<=NEGATIVE COUNT => CONVERT FIRST SMALLEST K NEGATIVES INTO POSITIVE THATS IT.
IF K>NEGATIVE COUNT => CONVERT ALL NEGATIVES, NOW ALL THE ELEMENTS ARE POSITIVE, IF REMAINING K IS ODD THEN CONVERT THE SMALLEST +VE TO -VE. 
bUT IF REMAINING K IS EVEN THEN DO NOTHING AS WE WOULD HAVE PERFORMED THE REMAINING OPERATIONS ON THE SAME ELEMENT AND PERFORMING OPEARTIONS EVEN NO. OF TIMES DOESNT CHANGE THE SIGN

typedef long long ll;
long long int maximizeSum(long long int a[], int n, int k)
{
    vector<ll> pos,neg;
    for(ll i=0;i<n;i++){
        if(a[i]>=0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    if(k<=neg.size()){
        sort(neg.begin(),neg.end());
        for(ll i=0;i<k;i++) neg[i]*=-1;
        ll sum=0;
        for(int i=0;i<pos.size();i++){
            sum+=pos[i];
        }
        for(int i=0;i<neg.size();i++){
            sum+=neg[i];
        }
        
        return sum;
    }
    else{
        for(ll i=0;i<neg.size();i++) {neg[i]*=-1;
            pos.push_back(neg[i]);
        }
        k-=neg.size();
        sort(pos.begin(),pos.end());
        if(k%2==1 and pos.size()>0) pos[0]*=-1;
        ll sum=0;
        for(int i=0;i<pos.size();i++) sum+=pos[i];
        return sum;
    }

}