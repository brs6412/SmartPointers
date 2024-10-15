#ifndef SP_FILE_H
#define SP_FILE_H

#include <string>

class File {
    public:
        File(const std::string& name, const std::string& content);

        std::string read() const;

        void write(const std::string& newContent);

        std::string getInfo() const;

        std::string getName() const;
    
    private:
        std::string fileName;
        std::string fileContents;
};

#endif