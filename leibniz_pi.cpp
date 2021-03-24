// Happy Pi day (March 14th) - too shame the year isn't 1592
// Calculating Pi using Leibniz's formula
// https://en.wikipedia.org/wiki/Leibniz_formula_for_π
// Yuval Kedar - KD Technology
// www.kdtech.co.il

#include <Arduino.h>

#define SERIAL_BAUDRATE	115200
#define PI				3.14159265359
#define FACTOR			1	// to see more clearly on the Serial Plotter
#define REFRESH_MS		10

float pi = 4;	// because in Leibniz's formula the series converges to Pi/4, so it's like saying 4 - 4/3 + 4/5 - 4/7 ... = Pi
uint32_t iterations = 0;

void setup()
{
	Serial.begin(SERIAL_BAUDRATE);
}

void loop()
{
	float denominator = iterations * 2 + 3; // becaue we start at 3, then 5, then 7, etc...
	
	if (iterations % 2 == 0) {	// even denominator
		pi -= (4 / denominator);
	} else {	// odd denominator
		pi += (4 / denominator);
	}

	Serial.print(pi * FACTOR, 10);
	Serial.print(" ~= ");
	Serial.println(PI * FACTOR, 10);
	delay(REFRESH_MS);
	iterations++;
}
