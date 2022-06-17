#include <thread>
#include <iostream>
#include <mutex>
#include <iomanip>

class ThreadManager
{
public:
    static std::mutex m1;
    static std::mutex m2;
};

std::mutex ThreadManager::m1;
std::mutex ThreadManager::m2;

class Thread1Function : public ThreadManager
{
public:
    void operator()(int a)
    {

        for (int i = 0; i < a; i++)
        {
            ThreadManager::m1.lock();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::this_thread::get_id();
            std::cout << "From thread1 " << std::endl;
            std::cout << "unLocking thread 2" <<std::endl;
            ThreadManager::m2.unlock();
            std::cout << "Locking thread 1" <<std::endl;
            ThreadManager::m1.lock();
        }
    }
};

class Thread2Function : public ThreadManager
{
public:
    void operator()(int b)
    {
        for (int i = 0; i < b; i++)
        {
            ThreadManager::m2.lock();
            std::cout << "From thread2 " << std::endl;
            std::cout << "unlocking thread 1 " << std::endl;
            ThreadManager::m1.unlock();
            std::cout << "locking thread 2 " << std::endl;
            ThreadManager::m2.lock();
        }
    }
};

int main(int argc, char const *argv[])
{

    Thread1Function worker1;
    Thread2Function worker2;
    ThreadManager::m2.lock();
    std::thread t1(worker1, 10);
    std::thread t2(worker2, 10);
    t1.join();
    t2.join();
    return 0;
}
