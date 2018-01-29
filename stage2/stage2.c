#include <osbind.h>
#include "raster.h"

int main() {
	void *base = Physbase();
	plot_horizontal_line(base, 39, 96, 39);
	plot_vertical_line(base, 39, 39, 88);

	print_string(base, 40, 40, "hello string");
	print_num(base, 40, 50, 9999);
	print_num(base, 40, 60, 0);
	print_num(base, 40, 70, 5);
	print_num(base, 40, 80, 123);
	return 0;
}
