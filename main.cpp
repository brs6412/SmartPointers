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

int main() {
    std::string fname = "hello.txt";
    std::string content = "Hello there, universe!";
    testFileCreation(fname, content);
    return 0;
}