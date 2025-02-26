#include <gtest/gtest.h>

#include <chrono>
#include <fmt/format.h>
#include <thread>

#include "blocking_queue.h"

TEST(BlockingQueues, NewBQShouldBeEmpty)
{
    BlockingQueue<int> bq;
    EXPECT_TRUE(bq.empty());
}

TEST(BlockingQueues, EnQ_SizeUpByOne)
{
    BlockingQueue<int> bq;
    bq.enqueue(42);
    EXPECT_EQ(bq.size(), 1);
    EXPECT_EQ(bq.peek(), 42);

    bq.enqueue(43);
    EXPECT_EQ(bq.size(), 2);
    EXPECT_EQ(bq.peek(), 42);
}

TEST(BlockingQueues, DeQ_SizeDownByOne)
{
    BlockingQueue<int> bq;
    bq.enqueue(42);
    bq.enqueue(43);

    EXPECT_EQ(bq.size(), 2);

    auto i = bq.dequeue();
    EXPECT_EQ(i, 42);
    EXPECT_EQ(bq.size(), 1);

    i = bq.dequeue();
    EXPECT_EQ(i, 43);
    EXPECT_EQ(bq.size(), 0);
    EXPECT_TRUE(bq.empty());
}

void EnQThreadFunction(int threadNum, std::chrono::milliseconds sleep_duration, int count, BlockingQueue<int> &bq) {
    for (int i = 0; i < count; ++i)
    {
        bq.enqueue(threadNum + i);
        std::this_thread::sleep_for(sleep_duration);
    }
}

void DeQThreadFunction(int threadNum, std::chrono::milliseconds sleep_duration, BlockingQueue<int> &bq) {
    using namespace std::chrono_literals;

    // Wait for data in the Q
    while (bq.empty())
    {
        std::this_thread::sleep_for(10ms);
    }

    while (!bq.empty())
    {
        int val{ bq.dequeue() };
        fmt::println("{} -- {}", threadNum, val);
        std::this_thread::sleep_for(sleep_duration);
    }

    EXPECT_TRUE(bq.empty());
}

TEST(BlockingQueues, MultiProducerTest) {
    using namespace std::chrono_literals;

    BlockingQueue<int> bq;

    {
        std::jthread enq_t1(EnQThreadFunction, 1000, 50ms, 25, std::ref(bq));
        std::jthread enq_t2(EnQThreadFunction, 2000, 75ms, 25, std::ref(bq));
        std::jthread enq_t3(EnQThreadFunction, 3000, 25ms, 25, std::ref(bq));
        std::jthread enq_t4(EnQThreadFunction, 4000, 100ms, 25, std::ref(bq));
        std::jthread enq_t5(EnQThreadFunction, 5000, 125ms, 25, std::ref(bq));

        std::jthread deq_t1(DeQThreadFunction, 1, 100ms, std::ref(bq));
    }
}

TEST(BlockingQueues, MultiConsumerTest) {
    using namespace std::chrono_literals;

    BlockingQueue<int> bq;

    {
        std::jthread enq_t1(EnQThreadFunction, 1000, 10ms, 200, std::ref(bq));

        std::jthread deq_t1(DeQThreadFunction, 1, 100ms, std::ref(bq));
        std::jthread deq_t2(DeQThreadFunction, 2, 110ms, std::ref(bq));
        std::jthread deq_t3(DeQThreadFunction, 3, 120ms, std::ref(bq));
        std::jthread deq_t4(DeQThreadFunction, 4, 130ms, std::ref(bq));
        std::jthread deq_t5(DeQThreadFunction, 5, 140ms, std::ref(bq));
    }
}
