#pragma once

#include <exception>

#include <linked_lists/linked_lists.hh>

std::unique_ptr<LinkedList> merge_sort(std::unique_ptr<LinkedList> list);
std::vector<std::size_t> merge_sort(std::vector<size_t> list);