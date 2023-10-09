#include <string>

#ifndef CLASS_H
#define CLASS_H

class CreateAndDestroy {
    public:
        CreateAndDestroy(int, std::string);
        ~CreateAndDestroy();

    private:
        int objectID;
        std::string message;
};

#endif
