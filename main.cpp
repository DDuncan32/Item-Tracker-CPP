#include <iostream>
#include <string>
#include "ItemTracker.h"

void displayMenu()
{
    std::cout << "1. Look up item frequency\n";
    std::cout << "2. Print all item frequencies\n";
    std::cout << "3. Print item frequency histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    ItemTracker tracker;
    tracker.readInputFile("CS210_Project_Three_Input_File.txt");

    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string item;
            std::cout << "Enter item to look up: ";
            std::cin >> item;
            std::cout << item << ": " << tracker.getItemFrequency(item) << " times\n";
            break;
        }
        case 2:
            tracker.printAllItems();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    tracker.writeFrequencyToFile(); // Write backup file on exit
    return 0;
}
