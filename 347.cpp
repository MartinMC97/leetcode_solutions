class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int num: nums){
            map[num]++;
        }
        
        vector<int> res;
        
        auto cmp = [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.second < rhs.second; };
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> p_queue(cmp);
        
        for(pair<int, int> map_item: map){
            p_queue.push(map_item);
        }
        
        while(k > 0){
            //put the first k elements into the result vector.
            res.push_back(p_queue.top().first);
            p_queue.pop();
            k--;
        }
        
        return res;
    }
};