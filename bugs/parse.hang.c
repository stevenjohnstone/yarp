#include <yarp.h>

// WARNING: can lock up desktops, mileage may vary. Memory is allocated in a tight loop

// '!"#'
static uint8_t hang[] = {
  0x21, 0x22, 0x23
};

static void harness(const uint8_t *data, size_t size) {
  yp_buffer_t *buffer = malloc(sizeof(yp_buffer_t));
  yp_buffer_init(buffer);
  yp_parse_serialize((const char *)data, size, buffer);
  yp_buffer_free(buffer);
  free(buffer);
}

int main(int argc, const char **argv) {
  harness(hang, sizeof(hang));
}
