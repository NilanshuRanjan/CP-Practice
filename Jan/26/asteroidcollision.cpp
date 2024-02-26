class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size()-1;

        while (n > 0){
            if (asteroids[n] < 0 && asteroids[n-1] > 0){
                if (abs(asteroids[n]) > abs(asteroids[n-1])){
                    asteroids.erase(asteroids.begin() + (n-1));
                }
                else if (abs(asteroids[n]) < abs(asteroids[n-1])){
                    asteroids.erase(asteroids.begin() + (n));
                }
                else{
                    asteroids.erase(asteroids.begin() + (n));
                    asteroids.erase(asteroids.begin() + (n-1));
                }
                n = asteroids.size()-1;
            }
            else{
                n--;
            }
        }
        return asteroids;
        
    }
};
