#include <osbind.h>
#include "raster.h"

int main() {
	void *base = Physbase();
	plot_line(base, 40, 40, 90, 90);
	return 0;
}
