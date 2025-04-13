#include <Servo.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16x2 LCD
Servo myservo_enter;
Servo myservo_back;

// IR sensor pins
#define ir_enter 2
#define ir_back  4
#define ir_car1 5
#define ir_car2 6
#define ir_car3 7
#define ir_car4 8
#define ir_car5 9
#define ir_car6 10

int S1=0, S2=0, S3=0, S4=0, S5=0, S6=0;
//int flag1=0, flag2=0; 
int slot = 6;  

void setup() {
    Serial.begin(9600);  
    
    pinMode(ir_car1, INPUT);
    pinMode(ir_car2, INPUT);
    pinMode(ir_car3, INPUT);
    pinMode(ir_car4, INPUT);
    pinMode(ir_car5, INPUT);
    pinMode(ir_car6, INPUT);
    pinMode(ir_enter, INPUT);
    pinMode(ir_back, INPUT);
  
    myservo_enter.attach(3);
    delay(10);
    myservo_back.attach(11);
    delay(10);
    myservo_enter.attach(3);
    delay(10);
    myservo_back.attach(11);
    delay(10);
    myservo_enter.write(0);
    myservo_back.attach(0);
    
    lcd.init();        
    lcd.backlight();   
    
    lcd.setCursor(0, 0);
    lcd.print("  Car Parking ");
    Serial.println("Car Parking System");  
    
    lcd.setCursor(0, 1);
    lcd.print("    System    ");
    Serial.println("System");
    
    delay(2000);
    lcd.clear();   

    Read_Sensor();
    slot = 6 - (S1 + S2 + S3 + S4 + S5 + S6); 
}

void loop() {
    Read_Sensor();
    myservo_back.attach(11);

    // Update available slots count
    slot = 6 - (S1 + S2 + S3 + S4 + S5 + S6);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    
    Serial.print("Available Slots: ");
    if (slot > 0) {
        lcd.print("Slots: ");
        lcd.print(slot);
        Serial.println(slot);
    } else {
        lcd.print("Parking Full");
        Serial.println("Full");
    }

    // Display S1, S2, S3 on LCD and Serial Monitor
    lcd.setCursor(0, 1);
    Serial.print("S1: ");
    lcd.print("S1:");
    lcd.print(S1 ? "F " : "E ");
    Serial.print(S1 ? "F " : "E ");

    lcd.print("S2:");
    Serial.print(" S2: ");
    lcd.print(S2 ? "F " : "E ");
    Serial.print(S2 ? "F " : "E ");

    lcd.print("S3:");
    Serial.print(" S3: ");
    lcd.print(S3 ? "F " : "E ");
    Serial.println(S3 ? "F " : "E ");

    delay(1000);

    // Display S4, S5, S6 on LCD and Serial Monitor
    lcd.clear();
    lcd.setCursor(0, 0);
    Serial.print("S4: ");
    lcd.print("S4:");
    lcd.print(S4 ? "F " : "E ");
    Serial.print(S4 ? "F " : "E ");

    lcd.print("S5:");
    Serial.print(" S5: ");
    lcd.print(S5 ? "F " : "E ");
    Serial.print(S5 ? "F " : "E ");

    lcd.print("S6:");
    Serial.print(" S6: ");
    lcd.print(S6 ? "F " : "E ");
    Serial.println(S6 ? "F " : "E ");

    delay(1000);

    // Entry/Exit Mechanism
  /*  if (digitalRead(ir_enter) == 0 && flag1 == 0) {
        if (slot > 0) {
            flag1 = 1;
            if (flag2 == 0) {
                myservo.write(180);
                slot = slot - 1;
            }
        } else {
            lcd.setCursor(0, 0);
            lcd.print(" Parking Full ");
            Serial.println("Parking Full");
            delay(1500);
        }   
    }

    if (digitalRead(ir_back) == 0 && flag2 == 0) {
        flag2 = 1;
        if (flag1 == 0) {
            myservo.write(180);
            slot = slot + 1;
        }
    }

    if (flag1 == 1 && flag2 == 1) {
        delay(1000);
        myservo.write(90);
        flag1 = 0;
        flag2 = 0;
    }

    delay(500);  // Reduce CPU load
}*/
if(slot>0){
if(digitalRead(ir_enter) == 0 ){
  myservo_enter.write(0);

}
else{
  myservo_enter.write(90);
  
}
if(digitalRead(ir_back) == 0){
   myservo_back.write(0);
}
else{
  myservo_back.write(90);
}

delay(500);
//myservo.write(0);

if (slot==0){
  lcd.setCursor(0, 0);
  lcd.println("Parking");
  lcd.setCursor(0, 1);
  lcd.print("Full Full");
  Serial.print(" Parking Full ");
  //lcd.print(" Parking Full ");
}
}}
void Read_Sensor() {
    S1 = digitalRead(ir_car1) == 0 ? 1 : 0;
    S2 = digitalRead(ir_car2) == 0 ? 1 : 0;
    S3 = digitalRead(ir_car3) == 0 ? 1 : 0;
    S4 = digitalRead(ir_car4) == 0 ? 1 : 0;
    S5 = digitalRead(ir_car5) == 0 ? 1 : 0;
    S6 = digitalRead(ir_car6) == 0 ? 1 : 0;
}
