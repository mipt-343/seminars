#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void printHello(mutex *out_mutex)
{
    cout << "Hello, World!\n";
    for(int i = 0; i < 10; i++)
    {
        lock_guard<mutex> lock_out(*out_mutex);
        cout << "thread: " << i << endl;
    }
}

int main()
{
    mutex out_mutex;
    thread A(printHello, &out_mutex);

    cout << "Main thread\n";
    for(int i = 0; i < 10; i++)
    {
        lock_guard<mutex> lock_out(out_mutex);
        cout << "main: " << i << endl;
    }
    
    A.join();
    cout << "The end.\n";

    return 0;
}
