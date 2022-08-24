//
// Created by XENSF101 on 2022-08-24.
//

#ifndef C_POS_H
#define C_POS_H

typedef struct pos{
    int x, y;
} Position;

Position move_to(Position pos, int dir);

#endif //C_POS_H
