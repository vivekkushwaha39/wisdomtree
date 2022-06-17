#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    
    std::basic_string s1("how");
    cout << s1.capacity() << "\n";

    string s = "How are you";
    cout << s.capacity() << "\n" << s.size() << "\n";
    s.shrink_to_fit();
    cout << s.capacity() << "\n" << s.size() << "\n";

    return 0;
}
