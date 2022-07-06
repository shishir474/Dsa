 
 // solution 1:
// return unique elements that are common in 3 sorted arrays, 
// similar logic as of INTERSECTION of 2 arrays
// https://practice.geeksforgeeks.org/problems/common-elements1132/1#
 
 vector <int> commonElements (int a1[], int a2[], int a3[], int n1, int n2, int n3)
{
    //code here.
    vector<int> ans;
    int i=0,j=0,k=0;
    while(i<n1 and j<n2 and k<n3){
        if (a1[i]==a2[j] and a2[j]==a3[k]){
            ans.push_back(a1[i]);
            int val=a1[i];
            while(i<n1 and a1[i]==val) i++; // to take care of duplicates
            while(j<n2 and a2[j]==val) j++; // to take care of duplicates
            while(k<n3 and a3[k]==val) k++; // to take care of duplicates
        }
        else if(a1[i] < a2[j]) i++;
        else if(a2[j] < a3[k]) j++;
        else k++;
    }
    
    return ans;
}









// solution 2:
// In this approach, we will first delete the duplicate from each array, and after this, we will find the frequency of each element and the element whose frequency equals 3 will be printed. 
void removeDuplicates(vector<int> &a, int n){
    for(int i=0;i<n-1;i++){
        if (a[i]==a[i+1]) a[i]=INT_MAX;
    }
    a.erase(remove(a.begin(),a.end(),INT_MAX), a.end());
}
    
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    vector<int> ans;
    vector<int> a1(A,A+n1), a2(B,B+n2), a3(C,C+n3);

    removeDuplicates(a1,n1);
    removeDuplicates(a2,n2);
    removeDuplicates(a3,n3);
    
    map<int,int> mp;
    for(int i=0;i<a1.size();i++) mp[a1[i]]++;
    for(int i=0;i<a2.size();i++) mp[a2[i]]++;
    for(int i=0;i<a3.size();i++) mp[a3[i]]++;
    
    for(auto it=mp.begin();it!=mp.end();it++){
        if (it->second==3) ans.push_back(it->first);
    }
    
    return ans;
    
        }
