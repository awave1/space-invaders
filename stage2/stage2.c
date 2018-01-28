#include <osbind.h>
#include "raster.h"

int main() {
	void *base = Physbase();
	int i = 0;

	plot_pixel(base, 40, 40);
	plot_pixel(base, 41, 41);
	plot_pixel(base, 42, 42);

	for (i = 0; i < 100; i++) {
	}

	clear_screen();

	return 0;
}
