#include "Generator.h"

using namespace std;
using namespace sc_core;

void Generator::thread(void) {
	//ensitlm::data_t val = 10;
	ensitlm::addr_t addr = 0x10000000;
  for (int i = 0; i < 11; i++) {
    cout << name() <<" sends: " << std::dec << i << endl;
    socket.write(addr, i);
    addr= addr + 0x00000010;
    /*What if addresses are incremented by 0x00000001; */
  }
}

Generator::Generator(sc_module_name name) : sc_module(name) {
	SC_THREAD(thread);
}
