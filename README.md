# Arduino Pro Micro 4x4 Keypad Matrix Keyboard Emulation

This project is designed for use with an Arduino Pro Micro and a 4x4 keypad matrix. The code enables the Arduino to read input from the keypad and emulate keyboard input, sending keystrokes to a connected computer based on the pressed keys.

## Components
- Arduino Pro Micro
- 4x4 Keypad Matrix
- Connectors and wires
  
## Connection Diagram
- Row pins and column pins are defined in the diagram. Make sure to connect the keypad matrix to these pins on the Arduino Pro Micro.
![11](https://github.com/user-attachments/assets/f851d687-fca5-45e9-a297-03320c17531e)

## Libraries
- `Keypad` library
- `Keyboard` library

## Code Functionality
- **Keypad Input**: The code reads the input from a 4x4 keypad matrix.
- **Keyboard Emulation**: Based on the pressed key, the Arduino sends corresponding keystrokes to the computer.
- **Keystroke Repetition**: When a key is held down, the code continuously sends the keystroke to the computer, emulating the behavior of a real keyboard.

## Usage
1. Upload the code to the Arduino Pro Micro.
2. Connect the 4x4 keypad matrix to the Arduino according to the pin configuration specified in the code.
3. The Arduino will act as a keyboard, sending keystrokes to the connected computer based on the keypad input.

## Example
If you press a key on the 4x4 keypad, the corresponding character will be sent to the connected computer as if it were typed on a keyboard.

For further details and customization, refer to the code comments and the documentation for the `Keypad` and `Keyboard` libraries.
