#include <iostream>
#include <string>
#include <functional>

void callDoIt(std::function<void(int)> fn, int value)
{
    if (fn)
        fn(value);
}

class Foo
{
public:
    void doIt(int value)
    {
        std::cout << "Doing it for " << value << "..." << std::endl;
    }

    void work(int value)
    {
        using namespace std::placeholders;
        callDoIt(std::bind(&Foo::doIt, this, _1), value);
    }
};

int main(int argc, const char *argv[])
{
    Foo foo;
    foo.work(15);
    return 0;
}
