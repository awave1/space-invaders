#include <osbind.h>
#include "raster.h"

int main() {
	void *base = Physbase();
	plot_vertical_line(base, 40, 40, 350);
	return 0;
}
