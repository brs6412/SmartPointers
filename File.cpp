#include "File.h"

File::File(const std::string& name, const std::string& content) : fileName(name), fileContents(content) {}

std::string File::getInfo() const {
    std::string output;
    output += fileName;
    output += " - " + std::to_string(fileContents.size()) + " bytes";
    return output;
}


std::string File::read() const { return fileContents; }

void File::write(const std::string& newContent) { fileContents = newContent; }

std::string File::getName() const { return fileName; }