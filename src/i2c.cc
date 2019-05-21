#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

class I2C_Dev {

private:

int devAddr = -1;
int devMode = I2C_SLAVE;
int adapter = -1;
char filename[20];
int file = -1;

public:

/**
 * Constructor which takes the following parameters:
 * 
 * address - The address for the device
 * fnum - The number of the i2c file
 */
I2C_Dev (int address, int fnum) {
    // Get parameters
    devAddr = address;
    if (fnum < 0) {
        adapter = 1;
    } else {
        adapter = fnum;
    }

    // Open the i2c file
    snprintf(filename, 19, "/dev/i2c-%d", adapter);
    file = open(filename, O_RDWR);

    // If the file open fails, exit with cause
    if (file < 0) {
        exit(1);
    }
}

~I2C_Dev() {
    close(file);
}

read (byte * output, int size) {

}

write (byte * input, int size) {

}

};
