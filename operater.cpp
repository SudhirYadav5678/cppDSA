//   Miscellaneous Operators  ////

//sizeof Operator
//sizeof (char);
//sizeof (var_name);
//Comma Operator (,)
//a = (b = 3, b + 2);
//Addressof Operator (&)
//int* ptr = &a;
//Dot Operator.
//obj . member;
// Arrow Operator
//               Arrow operator is used to access the variables of classes or structures through its pointer.
//               sptr -> member;
//this->x = x;  pointer to the current object

// new and delete Operators
// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     // Declared a pointer to store
//     // the address of the allocated memory
//     int *nptr;
    
//     // Allocate and initialize memory
//     nptr = new int(6);

//     // Print the value
//     cout << *nptr << endl;

//     // Print the address of memory
//     // block
//     cout << nptr;
//     return 0;
// }
// delete operator
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     // Declared a pointer to store
//     // the address of the allocated memory
//     int *nptr;
//     // Allocate and initialize memory
//     nptr = new int(6);
//     // Print the value
//     cout << *nptr << endl;
//     // Print the address of memory
//     // block
//     cout << nptr << endl;
//     // Deallocate memory
//     delete nptr;
//     // Print the address of memory
//     // block after deallocation

//     cout << nptr << endl;                                                                            
//     // Print the value after deallocation
//     cout << *nptr << endl; // Undefined behavior, accessing deleted memory
//     return 0;
// }