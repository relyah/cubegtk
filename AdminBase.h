#ifndef _ADMINBASE_H_
#define _ADMINBASE_H_

#include "Logger.h"

class AdminBase {

public:
  AdminBase();
  ~AdminBase();

protected:
  log4cpp::Category* logger;
};

#endif
