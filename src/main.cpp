#include <Arduino.h>

int c1 = 0;
int c2 = 0;

TaskHandle_t task1_handle = NULL;
TaskHandle_t task2_handle = NULL;

void task1(void *parameters)
{
  for (;;)
  {
    Serial.print("Task 1 Counter1:");
    Serial.println(c1++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void task2(void *parameters)
{
  for (;;)
  {
    Serial.print("Task 2 Counter2:");
    Serial.println(c2++);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
void setup()
{
  Serial.begin(115200);
  xTaskCreate(task1, "Task1", 1000, NULL, 1, &task1_handle);
  xTaskCreate(task2, "Task2", 1000, NULL, 2, &task2_handle);
}

void loop()
{
  if (c1 > 3 && task1_handle != NULL)
  {
    // Serial.print("KK");
    vTaskSuspend(task1_handle);
  }
  
}