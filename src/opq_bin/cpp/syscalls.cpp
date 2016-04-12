#include <config.h>
#include <uart.h>

#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern "C" {
    // _sbrk in heap.cpp
    
    void abort(void) {
        while(true);
    }

    void exit(int status) {
        while(true);
    }

    auto _write( int fd, const void *buf, size_t size ) -> size_t {
        for( auto i = 0u; i < size; i++ ) {
            while(!io_uart::tx_empty());                    // wait until txe
            io_uart::transmit(((std::uint8_t *)buf)[i]);    // shift out byte
        }

        return size;
    }

    auto _close(int) -> int {
        return 0;
    }

    auto _read( int fd, const void *buf, size_t size ) -> size_t {
        return 0;
    }

    auto _isatty(int) -> int {
        return 0;
    }

    auto _lseek(int fd, off_t offset, int whence) -> off_t {
        return -1;
    }

    auto _fstat(int fd, struct stat *buf) -> int {
        return -1;
    }
}
