#include <osbind.h>
#include "raster.h"
#include "bitmap.h"

int main() {
	void* base = Physbase();

	plot_rectangle(base, 0, 0, 640, 400);
	clear_screen(base);

	return 0;
}

