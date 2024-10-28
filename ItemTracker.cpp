#include <iostream>
#include <fstream>
#include "ItemTracker.h"

void ItemTracker::readInputFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string item;
    while (file >> item)
    {
        itemFrequency[item]++;
    }
    file.close();
}

int ItemTracker::getItemFrequency(const std::string &itemName)
{
    if (itemFrequency.find(itemName) != itemFrequency.end())
    {
        return itemFrequency[itemName];
    }
    return 0;
}

void ItemTracker::printAllItems()
{
    for (const auto &pair : itemFrequency)
    {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

void ItemTracker::printHistogram()
{
    for (const auto &pair : itemFrequency)
    {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void ItemTracker::writeFrequencyToFile()
{
    std::ofstream outFile("frequency.dat");
    for (const auto &pair : itemFrequency)
    {
        outFile << pair.first << " " << pair.second << "\n";
    }
    outFile.close();
}
