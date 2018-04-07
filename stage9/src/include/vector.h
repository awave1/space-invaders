#ifndef SPACE_INVADERS_VECTOR_H
#define SPACE_INVADERS_VECTOR_H

#define VBL_ISR 28

typedef void (*Vector) ();

Vector install_vector(int trap_num, Vector vector);


#endif /* SPACE_INVADERS_VECTOR_H */

