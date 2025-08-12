#include<iostream>
using namespace std;

// enum LEVEL{
//     LOW,
//     HIGH
// };
// enum Level {
//   LOW = 25,
//   MEDIUM = 50,
//   HIGH = 75
// }; 
enum Level {
  LOW = 1,
  MEDIUM,
  HIGH
};
int main(){
    enum Level v =HIGH;
    cout<<v;
    return 0;

}