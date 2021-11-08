/******************************************************************************

  WRITTEN BY: Ho Yun "Bobby" Chan
  @ SparkFun Electronics
  DATE: 10/19/2021
  GITHUB REPO: https://github.com/sparkfun/SparkFun_MicroMod_Main_Board_Double
  DEVELOPMENT ENVIRONMENT SPECIFICS:
    Firmware developed using Arduino IDE v1.8.12

  ========== DESCRIPTION==========
  This example code toggles the Function Board's AP2112 3.3V voltage
  regulator's enable pin. The Function Boards built-in power LED should blink.
   This example is based on Arduino's built-in Blink Example:

      https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink

  Note that this example code uses the MicroMod Main Board - Double. The MicroMod
  Main Board - Single routes the PWR_EN0 pin slightly different for the
  function board. 

  ========== HARDWARE CONNECTIONS ==========
  MicroMod Artemis Processor Board => MicroMod Main Board - Double => Function Boards

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
       MicroMod Artemis Processor Board - https://www.sparkfun.com/products/16401
       MicroMod Main Board - Double - https://www.sparkfun.com/products/18576
       MicroMod Environmental Function Board - https://www.sparkfun.com/products/18632

  LICENSE: This code is released under the MIT License (http://opensource.org/licenses/MIT)

******************************************************************************/

/*Define the power enable pins for the processor board with SDIO_DATA2.
  Depending on the processor board, the Arduino pin may be different. 

  Note: Certain Processor Boards like the Artemis have more than one pin available 
        to control the Function Board's voltage regulator (e.g. SDIO_DATA2 and G5).
        SAMD51, ESP32, and STM32 Processor Board pins do not have SDIO Data 2, so
        users will need to reference the Processor Pin G5. Below are a few examples. */
  
//ARTEMIS
#define PWR_EN0 4    //Function Board 0's "PWR_EN0" pin <= MicroMod SDIO_DATA2 => Artemis Processor Board (D4)  
#define PWR_EN1 26   //Function Board 1's "PWR_EN1" pin <= MicroMod SDIO_DATA1 => Artemis Processor Board (D26)

//Alternative option that does the same thing. Make sure to just choose one for PWR_EN0 and PWR_EN1
//#define PWR_EN0 29   //Function Board 0's "PWR_EN0" pin <= MicroMod G5 => Artemis Processor Board (A29)
//#define PWR_EN1 14   //Function Board 1's "PWR_EN0" pin <= MicroMod G6 => Artemis Processor Board (D14)


//TEENSY
//#define PWR_EN0 39   //Function Board 0's "PWR_EN0" pin <= MicroMod SDIO_DATA2 => Teensy Processor Board (D39)
//#define PWR_EN1 34   //Function Board 1's "PWR_EN1" pin <= MicroMod SDIO_DATA1 => Teensy Processor Board (D34)

//Alternative option that does the same thing. Make sure to just choose one for PWR_EN0 and PWR_EN1
//#define PWR_EN0 45   //Function Board 0's "PWR_EN0" pin <= MicroMod G5 => Teensy Processor Board (45)
//#define PWR_EN1 6   //Function Board 1's "PWR_EN1" pin <= MicroMod G6 => Teensy Processor Board (6)

//Note: The SAMD51, ESP32, and STM32 Processor Board Pins do not have SDIO Data 2 and SDIO Data 1.

//SAMD51
//#define PWR_EN0 7   //Function Board 0's "PWR_EN0" pin <= MicroMod G5 => SAMD51 Processor Board (D7)
//#define PWR_EN1 8   //Function Board 1's"PWR_EN1" pin <= MicroMod G6 => SAMD51 Processor Board (D8)

//ESP32
//#define PWR_EN0  32   //Function Board 0's "PWR_EN0" pin <= MicroMod G5 => ESP32 Processor Board (32)
//#define PWR_EN1  33   //Function Board 1's"PWR_EN1" pin <= MicroMod G6 => ESP32 Processor Board (33)



void setup() {
  // initialize the digital pins as an output.
  pinMode(PWR_EN0, OUTPUT); 
  pinMode(PWR_EN1, OUTPUT);

}



void loop() {

  digitalWrite(PWR_EN0, HIGH); // turn the 3.3V regulator on (HIGH is the voltage level)
  digitalWrite(PWR_EN1, HIGH); // turn the 3.3V regulator on (HIGH is the voltage level)
  delay(5000);                 // wait for a few seconds to do something with the function boards 
  
  digitalWrite(PWR_EN0, LOW);  // turn the 3.3V regulator off by making the voltage LOW
  digitalWrite(PWR_EN1, LOW);  // turn the 3.3V regulator off by making the voltage LOW
  delay(5000);                 // wait for a few seconds before turning function boards back on

}
