#include "Generator.h"
#include "bus.h"

using namespace std;
using namespace sc_core;

int sc_main(int argc, char **argv) {
	/*
	 +---------+	+-------------+	   +--------+
	 |	  +++  +-+	     +++  +++	    |
	 | Alice  | +--+ |  Router   | +--+ |  Bob  |
	 |	  +++  +-+	     +++  +++	    |
	 +---------+	+-------------+	   +--------+
	 */

	Generator generator("Generator1");
	//target b("Bob");
	Bus bus("Bus");

	/* Bob is mapped at addresses [0, 100[, i.e. ... */
	//router.map(b.socket, 0, 100);

	/* connect components to the bus */
	generator.socket.bind(bus.target);
	//router.initiator.bind(b.socket);

	/* and start simulation */
	sc_start();
	return 0;
}
