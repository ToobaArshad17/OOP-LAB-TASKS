#include <iostream>
using namespace std;

class Blend{
    public:
        void blend(){
            cout << "Blending Juice!!\n";

            for (int i=0 ; i<5 ; i++){
                cout << "Blending in progress..(" << i + 1 << " seconds)" << endl;
                for (int j=0 ; j<100000 ; j++) {}
            }
            cout << "Juice blended successfully!!\n" << endl;
        }
};

class Grind{
    public:
        void grind(){
            cout << "Grinding fruits!!\n";

            for (int i=0 ; i<5 ; i++){
                cout << "Grinding in progress..(" << i + 1 << " seconds)" << endl;
                for (int j=0 ; j<100000 ; j++) {}
            }
            cout << " Fruits grinded successfully!!\n" << endl;
        }
};

class JuiceMaker{
    Blend blender;
    Grind grinder;

    public:
        void blendJuice() {
            blender.blend();
        }
        void grindJuice() {
            grinder.grind();
        }
};

int main(){
    JuiceMaker juice_maker;

    cout << "STARTING TO MAKE JUICE...\n";
    juice_maker.blendJuice();
    juice_maker.grindJuice();
    cout << "JUICE PREPARATION COMPLETE!\n";

    return 0;
}