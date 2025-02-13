include<iostream>
using namespace std;


class Glass{
public:
int liquidLevel = 200;

void Drink(int millilitres){
liquidLevel -= millilitres;
}

void refill(){
if(liquidLevel <= 200){
liquidLevel =200;
cout << "Refilled" << endl;
}
}
};

int main(){

Glass glass;
int mmDrank;


do{
cout << "1.Enter mm drank or 0 to terminate: " ;
cin >> mmDrank;


if (mmDrank == 0){
break;
}else{
glass.Drink(mmDrank);
glass.refill();
}

}while(mmDrank != 0);

return 0;


}