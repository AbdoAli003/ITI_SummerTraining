/*
 * BITMATH.h
 *
 *  Created on: Jul 17, 2025
 *      Author: abdoa
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define set(x, pos) x | (1 << pos)
#define rst(x, pos) x & ~(1 << pos)
#define toggle(x, pos) x ^ (1 << pos)
#define read(x, pos) (x >> pos) & 1


#endif /* BITMATH_H_ */
