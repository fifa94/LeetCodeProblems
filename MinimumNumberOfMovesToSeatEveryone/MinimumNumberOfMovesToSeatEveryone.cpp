#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {

        int min = 0;
        std::sort(seats.begin(),seats.end());
        std::sort(students.begin(), students.end());

        for (int i = 0; i < students.size(); i++)
        {
            min += abs(students[i] - seats[i]);
        }
        return min;
    }
};

int main()
{
    //seats = [3,1,5], students = [2,7,4]

    std::vector<int> seats = {3,1,5};
    std::vector<int> students = {2,7,4};

    Solution SolutionObj;
    SolutionObj.minMovesToSeat(seats, students);    

    return 0;
}