#ifndef __BULLET_H
#define __BULLET_H

#include "types.h"

/* Struct to handle bullet information */
typedef struct
    {
        /* Bullet position */
        float bulletX;
        float bulletY;

        /* Bullet hit */
        bool bulletHit;

}Bullet;

/* Function to get bullet position */
void getBulletPos
    (
    Bullet b,
    float *x,
    float *y
    );

#endif