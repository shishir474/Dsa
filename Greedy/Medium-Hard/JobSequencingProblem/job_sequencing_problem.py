class Solution:
    def job_sequencing(self, jobs):
        n = len(jobs)
        # Sort jobs by decreasing profit
        jobs.sort(key=lambda x: x[2], reverse=True) # x[2] is profit
        
        max_deadline = -1
        for job in jobs:
            max_deadline = max(max_deadline, job[1]) # x[1] is deadline
            
        # Create a time slot array to keep track of free time slots
        time_slots = [-1] * (max_deadline + 1)
        
        total_profit = 0
        job_count = 0
        for job in jobs:
            job_id, deadline, profit = job[0], job[1], job[2]
            for slot in range(deadline, 0, -1):
                if time_slots[slot] == -1: # If the slot is free
                    time_slots[slot] = job_id
                    total_profit += profit
                    job_count += 1
                    break
                
        return job_count, total_profit
    
    # TC: O(nlogn) + O(n * d) where d is the maximum deadline
    # SC: O(d) for time_slots array
    
    
# Most Optimal Solution using Disjoint Set Union (DSU)
# Finding the next available slot can be optimized using DSU. Instead of running a loop to find the available slot, 
# dsu can help us to find the slots in O(1) time on average

class Solution:
    def job_sequencing(self, jobs):
        n = len(jobs)
        # Sort jobs by decreasing profit
        jobs.sort(key=lambda x: x[2], reverse=True) # x[2] is profit
        
        max_deadline = -1
        for job in jobs:
            max_deadline = max(max_deadline, job[1]) # x[1] is deadline
            
        dsu = list(range(max_deadline + 1)) # gives us a list [0, 1, 2, ..., max_deadline]
        
        total_profit = 0
        job_count = 0
        for job in jobs:
            job_id, deadline, profit = job[0], job[1], job[2]
            
            # finds the absolute parent or available slot
            available_slot = self.find(dsu, deadline)
            
            # if the slot exists:
            if available_slot > 0:
                # update the next available slot- assume available_slot is 2
                # so dsu[2] which is next avaialble slot of 2 will now be find(1)
                dsu[available_slot] = self.find(dsu, available_slot - 1)
                total_profit += profit
                job_count += 1
                
        return job_count, total_profit
    
    # TC: O(nlogn) + O(n)
    # SC: O(d) for dsu array