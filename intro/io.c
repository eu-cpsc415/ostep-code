#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // Open a file for writing (create if it doesn't exist, truncate if it does)
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0);

    // Write a string to a buffer in memory
    char buffer[20];
    sprintf(buffer, "hello world\n");

    // Write the string from the buffer to the file
    int rc = write(fd, buffer, strlen(buffer));
    assert(rc == (strlen(buffer)));

    // Ensure write is flushed to disk and close the file
    fsync(fd);
    close(fd);
    return 0;
}
