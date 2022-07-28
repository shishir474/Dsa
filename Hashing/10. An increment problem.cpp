// The problem states that “increase its first occurrence by 1 and include this in the stream” meaning when you increment the first occurrence by 1, then the array gets updated itself and next time when you are incrementing then you need to increment considering the updated array.
// For example: [1,1,1]
// When i=0 then array becomes [1]
// When i=1 then array becomes [2,1], since the first occurrence of 1 is at index 0, its value is increased by 1
// When i=2 then the array becomes [2,2,1] since the first occurrence of 1 in the updated array is at index 1 not at index 0.

// Sly, for this example: [5,5,5,6]
// at i=0, A=[5]
// at i=1, A=[6,5] first occurrence of 5 is at index 0
// at i=2, A=[6,6,5] first occurrence of 5 in updated array is at index 1
// at i=3, A=[7,6,6,5] first occurrence of 6 in updated array is at index 0

// Sly, for this example: [1,2,3,2,3,1,4,2,1,3]
// at i=0, A=[1]
// at i=1, A=[1,2]
// at i=2, A=[1,2,3]
// at i=3, A=[1,3,3,2] occurrence of 2 was at index 1
// at i=4, A=[1,4,3,2,3] occurrence of 3 was at index 1
// at i=5, A=[2,4,3,2,3,1] occurene of 1 was at index 0
// at i=6, A=[2,5,3,2,3,1,4] occurrence of 4 was at index 1
// at i=7, A=[3,5,3,2,3,1,4,2] occurrence of 2 was at index 0
// at i=8, A=[3,5,3,2,3,2,4,2,1] occurrence of 1 was at index 5
// at i=9, A=[4,5,3,2,3,2,4,2,1,3] occurrence of 3 was at index 0
vector<int> Solution::solve(vector<int> &A) {
    vector<int> v;
    for(int i=0;i<A.size();i++){
        auto it=find(v.begin(),v.end(),A[i]);
        if (it== v.end()){ // first time
            v.push_back(A[i]);
        }
        else{  // increment its first occurence by 1 and push the curr element
            v[it-v.begin()]++;
            v.push_back(A[i]);
        }
    }

    return v;
}

