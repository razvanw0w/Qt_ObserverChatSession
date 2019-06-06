#include "subject.h"
#include <algorithm>

Subject::Subject()
{

}

void Subject::registerObserver(Observer *observer)
{
    observers.push_back(observer);
}

void Subject::unregisterObserver(Observer *observer)
{
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Subject::notify()
{
    for (Observer *observer: observers) {
        observer->update();
    }
}

Subject::~Subject()
{
    for (Observer *p: observers) {
        delete p;
    }
}
