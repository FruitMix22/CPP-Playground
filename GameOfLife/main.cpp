#include <iostream>
#include <vector>
#include <stdexcept>

void InitGrid(std::vector<char>&grid, size_t lines, size_t columns);
void PasteGrid(std::vector<char>&grid, size_t lines, size_t columns);

int main()
{
    std::vector<char> vec1;
    size_t lines = 5;
    size_t columns = 5;
    
    std::cout << "Enter the amount of Columns (x): ";
    std::cin >> columns;
    std::cout << std::endl;
    std::cout << "Enter the amount of Lines (y): ";
    std::cin >> lines;
    std::cout << std::endl;

    try
    {
        InitGrid(vec1, lines, columns);
        PasteGrid(vec1, lines, columns);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


void InitGrid(std::vector<char>&grid, size_t lines, size_t columns) 
{
    size_t size = lines * columns;
    if (size == 0) throw std::invalid_argument("Grid cannot be empty!");
    for (int i = 0; i <= size; i++)
    {
        grid.push_back('0');
    }
}

void PasteGrid(std::vector<char>&grid, size_t lines, size_t columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << grid.at(i * columns + j);
        }
        std::cout << std::endl;
    }
}
