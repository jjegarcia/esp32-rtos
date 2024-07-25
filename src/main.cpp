#include <Arduino.h>

int c1 = 0;
int c2 = 0;

void task1(void *parameters)
{
  for (;;)
  {
    Serial.print("Task 1 Counter:");
    Serial.println(c1++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void task2(void *parameters)
{
  for (;;)
  {
    Serial.print("Task 2 Counter:");
    Serial.println(c2++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void setup()
{
  Serial.begin(115200);
  xTaskCreate(task1, "Task1", 1000, NULL, 1, NULL);
  xTaskCreate(task2, "Task2", 1000, NULL, 1, NULL);
}

void loop()
{
  // put your main code here, to run repeatedly:
}