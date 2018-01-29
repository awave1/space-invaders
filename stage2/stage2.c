#include <osbind.h>
#include "raster.h"

int main() {
	void *base = Physbase();
	print_string(base, 40, 40, "hello string");
	return 0;
}
