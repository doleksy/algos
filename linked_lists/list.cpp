#include "list.h"

List::Node *List::new_after(List::Node *prev, int64_t value) {
    nodes_.push_back(std::make_unique<List::Node>(value, nullptr));
    if (prev == nullptr)
        return head = nodes_.back().get();
    else
        return prev->next = nodes_.back().get();
}

List::Node *reverse(List::Node *head)
{
    List::Node *result = nullptr;
    List::Node *iter = head;

    while (iter != nullptr)
    {
        iter = std::exchange(iter->next, std::exchange(result, iter));
    }

    return result;
}

List::Node *reverse(List::Node *head, int k)
{
    List::Node *result = nullptr;
    List::Node *iter = head;

    for (auto i = 0; i < k and iter != nullptr; ++i)
    {
        iter = std::exchange(iter->next, std::exchange(result, iter));
    }

    return result;
}


void k_groups(List &list, int k)
{
    List::Node *unprocessed_head{ list.head };
    List::Node *unprocessed_tail{ list.head };
    List::Node *processed_tail{ nullptr };
    List::Node *result{ nullptr };

    while (unprocessed_tail != nullptr)
    {
        int count{ 0 };
        while (count < k and unprocessed_tail != nullptr)
        {
            ++count;
            unprocessed_tail = unprocessed_tail->next;
        }

        if (count == k)
        {
            List::Node *processed_head = reverse(unprocessed_head, k);

            if (result == nullptr)
            {
                result = processed_head;
            }

            if (processed_tail != nullptr)
            {
                processed_tail->next = processed_head;
            }

            processed_tail = unprocessed_head;
            unprocessed_head = unprocessed_tail;
        }
    }
    if (processed_tail != nullptr)
    {
        processed_tail->next = unprocessed_head;
    }

    list.head = (result == nullptr) ? unprocessed_head : result;
}
