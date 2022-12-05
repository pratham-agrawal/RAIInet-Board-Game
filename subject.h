#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"

class Observer;

class Subject {
  std::vector<Observer*> observers;
 protected:
  void notifyObservers();
 public:
  void attach(Observer *o);
  void detach(Observer *o);
  virtual char getState(int row, int col) const = 0;
  virtual ~Subject() = default;
};

#endif


