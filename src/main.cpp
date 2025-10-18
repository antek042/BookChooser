#include "csv_tools.hpp"
#include "recommend.hpp"
#include "book.hpp"
#include "rang.hpp"
#include "gui.hpp"
#include "ascii_banner.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

using rf = rang::fg;
using rs = rang::style;

int main(int argc, char *argv[])
{
    CoutText cout_text;

    std::string want_to_read_path;
    std::string read_path;

    cout_text << "Enter path to books you want to read (*.csv): ";
    std::getline(std::cin, want_to_read_path);
    auto to_read_list = read_csv(want_to_read_path);

    cout_text << "Enter path to books you've already read (*.csv): ";
    std::getline(std::cin, read_path);
    auto read_list = read_csv(read_path);
    
    std::system("clear");

    std::cout << rf::cyan << banner << "\n" << rs::reset;
}