//
// Created by john on 2016/11/13.
//

#ifndef TOUR_SEARCH_H
#define TOUR_SEARCH_H

#include "create.h"

void inputTheDetail(ALGraph &g, bool isDetail);

void searchNode(ALGraph &g);

void sortByPopular(ALGraph &g);

void quickSort(int *pInt, int lo, int hi);
#endif //TOUR_SEARCH_H
