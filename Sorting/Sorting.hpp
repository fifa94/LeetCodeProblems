#include <iostream>
#include <vector>
#include <optional>
#include <utility>

class SortAlgorithm
{
private:
public:
    SortAlgorithm() = default;          // Výchozí konstruktor
    virtual ~SortAlgorithm() = default; // Virtuální destruktor
    virtual std::optional<std::vector<int>> Sort() = 0;
};

class BubleSort : public SortAlgorithm
{
private:
    std::vector<int> local_buffer;
    bool swaped;

public:
    BubleSort(const std::vector<int> &Buffer);
    ~BubleSort();
    std::optional<std::vector<int>> Sort() override;
};

BubleSort::BubleSort(const std::vector<int> &Buffer)
{
    this->local_buffer = Buffer;
}

BubleSort::~BubleSort()
{
}

std::optional<std::vector<int>> BubleSort::Sort()
{
    if (this->local_buffer.empty())
        return std::nullopt;

    bool swaped = false;

    while (!swaped)
    {
        swaped = true;
        for (int i = 0; i < this->local_buffer.size() - 1; i++)
        {
            if (this->local_buffer[i] > this->local_buffer[i + 1])
            {
                std::cout << "Swaping these two numbers " << this->local_buffer[i] << " and " << this->local_buffer[i + 1] << std::endl;
                std::swap(this->local_buffer[i], this->local_buffer[i + 1]);
                swaped = false;
            }
        }
    }

    return this->local_buffer;
}