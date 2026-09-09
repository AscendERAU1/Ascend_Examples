// GUVA-S12SD UV module

const int UV_PIN = A0;     
const float ADC_REF = 5.0;
const int ADC_RES = 1023;



void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(UV_PIN);
  float voltage = raw * (ADC_REF / ADC_RES);
  float uvIndex = mapVoltageToUVIndex(voltage);

  Serial.print("Raw: "); Serial.print(raw);
  Serial.print("  Voltage: "); Serial.print(voltage, 3);
  Serial.print("V  UV Index: "); Serial.println(uvIndex, 1);

  delay(1000);
}

// Standard GUVA-S12SD voltage -> UV Index lookup, linearly interpolated
float mapVoltageToUVIndex(float v) {
  float voltageTable[] = {0.99, 1.15, 1.36, 1.67, 1.83, 2.10, 2.27, 2.51, 2.78, 3.02, 3.20};
  int index = 0;
  for (int i = 0; i < 10; i++) {
    if (v >= voltageTable[i]) index = i;
  }
  if (v < voltageTable[0]) return 0.0;
  if (v >= voltageTable[10]) return 11.0;
  float uvIndex = index + (v - voltageTable[index]) / (voltageTable[index + 1] - voltageTable[index]);
  return uvIndex;
}