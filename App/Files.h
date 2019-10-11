#ifndef __FILES_H__
#define __FILES_H__

#include <Arduino.h>
#include <FS.h>

class Files {
    public:
        Files() {}

        void start();

        String getContentType(String filename);
        bool fileExists(String filename);
        File getFileForRead(String filename);
    private:


};

#endif
