#ifndef MEMORY_H
#define MEMORY_H

#include "ensitlm.h"
#include "bus.h"

struct Memory : sc_core::sc_module {
  ensitlm::target_socket<Memory> socket;
  ensitlm::data_t * stockage;
  ensitlm::data_t size;
  Memory(sc_core::sc_module_name name,
    ensitlm::data_t taille);
  tlm::tlm_response_status
    read(const ensitlm::addr_t &a, ensitlm::data_t &d);
  tlm::tlm_response_status
    write(const ensitlm::addr_t &a, const ensitlm::data_t &d);
  ~Memory();
};

#endif
