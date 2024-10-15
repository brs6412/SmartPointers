#include "FileManager.h"
#include "File.h"
#include <iostream>
#include <algorithm>

File* FileManager::findFile(const std::string& name) const {
    for (const auto& ptr: files) {
        if (ptr->getName() == name) {
            return ptr.get();
        }
    }
    return nullptr;
}

void FileManager::addFile(const std::string& name, const std::string& content) {
    files.push_back(std::make_unique<File>(name, content));
}

void FileManager::removeFile(const std::string& name) {
    files.erase(
        std::remove_if(files.begin(), files.end(),
            [name](const std::unique_ptr<File>& file) {
                return file->getName() == name;
            }),
        files.end());
}

void FileManager::listFiles() const{
    int i = 1;
    for(const auto& file: files) {
        std::cout << i << ". " << file->getInfo() << "\n";
        i++;
    }
}

void FileManager::readFile(const std::string& name) const {
    File* file = findFile(name);
    if (file) {
        std::cout << file->read();
    } else {
        std::cerr << "File not found." << std::endl;
    }
}

void FileManager::writeFile(const std::string& name, const std::string& newContent) {
    File* file = findFile(name);
    if (file) {
        file->write(newContent);
    } else {
        std::cerr << "File not found." << std::endl;
    }
}