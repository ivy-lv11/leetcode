#include <mutex>
#include <iostream>
#include <iostream>
#include <thread>
using namespace std;

int g_i = 0;
mutex g_i_lock;

void safe_thread_increment()
{
    std::lock_guard<mutex> lock(g_i_lock);
    ++g_i;
    cout<<g_i<<" in thread "<<std::this_thread::get_id()<<endl;
}

int main()
{
    std::thread th1(safe_thread_increment);
    std::thread th2(safe_thread_increment);
    th1.join();
    th2.join();
    return 0;
}
