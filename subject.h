#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

class Subject
{
private:
    std::vector <Observer*> observers;

public:
    Subject();
    void registerObserver(Observer* observer);
    void unregisterObserver(Observer* observer);
    void notify();
    virtual ~Subject();
};

#endif // SUBJECT_H
