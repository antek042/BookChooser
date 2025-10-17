#pragma once

#include "book.hpp"
#include <algorithm>
#include <map>
// TODO: What if we don't have favourite genre in to_read vector?
Book recommend_book(std::vector<Book>& read, std::vector<Book>& to_read){
    std::map<Genre, int> count_genres;
    for(auto& book : read)
        count_genres[book.genre]++;

    auto favourite_genre = *std::max_element(count_genres.begin(), count_genres.end(),
                                            [](const auto &a, const auto &b)
                                            { return a.second < b.second; });

    std::sort(to_read.begin(), to_read.end(),
              [](auto a, auto b)
              { return a.rating < b.rating; });

    return *std::find_if(to_read.begin(), to_read.end(), [favourite_genre](const auto &b)
                         { return b.genre == favourite_genre.first; });
}