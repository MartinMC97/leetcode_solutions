// 20210915 华为机试 题目1

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        vector<int> res(houses.size(), INT_MAX);
        
        for(int i = 0, h = 0; i < houses.size() && h < heaters.size();){
            if(houses[i] <= heaters[h]) {
                res[i] = std::min(res[i], abs(houses[i] - heaters[h]));
                i++;
            }else{
                h++;
            }
        }
        
        for(int j = houses.size() - 1, h = heaters.size() - 1; j >= 0 && h >= 0;){
            if(houses[j] >= heaters[h]){
                res[j] = std::min(res[j], abs(heaters[h] - houses[j]));
                j--;
            }else{
                h--;
            }
        }
        
        return *max_element(res.begin(), res.end());
    }
};
