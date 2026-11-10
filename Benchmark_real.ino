void setup() {
  Serial.begin(9600);
  while (!Serial); // Ожидание открытия порта (для плат с нативным USB, для Nano просто подстраховка)
  
  Serial.println("=== ТЕСТ ПРОИЗВОДИТЕЛЬНОСТИ ARDUINO ===");
  runBenchmark();
}

void loop() {
  // Тест запускается автоматически каждые 5 секунд
  delay(5000);
  runBenchmark();
}

void runBenchmark() {
  Serial.println("Запуск честных тестов...");
  
  unsigned long startTime = micros();
  
  // Подмешиваем шум с незадействованного пина A0 и используем volatile,
  // чтобы компилятор не стер цикл оптимизацией.
  volatile float val = analogRead(A0); 
  
  for (int i = 0; i < 10000; i++) {
    val = sin(val) * cos(val) * 1.0001;
  }
  
  unsigned long endTime = micros();
  unsigned long duration = endTime - startTime;

  // Выводим финальное значение, чтобы результат реально использовался
  Serial.print("Итоговое значение (для защиты от оптимизатора): ");
  Serial.println(val);
  
  Serial.print("10 000 честных тригонометрических операций заняли: ");
  Serial.print(duration);
  Serial.println(" микросекунд.");
  Serial.println("----------------------------------------");
}
