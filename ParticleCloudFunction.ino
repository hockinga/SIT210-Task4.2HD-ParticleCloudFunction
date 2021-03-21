// Pin constants
const int GREEN_LED = D4;
const int ORANGE_LED = D3;
const int RED_LED = D2;

// Colour constants
const String GREEN = "green";
const String ORANGE = "orange";
const String RED = "red";
const String OFF = "off";


/**
 * Setup up the LED pins for output
 */
void setup()
{
    // Setup LEDs for output
    pinMode(GREEN_LED, OUTPUT);
    pinMode(ORANGE_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    // Expose to the cloud
    Particle.function("traffic", requestColor);

    // Make sure LEDs start off
    deactivate();
}


void loop()
{

}


/**
 * Requests a new traffic light color
 *
 * @param color the new traffic light color
 */
int requestColor(String color)
{
    if (color == RED) {
        setColor(RED_LED);
    } else if (color == ORANGE) {
        setColor(ORANGE_LED);
    } else if (color == GREEN) {
        setColor(GREEN_LED);
    } else {
        // Fail, handle invalid colors by turning the traffic lights off for safety
        deactivate();
        return -1;
    }

    // Success
    return 1;
}


/**
 * Turns off all colors in the traffic light
 */
void deactivate()
{
    digitalWrite(RED_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
}


/**
 * Sets the colors of the traffic light
 *
 * @param led the color that the traffic light is to be set to
 */
void setColor(int led)
{
    digitalWrite(RED_LED, RED_LED == led);
    digitalWrite(ORANGE_LED, ORANGE_LED == led);
    digitalWrite(GREEN_LED, GREEN_LED == led);
}