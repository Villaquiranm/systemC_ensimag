#include "Generator.h"
#include "bus.h"

using namespace std;
using namespace sc_core;

int sc_main(int argc, char **argv) {
	Generator generator("Generator1");
	Bus bus("Bus");

	/* connect components to the bus */
	generator.socket.bind(bus.target);
	//router.initiator.bind(b.socket);
	/* and start simulation */
	sc_start();
	return 0;
}
