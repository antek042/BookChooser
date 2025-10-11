#pragma once

#include "book.hpp"

#include <fstream>
#include <string>
#include <vector>

std::vector<Book> read_csv(const std::string &filepath);
void write_csv(const std::string &filepath, Book books);