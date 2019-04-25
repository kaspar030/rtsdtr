#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd;

    if (argc < 3) {
        return -1;
    }

    fd = open(argv[1], O_RDWR | O_NOCTTY );
    int RTS_flag;
    RTS_flag = TIOCM_RTS;
    if (atoi(argv[2])) {
        ioctl(fd, TIOCMBIS, &RTS_flag);
    }
    else {
        ioctl(fd, TIOCMBIC, &RTS_flag);
    }
    close(fd);
}
