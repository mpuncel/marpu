void
setup()
{
  Wire.setSpeed(5000000);
  Wire.begin();
}

#define MCP4725_DEVICE 96

/*int sintab[64] = {2147, 2347, 2545, 2737, 2922, 3100, 3267, 3422, 3564, 3692, 3803,
3898, 3975, 4033, 4072, 4092, 4092, 4072, 4033, 3975, 3898, 3803,
3692, 3564, 3422, 3267, 3100, 2922, 2737, 2545, 2347, 2147, 1947,
1747, 1549, 1357, 1172, 994, 827, 672, 530, 402, 291, 196, 119, 61,
22, 2, 2, 22, 61, 119, 196, 291, 402, 530, 672, 827, 994, 1172,
1357, 1549, 1747, 1947} ;*/

int sintab[4] = {0, 2000, 4000, 2000} ;

int sp = 0 ;

void
loop()
{
  Wire.beginTransmission(MCP4725_DEVICE);
  Wire.write(64);                     // cmd to update the DAC
  Wire.write(sintab[sp] >> 4);        // the 8 most significant bits...
  Wire.write((sintab[sp] & 15) << 4); // the 4 least significant bits...
  Wire.endTransmission();
  sp = (sp + 1) & 3 ;
}
