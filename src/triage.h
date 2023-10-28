#pragma once

#include <ostream>
#include <queue>
#include <vector>

// Represents a patient in the ER with an ID number, vital signs, and a START tag.
class Patient {
public:

    // START tag for triage.
    enum Tag {
        GREEN, YELLOW, RED, BLACK
    };

    // Constructs a new patient with the given ID number and vital signs.
    Patient(int id, int respiratoryRate, int radialPulse, float capillaryRefill,
            bool canFollowCommands, bool canWalk);

    // Returns the patient's ID number.
    int getID() const;

    // Returns the START tag for the patient according to the vital signs.
    Tag getTag() const;

    // Prints patient information to the output stream for debugging purposes.
    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);

    // Returns whether the given patient should be triaged before the current one.
    bool operator<(const Patient& other) const;

private:
    // An ID number. Should be unique (no two patients with the same number).
    int id;

    // Breaths per minute.
    int respiratoryRate;

    // Standard pulse, taken at the wrist, in beats per minute.
    int radialPulse;

    // Time, in seconds, to refill the capillaries (Capillary Refill Test, or CRT).
    float capillaryRefill;

    // Whether the patient is alert enough to follow simple commands.
    bool canFollowCommands;

    // Whether the patient is able to walk to another area.
    bool canWalk;
};

// Simulates ER triage in a hospital.
class HospitalER {
public:

    // Creates a new ER object with the given list of patients needing triage.
    HospitalER(const std::vector<Patient>& patients);

    // Triages the patients according to the START method and treats one who is
    // most in need. If more than one patient is at the same triage level, the
    // order of treatment is undefined.
    Patient treatPatient();

    // Returns true if some patients still need treatment; false if all patients
    // have been triaged and treated.
    bool hasPatients() const;

private:
    std::priority_queue<Patient> q;
};
