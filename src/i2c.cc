#include "../includes/i2c.h"

I2C_Dev::I2C_Dev (int address, int fnum) {
    // Get parameters
    devAddr = address;
    if (fnum < 0) {
        adapter = 1;
    } else {
        adapter = fnum;
    }
}

I2C_Dev::~I2C_Dev() {
    close(file);
}

int I2C_Dev::initialize () {
    // Open the i2c file
    snprintf(filename, 19, "/dev/i2c-%d", adapter);
    file = open(filename, O_RDWR);

    // If the file open fails, exit with cause
    if (file < 0) {
        return errno;
    }

    // Obtain bus access, or exit
    if (ioctl(file, devMode, devAddr) < 0) {
        return errno;
    }
}

int I2C_Dev::readReg (int regnum, char * output, int size) {
    char reg[1] = {regnum};

    // pick register
    write(file, reg, 1);

    // read register
    if (read(file, output, size) != size) {
        return -1;
    }

    return 0;
}

int I2C_Dev::writeReg (int register, char * input, int size) {
    // Not supported yet.
    return -1;
}
