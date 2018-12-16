#ifndef FILTER_H
#define FILTER_H
#include <vector>
#include "business.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>
#include <string>

vector<business> filter( string res_cnt, string is_open, string tag, string latitude, string longitude, int distance, string rank);


#endif // FILTER_H
