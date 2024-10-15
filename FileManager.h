#ifndef SP_FILEM_H
#define SP_FILEM_H

#include "File.h"
#include <memory>
#include <vector>
#include <string>

class FileManager {
    public:
        void addFile(const std::string& name, const std::string& content);

        void removeFile(const std::string& name);

        void listFiles() const;

        void readFile(const std::string& name) const;

        void writeFile(const std::string& name, const std::string& newContent);

    private:
        std::vector<std::unique_ptr<File>> files;

        File* findFile(const std::string& name) const;
};

#endif