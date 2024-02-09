#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

struct List {
    struct Node {
        int64_t value;
        Node *next;
    };
    Node *head = nullptr;
    Node *new_after(Node *prev, int64_t value);

private:
    std::vector<std::unique_ptr<Node>> nodes_;
};


List::Node *reverse(List::Node *head);
List::Node *reverse(List::Node *head, int k);

void k_groups(List &list, int k);
