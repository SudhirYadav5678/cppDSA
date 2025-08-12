#include<iostream>
using namespace std;

struct s{
    int n;
    string name;
};
// struct {
//     int n;
//     string name;
// } st;

int main(){
    s st;
    st.n=1;
    st.name ="Sudhir";

    cout << st.n << "\n";
    cout << st.name << "\n";
    return 0;
}