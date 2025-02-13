#include<iostream>
using namespace std;

class Date{
private:
int month;
int day;
int year;

public:
void setMonth(int m){
month = m;
}

void setDay(int d){
day =d;
}

void setYear(int y){
year = y;
}

void displayDate(){
cout << month << "/" << day << "/" << year << endl;

}
};

int main(){
Date date;

date.setDay(12);
date.setMonth(3);
date.setYear(2025);

date.displayDate();

return 0;
}
