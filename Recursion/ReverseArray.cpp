#include <vector>
#include <iostream>

std::vector<int> reverse_array(std::vector<int> &array, std::vector<int> &results)
{

    if (array.size() != 0)
    {
        results.push_back(array[array.size() - 1]);
        array.pop_back();
        reverse_array(array, results);
    }

    return results;
};

int find_in_vector(std::vector<int> &array, int element, int left, int right)
{

    if (left > right)
    {
        return -1;
    }
    else
    {
        int mid = (left + right) / 2;
        if (element == array[mid])
        {
            return mid;
        }
        else if (element < array[mid])
        {
            return find_in_vector(array, element, left, mid - 1);
        }
        else if (element > array[mid])
        {
            return find_in_vector(array, element, mid + 1, right);
        }
    }
    return -1;
};

int main()
{
    std::vector<int> input_array = {7, 6, 5, 4, 3, 2, 1};
    std::vector<int> results;
    reverse_array(input_array, results);

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ,";
    }

    int index_of_element = 0;

    index_of_element = find_in_vector(results, 6, 0, results.size());

    std::cout << std::endl;
    std::cout << index_of_element;

    return 0;
}