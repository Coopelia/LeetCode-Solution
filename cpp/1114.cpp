#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class Foo
{
public:
    mutex mt_1, mt_2, mt_3;
    Foo()
    {
        mt_2.lock();
        mt_3.lock();
        mt_1.unlock();
    }

    void first(function<void()> printFirst)
    {
        mt_1.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mt_2.unlock();
    }

    void second(function<void()> printSecond)
    {
        mt_2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mt_3.unlock();
    }

    void third(function<void()> printThird)
    {
        mt_3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        mt_1.unlock();
    }
};