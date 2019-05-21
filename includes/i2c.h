#ifndef I2C_DEV_H
#define I2C_DEV_H

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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
    I2C_Dev (int address, int fnum);

    ~I2C_Dev();

    initialize ();

    int readReg (int register, char * output, int size);

    int writeReg (int register, char * input, int size);

};

#endif
