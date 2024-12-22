from cffi import FFI

ffibuilder = FFI()
ffibuilder.cdef("int sum64(const long long* data);")
ffibuilder.cdef("int sum64_32(const int* data);")
ffibuilder.cdef("int sum32(const int* data);")
ffibuilder.cdef("int sum256_32(const int* data);")
ffibuilder.cdef("int sum1x128_32(const int* data);")
ffibuilder.cdef("int sum4x128_32(const int* data);")
ffibuilder.cdef("int naive_sum(const int* data, const int n);")

ffibuilder.set_source(
    "_fastmath",
    """
    #include "arithmetic.h"
""",
    sources=["arithmetic.c"],
)

if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
