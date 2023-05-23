//PROGRAMA APENAS PARA DEBUGGING

#define print_period 100

void print_loop() {
  
  if (millis() - print_temp_aux >= print_period)
  {
    print_temp_aux = millis();

    Serial.print(F("RPM: "));        Serial.print(rpm, 1);    Serial.print(F(", \t"));

    Serial.print(F("WOW: "));        Serial.print(wow, 1);    Serial.print(F(", \t"));

    Serial.print(F("DIST: "));       Serial.print(sonarPing); Serial.print(F(", \t"));

    Serial.print(F("Aileron: "));    Serial.print(valor_graus1); Serial.print(F(", \t"));

    Serial.print(F("Profundor: "));  Serial.print(valor_graus2); Serial.print(F(",  \t"));

    Serial.print(F("Leme: "));       Serial.print(valor_graus3); Serial.print(F(", \t"));

    Serial.print(F("Flap: "));       Serial.print(valor_graus4); Serial.print(F(", \t"));
        
    Serial.print(F("Lat: "));        Serial.print(latfloat, 6); Serial.print(F("\t"));

    Serial.print(F("Long: "));       Serial.print(longfloat, 6); Serial.print(F("\t"));

    Serial.print(F("Alt: "));        Serial.print(altfloat, 2); Serial.print(F("\t"));

    Serial.print(F("Data: "));       Serial.print(dia); Serial.print("/"); Serial.print(mes); Serial.print("/"); Serial.print(ano); Serial.print(F("\t"));

    Serial.print(F("Hora: "));       Serial.print(hora); Serial.print(":"); Serial.print(minuto); Serial.print(":"); Serial.print(segundo); Serial.print(F("\t"));

    Serial.print(F("Tempo: "));      Serial.print(tempo);

    Serial.println();
  }
  
}
