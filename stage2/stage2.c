#include <osbind.h>
#include "raster.h"

int main() {
	void *base = Physbase();
	plot_line(base, 40, 40, 90, 90);
	plot_horizontal_line(base, 40, 90, 40);
	plot_vertical_line(base, 40, 40, 90);
	return 0;
}
