#include <HID.h>
#include <Keyboard.h>

// 4x4 tuş matris pin tanımlamaları
const int RowPinMap[4] = {2, 3, 4, 5};   
const int ColPinMap[4] = {6, 7, 8, 9};   // Sütun pinleri

// Tek bir tuş haritası
const uint16_t keyMap[16] = {
    'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l',
    'm' ,'n', 'o', 'p',
};

int keyDown[16];    // Tuş durumlarını izler
const int debounceDelay = 50;    // Debounce gecikme süresi
unsigned long lastDebounceTime[16]; // Her tuş için son debounce zamanı

void setup() {
    Keyboard.begin();

    // Başlangıçta tüm tuşları serbest bırak
    for (int i = 0; i < 16; i++) {
        keyDown[i] = 0;
        lastDebounceTime[i] = 0;
    }

    // Satır ve sütun pinlerini ayarla
    for (int i = 0; i < 4; i++) {
        pinMode(RowPinMap[i], OUTPUT);
        digitalWrite(RowPinMap[i], HIGH); // Satırları başlangıçta yüksek yap
        pinMode(ColPinMap[i], INPUT_PULLUP); // Sütunları giriş olarak ayarla
    }
}

void loop() {
    for (int row = 0; row < 4; row++) {
        digitalWrite(RowPinMap[row], LOW);   // Satırı aktif et

        for (int col = 0; col < 4; col++) {
            int keyPosition = col + (row * 4);
            int inputKey = digitalRead(ColPinMap[col]);

            if ((millis() - lastDebounceTime[keyPosition]) > debounceDelay) {
                if (inputKey == LOW && keyDown[keyPosition] == 0) {
                    keyDown[keyPosition] = keyMap[keyPosition];
                    Keyboard.press(keyDown[keyPosition]);
                } else if (inputKey == HIGH && keyDown[keyPosition] != 0) {
                    Keyboard.release(keyDown[keyPosition]);
                    keyDown[keyPosition] = 0;
                }
                lastDebounceTime[keyPosition] = millis();
            }
        }

        digitalWrite(RowPinMap[row], HIGH);  // Satırı pasif et
        delay(1);  // Geçiş gecikmesi
    }
}
