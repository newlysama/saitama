#pragma once

#include <exception>

#include <linked_lists/linked_lists.hh>

std::unique_ptr<LinkedList> merge_sort(std::unique_ptr<LinkedList> list);

std::tuple<std::vector<std::size_t>, std::vector<std::size_t>> split(std::vector<std::size_t> list);
std::vector<std::size_t> merge(std::vector<std::size_t> list1, std::vector<std::size_t> list2);
std::vector<std::size_t> merge_sort(std::vector<size_t> list);