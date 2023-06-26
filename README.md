# Seven-Segment-Display-Keypad-Controller

This project involves the development of a software application that interfaces a keypad and a seven-segment display to display a number on the display when a button on the keypad is pressed. The implemented GPIO driver will be used to facilitate communication between the keypad and the seven-segment display.

## Project Structure
The project includes the following files:

* **Keypad.h:** Contains the declarations for the keypad manager APIs.
* **Keypad.c:** Contains the implementations for the keypad driver APIs.
* **Main.c:** Contains the implementation of the required application.

## Functions .
**Keypad_init function:**
  * Will be used to initialize the internal keypad driver variable(s).
**Keypad_manage function:**
  * called periodically from the infinite loop in the main function.
  * scan all keys to check which one is pressed.
  * Once a valid key press is detected, the function shall perform the following actions:
      * Store the pressed key value.
      * Call the function "KeypadCallouts_KeyPressNotification" without passing any arguments.
  * Only a transition from no key pressed to one key press shall be considered a valid press.
  * After a key press, the stored key value shall not change until the key is released.
  * The stored key value shall not change until the key is released and the Keypad_GetKey function is called.
  * The function shall use a lookup table implementation to determine the value of the pressed key.
    
**Keypad_GetKey function:**
  * Shall be called by the application to retrieve the last stored key value.
