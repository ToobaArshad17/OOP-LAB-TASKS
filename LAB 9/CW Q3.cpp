#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Doctor;
class Billing;

class PatientRecord {
    string name;
    string patientID;
    string dateOfBirth;
    vector<string> medicalHistory;
    vector<string> currentTreatments;
    vector<string> billingDetails;

    void updateMedicalHistory(const string& history) {
        medicalHistory.push_back(history);
    }

    void addBillingDetails(const string& billing) {
        billingDetails.push_back(billing);
    }

    public:
        PatientRecord(string name, string id, string dob)
            : name(name), patientID(id), dateOfBirth(dob) {}

        vector<string> getMedicalData() const {
            return medicalHistory;
        }

        friend class Doctor;
        friend class Billing;

        string getPublicData() const {
            return "Name: " + name + "Patient ID: " + patientID + "DOB: " + dateOfBirth;
        }
};

class Doctor {
    public:
        void updateMedicalHistory(PatientRecord& record, const string& history) {
            record.updateMedicalHistory(history);
        }

        vector<string> viewMedicalData(const PatientRecord& record) {
            return record.getMedicalData();
        }
};

class Billing {
    public:
        void addBilling(PatientRecord& record, const string& billing) {
            record.addBillingDetails(billing);
        }

        vector<string> viewBillingData(const PatientRecord& record) {
            return record.billingDetails;
        }
};

class Receptionist {
    public:
        void viewPublicData(const PatientRecord& record) {
            cout << record.getPublicData() << endl;
        }

        void viewSensitiveData(const PatientRecord& record) {
            cout << "Access Denied: Insufficient Permissions" << endl;
        }
};

int main() {
    PatientRecord patient("John Doe", "12345", "1990-05-15");
    Doctor doctor;
    Billing billing;
    Receptionist receptionist;

    cout << "Receptionist viewing public data:";
    receptionist.viewPublicData(patient);

    cout << "Doctor updating and viewing medical data:";
    doctor.updateMedicalHistory(patient, "Patient diagnosed with hypertension.");
    vector<string> medicalData = doctor.viewMedicalData(patient);
    for (const string& record : medicalData) {
        cout << record << endl;
    }

    cout << "Billing staff updating and viewing billing data:";
    billing.addBilling(patient, "Invoice #123: $200");
    vector<string> billingData = billing.viewBillingData(patient);
    for (const string& record : billingData) {
        cout << record << endl;
    }

    cout << "Receptionist trying to access sensitive data:";
    receptionist.viewSensitiveData(patient);

    return 0;
}