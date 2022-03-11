// To count loops.
int frame = 0;

// To use every nth frame.
int sampleRate = 20;

// Bend variables
// This is what no bend equals.
int prevValue = 2210;
// Only register a slap if the bend has increased by this much since the last check.
int bendThreshold = 250;
// We don't want slaps going off too closely together.
int prevFrame = 0;
// Minimum number of frames that had to have passed since the last slap.
int frameThreshold = 500;
void loop() {
    if ((frame++ % sampleRate) == 0) {
        // Read value from bend sensor.
        int value = analogRead(A0);
        
        // The difference in bend between now & the previous check.
        int bendDiff = value - prevValue;
        
        // The difference in frames 
        int frameDiff = frame - prevFrame;
        if (bendDiff > bendThreshold && frameDiff > frameThreshold) {
            Spark.publish("slap", String(frame) + "-" + String(prevFrame) + "=" + String(frameDiff));
            prevFrame = frame;
        }
        prevValue = value;
    }
}
