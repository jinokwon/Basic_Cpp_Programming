#include <iostream>
using namespace std;

class Demo
{
public:
  Demo();
  ~Demo();
};

Demo::Demo()
{
  cout << "Welcome to the constructor!\n";
}
Demo::~Demo()
{
  cout << "The destructor is now running.\n";
}

int main()
{
  Demo demoObject;
  cout << "This program demonstrates an object\n";
  cout << "with a constructor and destroctur.\n";
  return 0;
}