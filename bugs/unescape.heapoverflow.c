#include <yarp.h>
#include <unistd.h>

// Demonstrating how an out-of-bounds read turns into an out-of-bounds heap
// write (heap overflow).
//
// 'backslash' buffer in src/unescape.c:unescape is read past the bounds of the
// input buffer. This allows program logic to be influenced to trigger
// and out of bounds write on the heap.



static uint8_t bad_input[] = { ' ', ' ', '\\', '\r', '\n'};

static void harness(const uint8_t *data, size_t size, yp_unescape_type_t type) {
  yp_string_t *str = yp_string_alloc();
  assert(str);
  yp_list_t *error_list = malloc(sizeof(yp_list_t));
  assert(error_list);
  yp_list_init(error_list);
  yp_unescape_manipulate_string((const char *)data, size, str, type, error_list);
  yp_list_free(error_list);
  free(error_list);
  yp_string_free(str);
  free(str);
}


int main(int argc, const char **argv) {
  // input passed to harness is "  \\" but the trailing carriage return and line
  // feed are read
  harness(bad_input, sizeof(bad_input) - 2, YP_UNESCAPE_ALL);
  return 0;
}
