class Solution { 
public: 
    int longestSubarray(vector<int>& nums, int k) { 
        int n = nums.size(); 
        vector<int> dist(100001, 0); 
        
        int j = 0; 
        int cnt = 0; 
        int ans = 0; 
        
        for(int i = 0; i < n; i++){ 
            int val = nums[i]; 
            
            for(int p = 2; p * p <= val; p++){ 
                if(val % p == 0){ 
                    if(dist[p] == 0) cnt++; 
                    dist[p]++; 
                    
                    while(val % p == 0){ 
                        val /= p; 
                    } 
                } 
            } 
            
            if(val > 1){ 
                if(dist[val] == 0) cnt++; 
                dist[val]++; 
            } 
            
            while(cnt > k){ 
                int val = nums[j]; 
                
                for(int p = 2; p * p <= val; p++){ 
                    if(val % p == 0){ 
                        dist[p]--; 
                        
                        if(dist[p] == 0){ 
                            cnt--; 
                        } 
                        
                        while(val % p == 0){ 
                            val /= p; 
                        } 
                    } 
                } 
                
                if(val > 1){ 
                    dist[val]--; 
                    
                    if(dist[val] == 0){ 
                        cnt--; 
                    } 
                } 
                
                j++; 
            } 
            
            ans = max(ans, i - j + 1); 
        } 
        
        return ans; 
    } 
};