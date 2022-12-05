#ifndef __addGraphics_H__
#define __addGraphics_H__
#include <string>
#include "observer.h"
#include "board.h"
#include "window.h"

class addGraphics: public Observer {
  std::shared_ptr<Board> subject;
  std::shared_ptr<Xwindow> window;

 public:
  addGraphics(std::shared_ptr<Board> s);
  void notify() override;
  ~addGraphics();
};

#endif

