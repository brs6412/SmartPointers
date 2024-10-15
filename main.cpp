#include <iostream>
#include "File.h"
#include "FileManager.h"

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

int main() {
    testFileManager();
    return 0;
}