#pragma once
#include <string>
#include <vector>

class Book{
    public:
        Book() = default;
        Book(const std::string &author, const std::string &title, const std::string &genre, int desire)
            : author(author), title(title), genre(genre), desire(desire) {}

        std::string author;
        std::string title;
        std::string genre;
        int desire; /* How much I want something from 0 to 10 */
};