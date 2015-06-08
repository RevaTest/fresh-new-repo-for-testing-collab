#include <iostream>
#include <string>
#include <functional>

void callDoIt(std::function<void()> fn)
{
    if (fn)
        fn();
}

class Foo
{
public:
    void doIt()
    {
        std::cout << "Doing it..." << std::endl;
    }

    void work()
    {
        using namespace std::placeholders;
        callDoIt(std::bind(&Foo::doIt, this));
    }

    void print()
    {
        std::cout << "Printing stuff" << std::endl;
    }
};

int main(int argc, const char *argv[])
{
    Foo foo;
    foo.work();
    return 0;
}
