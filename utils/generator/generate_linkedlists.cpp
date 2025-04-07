#include "generator.hh"

LinkedList Generator::generate_random_linked_list(size_t size, size_t max) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<size_t> distrib(0, max);

    LinkedList list(sizeof(Node) * size);
    for (size_t i = 0; i < size; ++i) {
        list.push_back(distrib(gen));
    }
    return list;
}

LinkedList Generator::generate_sorted_linked_list(size_t size) {
    LinkedList list(sizeof(Node) * size);
    for (size_t i = 0; i < size; ++i) {
        list.push_back(i);
    }
    return list;
}

LinkedList Generator::generate_reverse_sorted_linked_list(size_t size) {
    LinkedList list(sizeof(Node) * size);
    for (size_t i = size; i > 0; --i) {
        list.push_back(i - 1);
    }
    return list;
}