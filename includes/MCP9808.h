#include "../includes/i2c.h"
#include "../includes/sensor.h"

class MCP9808_Temp_Sensor: public Sensor {
    private:

        I2C_Dev * MCP9808;

    public:

    MCP9808_Temp_Sensor ();

    ~MCP9808_Temp_Sensor ();

    int initialize ();

    float getTemperatureC ();

    float getTemperatureF ();

}