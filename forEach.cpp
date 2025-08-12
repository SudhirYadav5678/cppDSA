// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
  
//   	vector<int> arr = {1, 2, 3, 4, 5};
    
//     // By value
//     cout << "Iterating by value" << endl;
//     for(auto it : arr){
//         cout << it <<" ";
//     }
//     cout<< endl;
    
//     // By reference
//     cout << "Iterating with reference" << endl;
//     for(auto &it : arr){
//         cout << it << " ";
//     }
//     cout<<endl;
//     return 0;
// }

//infinte loop
#include <iostream>
using namespace std;

int main() {

    // This is an infinite for loop as the condition
    // expression is blank
    for (;;) {
        cout << "This loop will run forever.\n";
    }
	return 0;
}