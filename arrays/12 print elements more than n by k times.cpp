class cell{
    public:
    int element,freq;
    cell(){
        element=0; freq=0;
    }
};

int main(){
    vector<int> arr(n);
    vector<cell> temp(k-1);  // contains the potemntial k-1 candidates
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<k-1;j++){
            if (arr[i]==temp[j].element){
                temp[j].freq++; break;
            }
        }
        if(j==k-1){
            int l;
            for(l=0;l<k-1;l++){
                if (temp[l].element==0){         // first available pos
                    temp[l].element = arr[i];
                    temp[l].freq = 1;
                    break;
                }  
            }
            if (l==k-1){
                for(int p=0;p<k-1;p++){
                    temp[p].freq--;
                }
            }
        }

    }

    // now check each element in temp if its freq is greater than n/k. Only this elements can have freq>n/k
    //print those elements
    for(int i=0;i<k-1;i++){
        int f=0;
        for(int j=0;j<n;j++){
            if (arr[j]==temp[i].element) f++;
        }
        if (f > n/k) cout<<temp[i].element<<" ";
    }

}

// space optimised
TC: O(n*k)
SC: O(k);

// algorithm
// maintain temp[k-1] sized array which will store potentail candidates
// for each element of arr, if arr[i] is present in temp, increase its freq otherwise find the first empty position and place the elemnet at pos with freq = 1
// if no empty space found, then decrease all elements freq in temp by 1
// check for each elements in temp, by calculating the freq again if its greater than n/k

other solutions using map,sorting and counting freq in nlogn