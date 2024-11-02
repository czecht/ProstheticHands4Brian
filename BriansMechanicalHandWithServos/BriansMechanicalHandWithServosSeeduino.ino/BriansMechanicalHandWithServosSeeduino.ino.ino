#include <Servo.h> // Include the Servo library

// Define Servo objects for each finger
Servo thumb;
Servo indexFinger;
Servo middleFinger;
Servo ringFinger;
Servo pinkyFinger;

// Define pin assignments for Seeeduino XIAO SAMD21
const int thumbPin = 0;         // Thumb servo on D0
const int indexFingerPin = 1;   // Index Finger servo on D1
const int middleFingerPin = 2;  // Middle Finger servo on D2
const int ringFingerPin = 3;    // Ring Finger servo on D3
const int pinkyFingerPin = 4;   // Pinky Finger servo on D4

// Define button pins
const int button1Pin = 5; // Button 1 on D5
const int button2Pin = 6; // Button 2 on D6
const int button3Pin = 7; // Button 3 on D7
const int button4Pin = 8; // Button 4 on D8
const int button5Pin = 9; // Button 5 on D9
const int button6Pin = 10; // Button 6 on D10

void setup() {
    Serial.begin(9600);
    Serial.println("Attaching fingers...");

    // Attach each finger to its respective pin
    thumb.attach(thumbPin);
    indexFinger.attach(indexFingerPin);
    middleFinger.attach(middleFingerPin);
    ringFinger.attach(ringFingerPin);
    pinkyFinger.attach(pinkyFingerPin);

    // Set up the buttons as inputs with pull-up resistors
    pinMode(button1Pin, INPUT_PULLUP);
    pinMode(button2Pin, INPUT_PULLUP);
    pinMode(button3Pin, INPUT_PULLUP);
    pinMode(button4Pin, INPUT_PULLUP);
    pinMode(button5Pin, INPUT_PULLUP);
    pinMode(button6Pin, INPUT_PULLUP);

    // Initialize all fingers to the closed position on startup
    thumb.write(180);       // Thumb starts closed at 180 degrees
    indexFinger.write(0);    // Index Finger starts closed
    middleFinger.write(0);   // Middle Finger starts closed
    ringFinger.write(0);     // Ring Finger starts closed
    pinkyFinger.write(0);    // Pinky Finger starts closed
    Serial.println("All fingers set to closed position on startup.");
}

void loop() {
    // Button 1: Exercise routine
    if (digitalRead(button1Pin) == LOW) { // Button 1 pressed
        Serial.println("Button 1 pressed: Starting exercise routine...");

        // Open each finger to its maximum position
        thumb.write(0);           // Open thumb to 0 degrees
        indexFinger.write(165);    // Open index finger to 165 degrees
        middleFinger.write(180);   // Open middle finger to 180 degrees
        ringFinger.write(180);     // Open ring finger to 180 degrees
        pinkyFinger.write(180);    // Open pinky finger to 180 degrees
        delay(1000); // Hold open for a moment

        // Close each finger back to its starting position
        thumb.write(180);          // Close thumb to 180 degrees
        indexFinger.write(0);      // Close index finger to 0 degrees
        middleFinger.write(0);     // Close middle finger to 0 degrees
        ringFinger.write(0);       // Close ring finger to 0 degrees
        pinkyFinger.write(0);      // Close pinky finger to 0 degrees
        delay(1000); // Hold closed for a moment

        Serial.println("Exercise routine complete. All fingers returned to closed position.");
    }

    // Button 2: Open all fingers
    if (digitalRead(button2Pin) == LOW) { // Button 2 pressed
        Serial.println("Button 2 pressed: Opening hand...");

        thumb.write(0);           // Open thumb
        indexFinger.write(165);    // Open index finger
        middleFinger.write(180);   // Open middle finger
        ringFinger.write(180);     // Open ring finger
        pinkyFinger.write(180);    // Open pinky finger

        delay(500); // Wait a moment after opening
    }

    // Button 3: Close all fingers
    if (digitalRead(button3Pin) == LOW) { // Button 3 pressed
        Serial.println("Button 3 pressed: Closing hand (making fist)...");

        thumb.write(180);           // Close thumb
        indexFinger.write(0);       // Close index finger
        middleFinger.write(0);      // Close middle finger
        ringFinger.write(0);        // Close ring finger
        pinkyFinger.write(0);       // Close pinky finger

        delay(500); // Wait a moment after closing
    }

    // Button 4: Show middle finger only
    if (digitalRead(button4Pin) == LOW) { // Button 4 pressed
        Serial.println("Button 4 pressed: Extending middle finger only...");

        thumb.write(180);           // Close thumb
        indexFinger.write(0);       // Close index finger
        middleFinger.write(180);    // Extend middle finger to 180 degrees
        ringFinger.write(0);        // Close ring finger
        pinkyFinger.write(0);       // Close pinky finger

        delay(500); // Hold the position with middle finger extended
    }

    // Button 5: Finger exercise show for 5 seconds
    if (digitalRead(button5Pin) == LOW) { // Button 5 pressed
        Serial.println("Button 5 pressed: Starting finger exercise show...");

        unsigned long startTime = millis();
        while (millis() - startTime < 5000) { // Run for 5 seconds
            // Open and close each finger in sequence
            thumb.write(0);           // Open thumb
            delay(200);
            thumb.write(180);         // Close thumb
            delay(200);

            indexFinger.write(165);    // Open index finger
            delay(200);
            indexFinger.write(0);      // Close index finger
            delay(200);

            middleFinger.write(180);   // Open middle finger
            delay(200);
            middleFinger.write(0);     // Close middle finger
            delay(200);

            ringFinger.write(180);     // Open ring finger
            delay(200);
            ringFinger.write(0);       // Close ring finger
            delay(200);

            pinkyFinger.write(180);    // Open pinky finger
            delay(200);
            pinkyFinger.write(0);      // Close pinky finger
            delay(200);
        }

        Serial.println("Finger exercise show complete.");
    }

    // Button 6: Wave gesture
    if (digitalRead(button6Pin) == LOW) { // Button 6 pressed
        Serial.println("Button 6 pressed: Starting wave gesture...");

        for (int i = 0; i < 3; i++) { // Repeat wave 3 times
            indexFinger.write(60);    // Partially open index finger
            delay(150);
            indexFinger.write(0);     // Close index finger
            delay(150);

            middleFinger.write(60);   // Partially open middle finger
            delay(150);
            middleFinger.write(0);    // Close middle finger
            delay(150);

            ringFinger.write(60);     // Partially open ring finger
            delay(150);
            ringFinger.write(0);      // Close ring finger
            delay(150);

            pinkyFinger.write(60);    // Partially open pinky finger
            delay(150);
            pinkyFinger.write(0);     // Close pinky finger
            delay(150);
        }

        Serial.println("Wave gesture complete.");
    }
}
