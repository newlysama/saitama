#include "vector_utils.hh"

std::vector<std::size_t> VectorUtils::merge(std::vector<std::size_t> list1, std::vector<std::size_t> list2) {
    if (list1.empty()) {
        return list2;
    } else if (list2.empty()) {
        return list1;
    }

    std::vector<std::size_t> res;
    size_t i = 0;
    size_t j = 0;

    while (i < list1.size() && j < list2.size()) {
        if (list1[i] <= list2[j]) {
            res.push_back(list1[i++]);
        } else {
            res.push_back(list2[j++]);
        }
    }

    while (i < list1.size()) {
        res.push_back(list1[i++]);
    }

    while (j < list2.size()) {
        res.push_back(list2[j++]);
    }

    return res;
}