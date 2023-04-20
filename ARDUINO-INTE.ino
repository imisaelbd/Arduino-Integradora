#include <ezButton.h>

#define btn_1 2
#define btn_2 3
#define btn_3 4
#define btn_4 5


ezButton button1(btn_1);
ezButton button2(btn_2);
ezButton button3(btn_3);
ezButton button4(btn_4);

void setup() {
  Serial.begin(9600);
  button1.setDebounceTime(50);
  button2.setDebounceTime(50);
  button3.setDebounceTime(50);
  button4.setDebounceTime(50);
}

void loop() {
  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();

  if (button1.isPressed()) {
    Serial.println("1");
  }

  if (button2.isPressed()) {
    Serial.println("2");
  }

  if (button3.isPressed()) {
    Serial.println("3");
  }

  if (button4.isPressed()) {
    Serial.println("4");
  }
}