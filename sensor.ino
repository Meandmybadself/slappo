int frame = 0;
int sampleRate = 20;

int prevValue = 2210;
int threshold = 375;

void loop() {
    if ((frame++ % sampleRate) == 0) {
        int value = analogRead(A0);
        int diff = value - prevValue;
        if (diff > threshold) {
            Spark.publish("slap");
        }
        prevValue = value;
    }
}