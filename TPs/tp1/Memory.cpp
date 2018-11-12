#include "Memory.h"

using namespace std;
using namespace sc_core;
using namespace tlm;

Memory::Memory(sc_module_name name, ensitlm::data_t taille)
              : sc_module(name), size(taille) {
  stockage = (ensitlm::data_t *)(malloc(size));
  std::cout << "my size is : " << size <<" my adress is :"<< stockage <<'\n';
}
Memory::~Memory(){
  delete[] stockage;
}
tlm_response_status Memory::read (const ensitlm::addr_t &a,
                                  ensitlm::data_t &d){
  assert(a <= size);
  if (a % 4 != 0) {
    std::cout << "error access to a non valid address" << '\n';
    return tlm::TLM_ADDRESS_ERROR_RESPONSE;
  }
  d = stockage[a / sizeof(ensitlm::data_t)];
  return tlm::TLM_OK_RESPONSE;
}
tlm_response_status Memory::write (const ensitlm::addr_t &a,
                                  const ensitlm::data_t &d){
  assert(a <= size);
  if (a % 4 != 0) {
    std::cout << "error access to a non valid address" << '\n';
    return tlm::TLM_ADDRESS_ERROR_RESPONSE;
  }
  stockage[a / sizeof(ensitlm::data_t)] = d;
  return tlm::TLM_OK_RESPONSE;
}
