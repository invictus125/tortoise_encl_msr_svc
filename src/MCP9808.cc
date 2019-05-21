#include "../includes/MCP9808.h"

MCP9808_Temp_Sensor::MCP9808_Temp_Sensor () {
    I2C_Dev dev(0x18, 1)
    MCP9808 = &dev;
}

MCP9808_Temp_Sensor::~MCP9808_Temp_Sensor () {
    ~MCP9808();
}

MCP9808_Temp_Sensor::initialize() {
    return MCP9808->initialize();
}

float MCP9808_Temp_Sensor::getTemperatureC () {
    // vars
    char buf[2] = {0};
    int rawTemp = 0;

    // Read the register
    if (MCP9808->readReg(0x05, &buf, 2) < 0) {
        // ERROR
        return 99999;
    } else {
        // Process the output values.
        rawTemp = ((buf[0] & 0x1F) * 256 + data[1]);
        if (rawTemp > 4095) {
            rawTemp -= 8192;
        }
        reading = rawTemp * 0.0625
        return reading;
    }
}

float MCP9808_Temp_Sensor::getTemperatureF () {
    float cTemp = getTemperatureC();
    if (cTemp < 99999) {
        // no error
        cTemp = cTemp * 1.8 + 32;
    }
    return cTemp;
}