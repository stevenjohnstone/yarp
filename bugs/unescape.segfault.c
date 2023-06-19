#include <yarp.h>

// (=>a:,
static uint8_t segfault[] = {
  0x28, 0x3d, 0x3e, 0x61, 0x3a, 0x2c, 0x0a
};



static void harness(const uint8_t *data, size_t size) {
  yp_buffer_t *buffer = malloc(sizeof(yp_buffer_t));
  yp_buffer_init(buffer);
  yp_parse_serialize((const char *)data, size, buffer);
  yp_buffer_free(buffer);
  free(buffer);
}

int main(int argc, const char **argv) {
  harness(segfault, sizeof(segfault));
}
