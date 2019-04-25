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
    int DTR_flag;
    DTR_flag = TIOCM_DTR;
    if (atoi(argv[2])) {
        ioctl(fd, TIOCMBIS, &DTR_flag);
    }
    else {
        ioctl(fd, TIOCMBIC, &DTR_flag);
    }
    close(fd);
}
