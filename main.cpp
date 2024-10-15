#include "File.h"
#include "FileManager.h"
#include <iostream>
#include <limits>

void appendExclamation(std::string& str) {
    str += "!";
}

void testFileCreation(std::string& fileName, std::string& contents) {
    File testFile(fileName, contents);

    std::cout << "File name: " << testFile.getName() << "\n";

    std::cout << testFile.getInfo() << "\n";
    std::cout << testFile.read() << "\n";

    std::string newContent = "Wow! Hello there universe! This is crazy!!";
    testFile.write(newContent);

    std::cout << testFile.getInfo() << "\n";
    std::cout << testFile.read() << "\n";
}

void testFileManager() {
    FileManager fileManager;

    fileManager.addFile("hello1.txt", "Hello there 1st example!");
    fileManager.addFile("hello2.txt", "Hello there 2nd example!Hello there 2nd example!");
    fileManager.addFile("hello3.txt", "Hello there 3rd example!Hello there 3rd example!Hello there 3rd example!");

    std::cout << "Current files in the manager:\n";
    fileManager.listFiles();
    std::cout << "\n";

    std::cout << "Reading hello1.txt:\n";
    fileManager.readFile("hello1.txt");
    std::cout << "\n\n";

    std::cout << "Reading hello2.txt:\n";
    fileManager.readFile("hello2.txt");
    std::cout << "\n\n";

    std::cout << "Updating contents of hello2.txt to a good quote.\n\n";
    std::string montyPython = "Three shall be the number thou shalt count, and the number of the counting shall be three.\n"
                        "Four shalt thou not count, neither count thou two, excepting that thou then proceed to three. Five is right out!";
    fileManager.writeFile("hello2.txt", montyPython);

    std::cout << "Reading new and improved hello2.txt:\n";
    fileManager.readFile("hello2.txt");
    std::cout << "\n\n";

    std::cout << "Reading hello3.txt:\n";
    fileManager.readFile("hello3.txt");
    std::cout << "\n\n";

    std::cout << "Removing hello3.txt.\n\n";
    fileManager.removeFile("hello3.txt");

    std::cout << "Resulting files in the manager:\n";
    fileManager.listFiles();
    std::cout << "\n";
}

void printBanner() {
    std::cout << "****************\n";
    std::cout << "* File Manager *\n";
    std::cout << "****************\n";
}

void printMenu() {
    std::cout << "\n** SELECT OPTION **\n";
    std::cout << "-------------------\n";
    std::cout << "1. Add file\n";
    std::cout << "2. Read file\n";
    std::cout << "3. List files\n";
    std::cout << "4. Write new content to a file\n";
    std::cout << "5. Remove a file\n";
    std::cout << "(x) to quit\n";
}

std::string promptForInput(const std::string& prompt) {
    std::string input;

    std::cout << prompt;
    std::getline(std::cin, input);

    while (input.empty()) {
        std::cout << "Input cannot be empty. " << prompt;
        std::getline(std::cin, input);
    }

    return input;
}

int main() {
    printBanner();
    FileManager fileManager;

    std::string userin = "";
    std::string fileName = "";
    std::string content = "";
    while (userin != "x") {
        printMenu();
        std::cout << "\nEnter an option: ";
        std::cin >> userin;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        fileName = "";
        content = "";

        if (userin == "1"){
            fileName = promptForInput("Enter filename to add: ");
            content = promptForInput("Enter contents to write to file: ");
            fileManager.addFile(fileName, content);
        } else if (userin == "2") {
            fileName = promptForInput("Enter filename to read: ");
            fileManager.readFile(fileName);
            std::cout << "\n";
        } else if (userin == "3") {
            std::cout << "Current files in the manager:\n";
            fileManager.listFiles();
            std::cout << "\n";
        } else if (userin == "4"){
            fileName = promptForInput("Enter filename to edit: ");
            content = promptForInput("Enter contents to write to file: ");
            fileManager.writeFile(fileName, content);
        } else if (userin == "5") {
            fileName = promptForInput("Enter filename to remove: ");
            fileManager.removeFile(fileName);
        } else if (userin == "x") {
            break;
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }
    std::cout << "Have a great day!\n";
    return 0;
}