#include <osbind.h>
#include "raster.h"

int main() {
	void *base = Physbase();

	plot_something_1(base, 100, 100);
	plot_something_2(base, 200, 200);

	return 0;
}
