Maximum Bipartite Matching
 
 There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interseted in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Given a matrix G where G(i,j) denotes ith applicant is interested in jth job. Find an assignment of jobs to applicant in such that as many applicants as possible get jobs.

 ex;
p1 -> j1, j2
p2 -> j1
p3 -> j2, j3
p4 -> j3, j4, j5
p5 -> j5

ans = 5

jobs[] = p1  p2  p3  p4  p5
         J2  J1  J3  J4  J5

TC: O(m*n*n);
SC: O(m);
 
 bool canBeAssignedJob(int p, vector<vector<int>> &G, vector<int>& jobs, vector<int>& seen){
        
        for(int j=0;j<G[0].size();j++){
            
            if(G[p][j] && !seen[j]){
                
                seen[j]=1;
        
        // if jth job not assigned or if person to whom it was assigned to can do another job, In both these cases pth person can do jth job
        // since seen[j]=1, that person wont be able to do the jth job
                if(jobs[j]==-1 || canBeAssignedJob(jobs[j],G,jobs,seen)){
                    // jth job can be assigned to pth person
                    jobs[j]=p;
                    return true;
                }
                
            }
        }
        
        return false;
    }
    
    
	int maximumMatch(vector<vector<int>>&G){
	    // Code here
	    // n persons, m jobs
	    int n=G.size(), m=G[0].size();
	    
	    vector<int> jobs(m,-1);
	    
	    int cnt=0;
	    
	    for(int i=0;i<n;i++){
	        vector<int> seen(m,false);
	        if(canBeAssignedJob(i,G,jobs,seen)) cnt++;
	    }
	    
	    return cnt;
	   
	}