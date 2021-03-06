/*
   Copyright 2011 David Malcolm <dmalcolm@redhat.com>
   Copyright 2011 Red Hat, Inc.

   This is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see
   <http://www.gnu.org/licenses/>.
*/

#include <Python.h>

/*
  Test of various arithmetic operations
*/

extern void __cpychecker_dump(int);

int
test(void)
{
    int i = 0;

    __cpychecker_dump(i++);
    __cpychecker_dump(i++);
    __cpychecker_dump(i--);
    __cpychecker_dump(i * 2);
    __cpychecker_dump(i / 2);
    __cpychecker_dump(i % 2);
    __cpychecker_dump(-i);

    __cpychecker_dump(abs(i));
    __cpychecker_dump(abs(-i));

    /* Bitwise: */
    i |= 0xf0f0;
    i &= 0xaaaa;
    i ^= 0xaaaa;
    __cpychecker_dump(i);


    i = ~i;
    __cpychecker_dump(i);

    /* Bit shifting */
    i <<= 2;
    i >>= 1;

    return i;
}

/*
  PEP-7
Local variables:
c-basic-offset: 4
indent-tabs-mode: nil
End:
*/
