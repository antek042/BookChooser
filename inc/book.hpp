#pragma once
#include <string>
#include <vector>

enum class Genre
{
    Programming,
    Economics,
    Mathematics
};

class Book{
    public:
        Book() = default;
        Book(const std::string &author, const std::string &title, Genre genre, int desire, int rating)
            : author(author), title(title), genre(genre), desire(desire), rating(rating) {}

        std::string author;
        std::string title;
        Genre genre;
        int desire; /* How much I want something from 0 to 10 */
        int rating; /* Shop book rating from 0 to 5 */
};