#include "Memory.h"

using namespace std;
using namespace sc_core;
using namespace tlm;

Memory::Memory(sc_module_name name) : sc_module(name) {

}
tlm_response_status Memory::read (const ensitlm::addr_t &a, const ensitlm::data_t &d){
  cout << name() <<" read, address : " << a <<" data: " << d << '\n';
}
tlm_response_status Memory::write (const ensitlm::addr_t &a, const ensitlm::data_t &d){
  cout << name() <<" write, address : " << a <<" data: " << d << '\n';
}
