Total no. of bst with n keys = Cn(nth catalan number)
Total no. of bt with n keys = countBST with n keys * n!
countBT(n) = countBST(n)*n!

ex : for n=3-> 1 2 3 5 BSTs are possible whereas 5*(3!) = 30 bt are possible


Total number of possible Binary Search Trees with n different keys (countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!)

For n = 0, 1, 2, 3, … values of Catalan numbers are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …. So are numbers of Binary Search Trees.

Total number of possible Binary Trees with n different keys (countBT(n)) = countBST(n) * n! 

program for nth catalan number

int t[n];
memset(t,0,sizeof(t));
t[0]=t[1]=1
for(int i=2;i<=n;i++){
    for(int j=0;j<i;j++){
        t[i]+=t[j]*t[i-1-j];
    }
}

return t[n];