#pragma once

#include "linked_list.hh"
#include "sort_selector.hh"

std::unique_ptr<LinkedList> sort(std::unique_ptr<LinkedList> list);
void sort(std::vector<size_t> list);