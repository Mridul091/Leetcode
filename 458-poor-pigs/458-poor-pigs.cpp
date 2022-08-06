class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rnd = minutesToTest/minutesToDie;
        int pigs = 0;
        while(pow(rnd+1,pigs)<buckets) pigs++;
        return pigs;
    }
};