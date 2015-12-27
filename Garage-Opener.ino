// -----------------------------------------
// Function and Variable with Photoresistors
// -----------------------------------------
// In this example, we're going to register a Spark.variable() with the cloud so that we can read brightness levels from the photoresistor.
// We'll also register a Spark.function so that we can turn the LED on and off remotely.

// We're going to start by declaring which pins everything is plugged into.

int relay = D0; // This is where the relay is plugged in.
int openCount = 0;

// Next we go into the setup function.

void setup() {

    // First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.
    pinMode(relay,OUTPUT); // Our LED pin is output (lighting up the LED)

    // We are going to declare a Spark.variable() here so that we can access the value of the open count
    Spark.variable("openCount", &openCount, INT);

    // We are also going to declare a Spark.function so that we can open the Garage from the cloud
    Spark.function("openGarage",openGarage);

}

int openGarage(String sCommand) {
    digitalWrite(relay,HIGH);
    delay(500);
    digitalWrite(relay,LOW);
    return openCount++;
}


// Next is the loop function...

void loop() {

}
