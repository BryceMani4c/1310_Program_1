#include <iostream>
#include <cstring>

class Text{
    public:
        Text();
        Text(const char*, int);
        ~Text();

        void displayText();
        const char * getText();
        int getLength();

    private:
        const char * textArray;
        int textLength;
};
