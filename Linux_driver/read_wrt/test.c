#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;
    char write_buf[] = "Hi from user space!";
    char read_buf[64] = {0};

    fd = open("/dev/hello0", O_RDWR);
    if (fd < 0) {
        perror("open");
        return fd;
    }

    write(fd, write_buf, strlen(write_buf));

    lseek(fd, 0, SEEK_SET);  

    ssize_t bytes = read(fd, read_buf, sizeof(read_buf));
	if (bytes < 0) {
    perror("read");
    close(fd);
    return 1;
	}
	read_buf[bytes] = '\0';  // Null-terminate
	printf("Read from device: %s\n", read_buf);


    close(fd);
    return 0;
}
