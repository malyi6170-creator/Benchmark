void setup() {
  Serial.begin(9600);
  Serial.println("=== ТЕСТ ПРОИЗВОДИТЕЛЬНОСТИ ARDUINO ===");
  runBenchmark();
}

void loop() {
  // Тест запускается раз в 5 секунд
  delay(5000);
  runBenchmark();
}

void runBenchmark() {
  Serial.println("Запуск тестов...");
  
  unsigned long startTime = micros();
  
  // Цикл с математическими расчетами (10 000 итераций)
  float val = 1.0;
  for (int i = 0; i < 10000; i++) {
    val = sin(val) * cos(val) * tan(val + 1.0);
  }
  
  unsigned long endTime = micros();
  unsigned long duration = endTime - startTime;

  Serial.print("10 000 тригонометрических операций заняли: ");
  Serial.print(duration);
  Serial.println(" микросекунд.");
  Serial.println("----------------------------------------");
}
