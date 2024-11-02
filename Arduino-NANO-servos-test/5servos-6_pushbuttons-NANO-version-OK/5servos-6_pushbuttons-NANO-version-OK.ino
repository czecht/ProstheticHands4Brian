#include <Servo.h> // Standard Servo library

// Define Servo objects for each servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Attach each servo to a specific pin
const int servoPins[5] = {9, 8, 7, 6, 5};

void setup() {
    Serial.begin(9600);
    Serial.println("Attaching servos...");

    // Attach each servo to its respective pin
    servo1.attach(servoPins[0]);
    servo2.attach(servoPins[1]);
    servo3.attach(servoPins[2]);
    servo4.attach(servoPins[3]);
    servo5.attach(servoPins[4]);

    Serial.println("Servos attached to pins 9, 8, 7, 6, and 5.");
}

void loop() {
    // Move each servo from 0 to 180 degrees one by one
    for (int i = 0; i < 5; i++) {
        Serial.print("Moving Servo ");
        Serial.print(i + 1);
        Serial.println(" from 0 to 180 degrees...");
        for (int pos = 0; pos <= 180; pos += 5) { // Increment by 5 degrees for smoother motion
            switch (i) {
                case 0: servo1.write(pos); break;
                case 1: servo2.write(pos); break;
                case 2: servo3.write(pos); break;
                case 3: servo4.write(pos); break;
                case 4: servo5.write(pos); break;
            }
            delay(15); // Small delay for smoother movement
        }

        delay(500); // Pause at 180 degrees

        // Move each servo from 180 to 0 degrees one by one
        Serial.print("Moving Servo ");
        Serial.print(i + 1);
        Serial.println(" from 180 to 0 degrees...");
        for (int pos = 180; pos >= 0; pos -= 5) {
            switch (i) {
                case 0: servo1.write(pos); break;
                case 1: servo2.write(pos); break;
                case 2: servo3.write(pos); break;
                case 3: servo4.write(pos); break;
                case 4: servo5.write(pos); break;
            }
            delay(15); // Small delay for smoother movement
        }

        delay(500); // Pause at 0 degrees
    }
}
