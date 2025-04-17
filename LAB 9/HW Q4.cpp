#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        virtual double getTuition(string status, int creditHours) = 0;
        virtual ~Student() {}
};

class GraduateStudent : public Student {
    string researchTopic;

    public:
        double getTuition(string status, int creditHours) override {
            double rate = 0.0;
            
            if (status == "undergraduate") {
                rate = 200.0;
            } 
            else if (status == "graduate") {
                rate = 300.0;
            } 
            else if (status == "doctoral") {
                rate = 400.0;
            }
            
            return rate * creditHours;
        }
        
        void setResearchTopic(const string& topic) {
            researchTopic = topic;
        }
        
        string getResearchTopic() const {
            return researchTopic;
        }
};

int main() {
    GraduateStudent gradStudent;
    
    gradStudent.setResearchTopic("Machine Learning in Healthcare");
    
    double tuition = gradStudent.getTuition("graduate", 12);
    
    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;
    cout << "Tuition for 12 credit hours: $" << tuition << endl;
    
    return 0;
}