#include <osbind.h>
#include "raster.h"
#include "bitmap.h"

int main() {
	void *base = Physbase();
  plot_bitmap(base, 623, 367, bitmap, BITMAP_HEIGHT);
	return 0;
}

