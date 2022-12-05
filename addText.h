#ifndef __addText_H__
#define __addText_H__
#include <string>
#include "observer.h"
#include "board.h"
#include <memory>

class addText: public Observer {
  std::shared_ptr<Board> subject;
  //Board *subject;
  
 public:
 addText(std::shared_ptr<Board> s);
  //addText(Board *s);
  void notify() override;
  ~addText();
};

#endif

