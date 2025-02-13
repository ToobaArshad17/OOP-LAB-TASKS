#include<iostream>
using namespace std;

class User{
public:
int age;
string name;
};

int main(){
User user1;
user1.name = "laiba";
user1.age = 20;
cout << "The name is " << user1.name << " and my age is " << user1.age << endl;

return 0;
}