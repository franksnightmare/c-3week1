#include "semaphore.ih"

#include <iostream>

bool test(int someInt)
{
	cout << "We done!\n";
	return true;
}

int main()
{
    Semaphore mx(5);
    
    mx.wait(test, 5);
    mx.wait(test, 5);
    mx.wait(test, 5);
    mx.wait(test, 5);
    mx.wait(test, 5);
    
}
