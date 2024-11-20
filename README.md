Aurora Gesture Lamp 
Aurora Gesture Lamp is an interactive LED lamp that responds to your hand gestures. It uses a gesture sensor to detect movements and changes the color of an RGB LED strip accordingly. Perfect for a stylish and futuristic lighting solution!

Features
Gesture Control: Change colors with simple hand gestures (up, down, left, right).
Dynamic Colors: Adjust the brightness and hue of the lamp in real-time.
Reset Option: Instantly reset to default colors with a gesture.
Compact and Customizable: Designed for easy assembly and endless creativity.
Components
Arduino Uno
Gesture Sensor (APDS-9960 recommended)
RGB LED strip or RGB LED module
Breadboard and jumper wires
Resistors (if using individual LEDs)
How It Works
Up Gesture: Increases the intensity of the red component.
Down Gesture: Increases the intensity of the green component.
Left Gesture: Increases the intensity of the blue component.
Right Gesture: Resets the colors to the default state.
The gesture sensor (APDS-9960) detects hand movements and sends signals to the Arduino. The Arduino adjusts the RGB values, and the changes are displayed on the LED strip.

Circuit Diagram
Connect the gesture sensor to the Arduino:
VIN → 5V
GND → GND
SCL → A5 (I2C Clock)
SDA → A4 (I2C Data)
Connect the RGB LED pins:
Red Pin → PWM Pin 9
Green Pin → PWM Pin 10
Blue Pin → PWM Pin 11
Installation
Clone the repository or copy the code provided.
Install the required library for the APDS-9960 gesture sensor:
Go to Tools > Manage Libraries in the Arduino IDE.
Search for Adafruit APDS9960 and install it.
Upload the code to your Arduino Uno.
Usage
Power the Arduino.
Wave your hand over the gesture sensor to see the color changes.
Experiment with gestures to create dynamic lighting effects!
Future Enhancements
Add brightness control with a "hover" gesture.
Integrate with a smartphone app for remote control.
Create custom animations or light patterns.
