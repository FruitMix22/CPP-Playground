#include <iostream>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <thread>

void InitGrid(std::vector<char>&grid, size_t lines, size_t columns);
void PasteGrid(std::vector<char>&grid, size_t lines, size_t columns);
void UpdateGrid(std::vector<char>&grid, size_t lines, size_t columns, uint8_t& idx);

int main()
{
    std::chrono::milliseconds frameTime = std::chrono::milliseconds(200);
    uint8_t frames = 50;
    std::vector<char> vec1;
    size_t lines = 5;
    size_t columns = 5;
    uint8_t idx = 0;
    
    try
    {
        InitGrid(vec1, lines, columns);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }

    for (int i = 0; i < frames; i++)
    {
        UpdateGrid(vec1, lines, columns, idx);
        PasteGrid(vec1, lines, columns);
        std::this_thread::sleep_for(frameTime);
    }


    return 0;
}


void InitGrid(std::vector<char>&grid, size_t lines, size_t columns) 
{
    size_t size = lines * columns;
    if (size == 0) throw std::invalid_argument("Grid cannot be empty!");
    grid.resize(size, '0');
}

void PasteGrid(std::vector<char>&grid, size_t lines, size_t columns)
{
    // Overwrite the previous line
    std::cout << "\033[H";
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            std::cout << grid.at(i * columns + j);
        }
        std::cout << std::endl;
    }
}

void UpdateGrid(std::vector<char>& grid, size_t lines, size_t columns, uint8_t& idx)
{
    if (idx < grid.size() - 1)
    {
        grid.at(idx) = '0';
        idx++;
        grid.at(idx) = '*';
    }
    /*
    * TODO: For now, just get movement +1.
    * So start at 0, move the * to the end, so on so on!
    * Move +1 each time funciton is called
    */
}

/*
* TODO: calculate where the other * are
* TODO: establish movement?
*/
