#ifndef __addText_H__
#define __addText_H__
#include <string>
#include "observer.h"
#include "board.h"

class addText: public Observer {
  board *subject;
  
 public:
  addText(board *s);
  void notify() override;
  ~addText();
};

#endif

