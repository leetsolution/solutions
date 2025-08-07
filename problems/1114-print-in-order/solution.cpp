#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class Foo {
private:
    std::mutex mtx;
    std::condition_variable cv1, cv2;
    bool firstDone = false;
    bool secondDone = false;

public:
    Foo() {
        
    }

    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);
        printFirst();
        firstDone = true;
        cv1.notify_one();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv1.wait(lock, [this]{ return firstDone; });
        printSecond();
        secondDone = true;
        cv2.notify_one();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv2.wait(lock, [this]{ return secondDone; });
        printThird();
    }
};