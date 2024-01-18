#include <LiquidCrystal.h>

// Mygtukai
#define BUTTON_UP 4
#define BUTTON_CENTER 5
#define BUTTON_DOWN 6

// Valdomi elementai
#define LED_1 2
#define LED_2 3

// Meniu punktai ir jų pavadinimai
const int menuItemsCount = 8;
const char *menuItems[] = {"ijungti 1", "isjungti 1", "ijungti 2", "isjungti 2", "menu 5", "menu 6", "menu 7", "menu 8"};

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int selectedMenuItem = 0;
int menuIndex = 0;
void setup() {
  lcd.begin(16, 2);

  pinMode(BUTTON_UP, INPUT);
  pinMode(BUTTON_CENTER, INPUT);
  pinMode(BUTTON_DOWN, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  printMenu();
}

void loop() {
  lcd.setCursor(0, 0);
  if (digitalRead(BUTTON_UP) == HIGH) {
    delay(300);
 
    if (selectedMenuItem > 0) {
      selectedMenuItem--;
    } else {
      selectedMenuItem = menuItemsCount - 1;
    }
    printMenu();
  }

  if (digitalRead(BUTTON_DOWN) == HIGH) {
    delay(300);
    if (selectedMenuItem < menuItemsCount - 1) {
      selectedMenuItem++;
    } else {
      selectedMenuItem = 0;
    }
    printMenu();
  }

  if (digitalRead(BUTTON_CENTER) == HIGH) {
    
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(menuItems[selectedMenuItem]);
    lcd.setCursor(0, 1);
    lcd.print("Selected");
    performAction(selectedMenuItem);
    delay(1000); 
    lcd.clear();
    lcd.setCursor(0, 0);
    printMenu();
  }
}

void performAction(int menuItemIndex) {
  // Realizuoti veiksmus atitinkamai meniu punktui
  switch (menuItemIndex) {
    case 0:
      digitalWrite(LED_1, HIGH);
      break;
    case 1:
      digitalWrite(LED_1, LOW);
      break;
          case 2:
      digitalWrite(LED_2, HIGH);
      break;
          case 3:
      digitalWrite(LED_2, LOW);
      break;
          case 4:
          lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Coming");
          lcd.setCursor(6, 1);
          lcd.print("Soon");
          delay(1000);
          printMenu();
      break;
          case 5:
                lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Coming");
          lcd.setCursor(6, 1);
          lcd.print("Soon");
          delay(1000);
          printMenu();
      break;
          case 6:
                lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Coming");
          lcd.setCursor(6, 1);
          lcd.print("Soon");
          delay(1000);
          printMenu();
      break;
          case 7:
                lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Coming");
          lcd.setCursor(6, 1);
          lcd.print("Soon");
          delay(1000);
          printMenu();
      break;
  }
}

void toggleLED(int ledPin) {
  if (digitalRead(ledPin) == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
void printMenu() {
    lcd.clear();
    if (selectedMenuItem == 0){
    lcd.setCursor(0, 0);
    lcd.print(">");
    lcd.print(menuItems[selectedMenuItem]);

    lcd.setCursor(0, 1);
    lcd.print(" ");
    lcd.print(menuItems[selectedMenuItem+1]);
    }
    else if (selectedMenuItem > 0 && selectedMenuItem <8){
    lcd.setCursor(0, 0);
    lcd.print(" ");
    lcd.print(menuItems[selectedMenuItem-1]);

    lcd.setCursor(0, 1);
    lcd.print(">");
    lcd.print(menuItems[selectedMenuItem]);
    }

}

