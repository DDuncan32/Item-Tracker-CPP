#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

class ItemTracker
{
private:
    std::map<std::string, int> itemFrequency;

public:
    void readInputFile(const std::string &fileName);
    int getItemFrequency(const std::string &itemName);
    void printAllItems();
    void printHistogram();
    void writeFrequencyToFile();
};

#endif
