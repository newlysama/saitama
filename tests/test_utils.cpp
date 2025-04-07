#include "test_utils.hh"

void TestUtils::test_linked_list_integrity(LinkedList& list, const std::vector<size_t>& values) {
    EXPECT_EQ(list.size, values.size());

    if (values.empty()) {
        EXPECT_EQ(list.first, nullptr);
        EXPECT_EQ(list.last, nullptr);
        return;
    }

    EXPECT_EQ(list.first->prev, nullptr);
    EXPECT_EQ(list.last->next, nullptr);

    Node* current = list.first;
    Node* prev = nullptr;

    for (size_t i = 0; i < values.size(); ++i) {
        ASSERT_NE(current, nullptr) << "Node is null at index " << i;
        EXPECT_EQ(current->value, values[i]) << "Value mismatch at index " << i;

        // Check prev
        EXPECT_EQ(current->prev, prev) << "Prev pointer incorrect at index " << i;

        // Check that next has current as prev
        if (current->next) {
            EXPECT_EQ(current->next->prev, current) << "Next->prev incorrect at index " << i;
        }

        prev = current;
        current = current->next;
    }

    EXPECT_EQ(prev, list.last) << "Last pointer incorrect";
    EXPECT_EQ(current, nullptr) << "List is longer than expected";
}
