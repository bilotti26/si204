#pragma once
#include <iostream>
using namespace std;
#include "point.h"
#include "hhmmss.h"

struct datum
{
  point position;
  hhmmss time;
};
istream& operator >> (istream& is, datum& D);
