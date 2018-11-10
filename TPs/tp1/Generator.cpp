#include "Generator.h"

using namespace std;
using namespace sc_core;

void Generator::thread(void) {
	ensitlm::data_t val = 1;
	ensitlm::addr_t addr = 4;
	while (true) {
		cout << "Entrer un nombre" << endl;
		cin >> val;
		cout << "je vais envoyer : " << std::dec << val << endl;
		socket.write(addr, val);
	}
}

Generator::Generator(sc_module_name name) : sc_module(name) {
	SC_THREAD(thread);
}
