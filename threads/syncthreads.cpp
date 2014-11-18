#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int shared_x = 1;
mutex allow_in, allow_out;

void x_reader();
void x_printer();

int main()
{
    allow_out.lock();
    thread A(x_reader), B(x_printer);
    A.join();
    B.join();

    cout << "Threads finished successfully!\n";
    return 0;
}

void x_reader()
{
    cin >> shared_x;
    allow_out.unlock();
    while (shared_x != 0)
    {
        allow_in.lock();
        cin >> shared_x;
        allow_out.unlock();
    }
}

void x_printer()
{
    while (shared_x != 0)
    {
        allow_out.lock();
        if (shared_x%2 == 0)
            cout << "Thread printer: " << shared_x << endl;
        allow_in.unlock();
    }
}
