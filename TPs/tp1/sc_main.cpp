#include "Generator.h"
#include "bus.h"
#include "Memory.h"

using namespace std;
using namespace sc_core;

int sc_main(int argc, char **argv) {
	Generator generator("Generator1");
	Memory memory ("Memory", 20);
	Bus bus("Bus");
	/*Map at addresses [0x10000000, 0x100000FF]*/
	bus.map(memory.socket, 0x00000000, 0x100000FF);
	/* connect components to the bus */
	generator.socket.bind(bus.target);
	bus.initiator.bind(memory.socket);
	/* and start simulation */
	sc_start();
	return 0;
}
