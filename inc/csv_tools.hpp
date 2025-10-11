#pragma once

#include "book.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <tuple>

std::vector<Book> read_csv(const std::string& filepath){
    std::vector<Book> books_queue;

    auto csv_file = std::ifstream(filepath);
    auto line = static_cast<std::string>("");

    while (getline(csv_file, line))
    {
        std::vector<std::string> data;
        auto last = 0;
        for (auto i = 0; i < line.size(); i++)
        {
            if (line[i] == ';'){
                data.push_back(line.substr(last, i-last));
                last = i + 1;
            }
        }
        data.push_back(line.substr(last));
        books_queue.push_back(Book(data[0], data[1], data[2], std::stoi(data[3]), std::stoi(data[4])));
    }
    
    csv_file.close();
    return books_queue;
}

// Note: write_csv requires at least one argument after 'filepath'.
template<typename... Args>
void write_csv(const std::string& filepath, Args... args){
    auto csv_file = std::ofstream(filepath, std::ios_base::app);
    auto tuple = std::make_tuple(args...);
    std::apply([&csv_file](const auto& first, const auto&... rest) {
        csv_file << first;                 
        ((csv_file << ';' << rest), ...);
        csv_file << '\n';
    }, tuple);
    csv_file.close();
}