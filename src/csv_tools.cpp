#include "csv_tools.hpp"

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
        books_queue.push_back(Book(data[0], data[1], data[2], std::stoi(data[3])));
    }
    
    csv_file.close();
    return books_queue;
}

void write_csv(const std::string& filepath, Book book){
    auto csv_file = std::ofstream(filepath, std::ios_base::app);
    csv_file << book.author << ";" << book.title  << ";"
             << book.genre  << ";" << book.desire << "\n";
    csv_file.close();
}