class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        map<int , int> map;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<size)
        {
            map[fruits[j]]++;
            while(map.size()>2)
            {
                 map[fruits[i]]--;
                 if(map[fruits[i]]==0)
                 {
                  map.erase(fruits[i]);
                 }
                 i++;
            }
            j++;
            maxi =max(maxi , j-i);
        }
        return maxi;
    }
};