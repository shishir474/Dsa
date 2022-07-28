int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());

    if (B==0){  // corner case: handled it separately
        for(int i=0;i<A.size()-1;i++){
            if (A[i]==A[i+1]) return 1;
        }
        return 0;
    }

    // Earlier i=0, and j=A.size()-1, so if (A[j]-A[i] > B) I can increase i or decrease j. Both will reduce the overall factor and bring us closer to the target. SO can't decide which way to move
    // hence kept i=0 and at j=1, so if (A[j]-A[i] > B), I have to decrease the overall factor so I will increase i which will increase A{i}
    // and if (A[j]-A[i] < B) increase j so that a[j] increases and overall factor increases
    int i=0,j=1;
    while(i<A.size() && j<A.size()){
        if (A[j]-A[i] == B) return 1;
        else if(A[j]-A[i] < B){
            j++;
        }
        else{
            i++;
        }
    }

    return 0;



Hashing based solutiohn
// Hashing: Diffk II 

    set<int> s;
    for(int i=0;i<A.size();i++){
        if (s.count(A[i]-B) || s.count(A[i]+B)) return 1;
        s.insert(A[i]);
    }

    return 0;
}
