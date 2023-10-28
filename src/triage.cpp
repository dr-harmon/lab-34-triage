#include "triage.h"

using namespace std;

Patient::Patient(int id, int respiratoryRate, int radialPulse, float capillaryRefill,
                 bool canFollowCommands, bool canWalk)
{
    this->id = id;
    this->respiratoryRate = respiratoryRate;
    this->radialPulse = radialPulse;
    this->capillaryRefill = capillaryRefill;
    this->canFollowCommands = canFollowCommands;
    this->canWalk = canWalk;
}

int Patient::getID() const
{
    return id;
}

Patient::Tag Patient::getTag() const
{
    // TODO
    return GREEN;
}

ostream& operator<<(ostream& os, const Patient& patient)
{
    os << patient.getID() << ": ";
    switch (patient.getTag()) {
        case Patient::GREEN:
            os << "green";
            break;
        case Patient::YELLOW:
            os << "yellow";
            break;
        case Patient::RED:
            os << "red";
            break;
        case Patient::BLACK:
            os << "black";
            break;
    }
    return os;
}

HospitalER::HospitalER(const vector<Patient>& patients)
{
}

Patient HospitalER::treatPatient()
{
    // TODO
}

bool HospitalER::hasPatients() const
{
    // TODO
    return false;
}
