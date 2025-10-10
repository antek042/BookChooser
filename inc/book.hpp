#pragma once
#include <string>

class Book{
    public:
        Book() = default;
        explicit Book(const std::string &author, const std::string &title, int desire)
            : author(author), title(title), desire(desire) {}

        std::string author;
        std::string title;
        int desire; /* How much I want something from 0 to 10 */
};