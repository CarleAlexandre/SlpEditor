#include "dlfcn.h"
#include <stdbool.h>
#include <assert.h>

int main(int argc, char** argv) {
	bool reload = false;
	void* lib = 0x00;
	lib = dlopen("build/libeditor.so", RTLD_LAZY);
	assert(lib);
	int (*main_entry)(int, char **) = 0x00;
	main_entry = dlsym(lib, "main_entry");
	while (1) {
		if (reload) {
			dlclose(lib);
			lib = 0x00;
			lib = dlopen("build/libeditor.so", RTLD_LAZY);
			assert(lib);
			main_entry = 0x00;
			main_entry = dlsym(lib, "main_entry");
		}
		if (main_entry) {
			int ret = main_entry(argc, argv);
			if (ret != 0) {
				return (ret);
			}
		}
		//should sleep here
	}
	dlclose(lib);
	return (0);
}
