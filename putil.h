//
//  putl.h
//  libpotados
//
//  Created by POTADOS on 07/02/2019.
//  Copyright © 2019 potados. All rights reserved.
//

#ifndef _putil_h
#define _putil_h

/**
 * Iterate array.
 *
 * @param _item_pointer_decl    Declaration for each item.
 * @param _array                Array to iterate.
 *
 * Usage:
 * foreach(int * item, my_int_array) { ... }
 */
#define p_for_each(_item_pointer_decl, _array) \
for(int keep = 1, count = 0, size = sizeof (_array) / sizeof *(_array); \
keep && count != size; \
keep = !keep, count++) \
for(_item_pointer_decl = (_array) + count; keep; keep = !keep)

/**
 * Iterate every digit of integet from LSB.
 *
 * @param _byte_decl        Declaration of byte variable to store each digit.
 * @param _int              Integer to iterate.
 *
 * Usage:
 * foreach_int_from_lsb(byte digit, 96400) { ... }
 */
#define p_for_each_int_from_lsb(_byte_decl, _int)                       \
for(int _digit_place = 0, _keep = 1, _num = _int;                       \
_num != 0;                                                              \
_num /= 10, ++_digit_place, _keep = !_keep)                             \
for (_byte_decl = _num % 10; _keep; _keep = !_keep)

#endif /* _putil_h */
