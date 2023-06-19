#include <yarp.h>

// "%I0\0#$0"
static uint8_t use_after_free[] = {
  0x25, 0x49, 0x30, 0x5c, 0x30, 0x23, 0x24, 0x30, 0x0a
};

static void harness(const uint8_t *data, size_t size) {
  yp_buffer_t *buffer = malloc(sizeof(yp_buffer_t));
  yp_buffer_init(buffer);
  yp_parse_serialize((const char *)data, size, buffer);
  yp_buffer_free(buffer);
  free(buffer);
}

int main(int argc, const char **argv) {
  harness(use_after_free, sizeof(use_after_free));
}
