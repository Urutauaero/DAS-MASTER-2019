//I2C

#include <Wire.h>

#define addr_i2c_slave 8

void i2c_transmission_setup()
{
  Wire.begin(addr_i2c_slave);
  Wire.onRequest(I2C_packet);
}

void I2C_packet()
{
  Wire.write(rpsArray, 2);

  Wire.write(tempoArray, 4);
  
  Wire.write(wow);
  
  Wire.write(sonarPing);

  Wire.write(valor_graus1); Wire.write(valor_graus2); Wire.write(valor_graus3); Wire.write(valor_graus4);

  Wire.write(latArray, 4); Wire.write(longArray, 4); Wire.write(altArray, 2);

  /*Wire.write(diaArray, 2); Wire.write(mesArray, 2); Wire.write(anoArray, 2);
  
  Wire.write(horasArray, 2); Wire.write(minutosArray, 2); Wire.write(segundosArray, 2);
  */
}
