#include <yarp.h>

// "(=>*,;\r)\r"
static uint8_t double_free[] = {
  0x28, 0x3d, 0x3e, 0x2a, 0x2c, 0x3b, 0x0a, 0x29, 0x0a
};


static void harness(const uint8_t *data, size_t size) {
  yp_buffer_t *buffer = malloc(sizeof(yp_buffer_t));
  yp_buffer_init(buffer);
  yp_parse_serialize((const char *)data, size, buffer);
  yp_buffer_free(buffer);
  free(buffer);
}

int main(int argc, const char **argv) {
  harness(double_free, sizeof(double_free));
}
