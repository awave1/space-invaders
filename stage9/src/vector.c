#include "include/vector.h"

Vector install_vector(int trap_num, Vector vector) {
  Vector orig;
  Vector* vectp = (Vector*) ((long) trap_num << 2);
  long old_ssp = Super(0);

  orig = *vectp;
  *vectp = vector;

  Super(old_ssp);
  return orig;
}

