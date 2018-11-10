#ifndef MEMORY_H
#define MEMORY_H

#include "ensitlm.h"
#include "bus.h"

struct Memory : sc_core::sc_module {
	ensitlm::target_socket<Memory> socket;
	SC_CTOR(Memory);
  tlm::tlm_response_status
    read(const ensitlm::addr_t &a, const ensitlm::data_t &d);
  tlm::tlm_response_status
    write(const ensitlm::addr_t &a, const ensitlm::data_t &d);
};

#endif
