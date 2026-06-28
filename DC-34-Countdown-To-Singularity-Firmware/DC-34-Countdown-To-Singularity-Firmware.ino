#include <RTClib.h>
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
RTC_PCF8563 rtc;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5, 14, 15};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);

  rtc.begin();

  if (rtc.lostPower()) {
    Serial.println("RTC is NOT initialized, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    //
    // Note: allow 2 seconds after inserting battery or applying external power
    // without battery before calling adjust(). This gives the PCF8523's
    // crystal oscillator time to stabilize. If you call adjust() very quickly
    // after the RTC is powered, lostPower() may still return true.
  }
  rtc.start();

  // Calculations for timer 1 with period 2000ms
  // 2000ms corresponds to a CTC frequency of 0.5 Hz
  // For prescaler 1024, OCR1A = 16000000/(2*1024*4.0) - 1 = 390
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B = bit(CS12) | bit(CS10);             // Set prescalar of timer 1 to 1024  
  TIMSK1 = bit(OCIE1A);                       // Enable compare match A on timer 1
  OCR1A = 390;
  sei();  // Enable back the interrupts
}

// This ISR refreshes the display
ISR(TIMER1_COMPA_vect) {
  TCNT1 = 0;  // Reset the counter
  sevseg.refreshDisplay(); // Must run repeatedly
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  DateTime now = rtc.now();
  // calculate a date which is 7 days, 12 hours and 30 seconds into the future
  DateTime future (now + TimeSpan(7,12,30,6));
  
  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; // 100 milliSeconds is equal to 1 deciSecond
    
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }
}
