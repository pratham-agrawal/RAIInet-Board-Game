#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"
#include <memory>

class Observer;

class Subject {
  std::vector<std::shared_ptr<Observer>> observers;
 protected:
  void notifyObservers();
 public:
  void attach(std::shared_ptr<Observer> o);
  void detach(std::shared_ptr<Observer> o);
  virtual char getState(int row, int col) const = 0;
  virtual ~Subject() = default;
};

#endif


