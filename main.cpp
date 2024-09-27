// If you want to disable RVNO NVO then:
//  -fno-elide-constructors
// use -Wall for unnecessary calls to move


#include <iostream>

class Foo
{
  public:
    Foo() { std::cout << "Called Constructor\n"; }

    Foo( const Foo& other ) { std::cout << "Called Copy Constructor\n"; }

    ~Foo() { std::cout << "Destructor Called\n"; }
};

Foo f()
{
    std::cout << "-- Inside f() before Constructing Foo\n";
    Foo blub;
    std::cout << "-- Inside f() after Constructing Foo\n";
    return std::move(blub);
}


int main()
{
    Foo foo1 = f();

    return 0;
}
