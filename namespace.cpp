// #include <iostream>
// using namespace std;

// inline namespace inline_space {
//     void display() {
//         cout << "Inside inline namespace";
//     }
// }

// int main() {
    
//     // Direct access due to inline namespace
//     display();  
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// namespace nmsp{
//     void func(){
//         cout << "You can extend me" << endl;
//     }
// }

// // Extending the same namespace
// namespace nmsp{
//     void func2(){
//         cout << "Adding new feature";
//     }
// }

// int main() {
//     nmsp::func();
//     nmsp::func2();

//     return 0;
// }

#include <iostream>
using namespace std;

// Anonymous namespace
namespace {
    int value = 10;
}

int main() {
    
    // Accessing anonymous namespace variable
    cout << value;  
    return 0;
}