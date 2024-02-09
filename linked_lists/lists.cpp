#include <gtest/gtest.h>

#include "list.h"

TEST(LinkedLists, ConstructList)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);
    list.new_after(list.head->next, 3);
    list.new_after(list.head->next->next, 4);
    list.new_after(list.head->next->next->next, 5);

    EXPECT_EQ(list.head->value, 1);
    EXPECT_EQ(list.head->next->value, 2);
    EXPECT_EQ(list.head->next->next->value, 3);
    EXPECT_EQ(list.head->next->next->next->value, 4);
    EXPECT_EQ(list.head->next->next->next->next->value, 5);
    EXPECT_EQ(list.head->next->next->next->next->next, nullptr);
}

TEST(LinkedLists, ReverseNodes)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);
    list.new_after(list.head->next, 3);
    list.new_after(list.head->next->next, 4);
    list.new_after(list.head->next->next->next, 5);

    list.head = reverse(list.head);

    EXPECT_EQ(list.head->value, 5);
    EXPECT_EQ(list.head->next->value, 4);
    EXPECT_EQ(list.head->next->next->value, 3);
    EXPECT_EQ(list.head->next->next->next->value, 2);
    EXPECT_EQ(list.head->next->next->next->next->value, 1);
    EXPECT_EQ(list.head->next->next->next->next->next, nullptr);
}


TEST(LinkedLists, ReverseFirstThree)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);
    list.new_after(list.head->next, 3);
    list.new_after(list.head->next->next, 4);
    list.new_after(list.head->next->next->next, 5);

    list.head = reverse(list.head, 3);

    EXPECT_EQ(list.head->value, 3);
    EXPECT_EQ(list.head->next->value, 2);
    EXPECT_EQ(list.head->next->next->value, 1);
    EXPECT_EQ(list.head->next->next->next, nullptr);
}

TEST(LinkedLists, ReverseThreeWithListOfTwo)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);

    list.head = reverse(list.head, 3);

    EXPECT_EQ(list.head->value, 2);
    EXPECT_EQ(list.head->next->value, 1);
    EXPECT_EQ(list.head->next->next, nullptr);
}

TEST(LinkedLists, SkipOneReverseNextThree)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);
    list.new_after(list.head->next, 3);
    list.new_after(list.head->next->next, 4);
    list.new_after(list.head->next->next->next, 5);

    list.head->next = reverse(list.head->next, 3);

    EXPECT_EQ(list.head->value, 1);
    EXPECT_EQ(list.head->next->value, 4);
    EXPECT_EQ(list.head->next->next->value, 3);
    EXPECT_EQ(list.head->next->next->next->value, 2);
    EXPECT_EQ(list.head->next->next->next->next, nullptr);
}


TEST(LinkedLists, KGroupsTwo)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);
    list.new_after(list.head->next, 3);
    list.new_after(list.head->next->next, 4);
    list.new_after(list.head->next->next->next, 5);
    list.new_after(list.head->next->next->next->next, 6);
    list.new_after(list.head->next->next->next->next->next, 7);
    list.new_after(list.head->next->next->next->next->next->next, 8);

    k_groups(list, 2);

    EXPECT_EQ(list.head->value, 2);
    EXPECT_EQ(list.head->next->value, 1);
    EXPECT_EQ(list.head->next->next->value, 4);
    EXPECT_EQ(list.head->next->next->next->value, 3);
    EXPECT_EQ(list.head->next->next->next->next->value, 6);
    EXPECT_EQ(list.head->next->next->next->next->next->value, 5);
    EXPECT_EQ(list.head->next->next->next->next->next->next->value, 8);
    EXPECT_EQ(list.head->next->next->next->next->next->next->next->value, 7);
    EXPECT_EQ(list.head->next->next->next->next->next->next->next->next, nullptr);
}

TEST(LinkedLists, KGroupsThree)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);
    list.new_after(list.head->next, 3);
    list.new_after(list.head->next->next, 4);
    list.new_after(list.head->next->next->next, 5);
    list.new_after(list.head->next->next->next->next, 6);
    list.new_after(list.head->next->next->next->next->next, 7);
    list.new_after(list.head->next->next->next->next->next->next, 8);
    list.new_after(list.head->next->next->next->next->next->next->next, 9);

    k_groups(list, 3);

    EXPECT_EQ(list.head->value, 3);
    EXPECT_EQ(list.head->next->value, 2);
    EXPECT_EQ(list.head->next->next->value, 1);
    EXPECT_EQ(list.head->next->next->next->value, 6);
    EXPECT_EQ(list.head->next->next->next->next->value, 5);
    EXPECT_EQ(list.head->next->next->next->next->next->value, 4);
    EXPECT_EQ(list.head->next->next->next->next->next->next->value, 9);
    EXPECT_EQ(list.head->next->next->next->next->next->next->next->value, 8);
    EXPECT_EQ(list.head->next->next->next->next->next->next->next->next->value, 7);
    EXPECT_EQ(list.head->next->next->next->next->next->next->next->next->next, nullptr);
}

TEST(LinkedLists, KGroupsThreeEndOnlyTwo)
{
    List list;
    list.new_after(nullptr, 1);
    list.new_after(list.head, 2);
    list.new_after(list.head->next, 3);
    list.new_after(list.head->next->next, 4);
    list.new_after(list.head->next->next->next, 5);
    list.new_after(list.head->next->next->next->next, 6);
    list.new_after(list.head->next->next->next->next->next, 7);
    list.new_after(list.head->next->next->next->next->next->next, 8);

    k_groups(list, 3);

    EXPECT_EQ(list.head->value, 3);
    EXPECT_EQ(list.head->next->value, 2);
    EXPECT_EQ(list.head->next->next->value, 1);
    EXPECT_EQ(list.head->next->next->next->value, 6);
    EXPECT_EQ(list.head->next->next->next->next->value, 5);
    EXPECT_EQ(list.head->next->next->next->next->next->value, 4);
    EXPECT_EQ(list.head->next->next->next->next->next->next->value, 7);
    EXPECT_EQ(list.head->next->next->next->next->next->next->next->value, 8);
    EXPECT_EQ(list.head->next->next->next->next->next->next->next->next, nullptr);
}
