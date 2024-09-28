// if you want to disable rvno nvo then:
//  -fno-elide-constructors
// use -wall for unnecessary calls to move

#include <iostream>

class foo
{
  public:
    foo() { std::cout << "called constructor\n"; }
    foo( const foo& other ) { std::cout << "called copy constructor\n"; }
    foo& operator=( const foo& rhs )
    {
        std::cout << "called assignemnt constructor\n";
        return *this;
    }
    foo( foo&& other ) { std::cout << "Called move constructor\n"; }

    ~foo() { std::cout << "destructor called\n"; }

    int32_t i = 0;
};

foo f()
{
    std::cout << "-- inside f() before constructing foo\n";
    foo blub;   // 2) Calling Constructor
    std::cout << "-- inside f() after constructing foo\n";
    return blub;
}

foo f_nrvo_multiple_paths( int32_t x )
{
    std::cout << "-- inside f() before constructing foo\n";
    if ( x % 2 == 0 )
    {
        std::cout << "Foo1\n";
        foo foo1;
        return foo1;
    }

    std::cout << "Foo2\n";
    foo foo2;
    return foo2;
}

foo f_rvo()
{
    std::cout << "-- inside f_rvo()\n";
    return foo();
}

void f_nrvo_multiple_paths_working( foo& foo12, bool flag )
{
    std::cout << "-- inside f() before constructing foo\n";

    if ( flag )
    {
        foo12.i = 123;
        return;
    }

    foo12.i = 1222;
    return;
}

int main()
{
    foo bar;
    f_nrvo_multiple_paths_working( bar, true );

    return 0;
}
