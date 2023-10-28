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

bool Patient::operator<(const Patient& other) const
{
    return getTag() < other.getTag();
}

Patient::Tag Patient::getTag() const
{
    if (respiratoryRate == 0) {
        return BLACK;
    }

    if (respiratoryRate > 30 || radialPulse == 0 || capillaryRefill > 2 || !canFollowCommands) {
        return RED;
    }

    if (canWalk) {
        return GREEN;
    }

    return YELLOW;
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

HospitalER::HospitalER(const vector<Patient>& patients) : q(patients.begin(), patients.end())
{
}

Patient HospitalER::treatPatient()
{
    Patient p = q.top();
    q.pop();
    return p;
}

bool HospitalER::hasPatients() const
{
    return !q.empty();
}
