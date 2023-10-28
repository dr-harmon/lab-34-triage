# Lab 34: Triage

In this lab, we will simulate the [triage](https://en.wikipedia.org/wiki/Triage) of patients in a hospital emergency room (ER). Triage is a process by which patients are treated in order of priority, where those with the most severe and life-threatening conditions have highest priority. (More than one patient may have the same priority.)

For the simulation, we will triage according to the [START method](https://en.wikipedia.org/wiki/Simple_triage_and_rapid_treatment), which classifies patients into one of four color-coded categories:

* Green (wounded/minor): can walk
* Red (immediate): more than 30 breaths per minute _or_ no pulse _or_ capillary refill time of more than two seconds _or_ can't follow simple commands
* Black (deceased): not breathing
* Yellow (delayed): all others

## Requirements

Some C++ code has been provided to help get you started:

* `Patient`: models a patient's vital signs.
* `HospitalER`: takes a vector of patients as input and "treats" them in order of priority: black, red, yellow, green.

Your task is to use the STL [priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue) within the `HospitalER` class so that its `treatPatient` method returns patients in the correct triage order. You will also need to add code so that the queue can order the patients according to their START tags.

When you are finished, make sure the provided unit test passes.

## Hints

* There are many ways to initialize a `std::priority_queue` from a set of objects. If the objects are already in an STL container class, such as `std::vector`, then one of the simplest and most efficient ways is to pass the vector's `begin` and `end` iterators to the `priority_queue` constructor.
* There are many ways to define an ordering for `std::priority_queue`. One way is to overload the less-than operator on the queue's element type. For example: `bool Patient::operator<(const Patient& other) const { ... }`.
* The `Tag` enum is part of the `Patient` class, so to reference the `Tag` type outside of `Patient`, you must fully qualify it as `Patient::Tag`.
