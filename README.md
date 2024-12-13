Here's a draft for the **Auto Fan Speed Temperature Controller with ATmega32 MCU** README. Let me know if any adjustments are needed:

---

# 🌡️ Auto Fan Speed Temperature Controller

**An automatic fan speed controller project using the AVR ATmega32 microcontroller.**

---

## 📃 Project Overview

This project implements an automatic fan speed controller based on temperature readings. Using an LM35 temperature sensor and PWM (Pulse Width Modulation) with the ATmega32 microcontroller, the system adjusts the fan speed dynamically to maintain optimal cooling.

---

## 📂 Project Structure

Here's an overview of the project structure and key files:

```
Auto-Fan-Speed-Temperature-Controller
├── .vs
│   ├── Fan Speed Controller
│   │   ├── v14
│   │   │   └── .atsuo
├── Fan Speed Controller
│   ├── Debug
│   │   └── Fan Speed Controller.elf
│   │   └── Fan Speed Controller.hex
│   │   └── Fan Speed Controller.lss
│   │   └── Fan Speed Controller.map
│   │   └── Fan Speed Controller.srec
│   │   └── Makefile
│   ├── HAL
│   │   ├── Button Driver
│   │   │   └── Butto_progaram.c
│   │   │   └── Button_Config.h
│   │   │   └── Button_Interface.h
│   │   │   └── Button_Private.h
│   │   ├── Keypad Driver
│   │   │   └── Keypad_Config.h
│   │   │   └── Keypad_Private.h
│   │   │   └── Keypad_Program.c
│   │   │   └── Keypad_interface.h
│   │   │   └── Types.h
│   │   ├── LCD Driver
│   │   │   └── CLCD_config.h
│   │   │   └── CLCD_extrachar.h
│   │   │   └── CLCD_interface.h
│   │   │   └── CLCD_private.h
│   │   │   └── CLCD_program.c
│   │   │   └── lcd_extrachar.txt
│   │   ├── LED Driver
│   │   │   └── LED.c
│   │   │   └── LED.h
│   │   ├── LM35 Driver
│   │   │   └── LM35_Config.h
│   │   │   └── LM35_Interface.h
│   │   │   └── LM35_Private.h
│   │   │   └── LM35_Program.c
│   ├── LIB
│   │   └── BIT_OPERATIONS.h
│   │   └── Types.h
│   │   └── register.h
│   ├── MCAL
│   │   ├── ADC Driver
│   │   │   └── ADC_Config.h
│   │   │   └── ADC_Interface.h
│   │   │   └── ADC_Private.h
│   │   │   └── ADC_Program.c
│   │   │   └── BIT_OPERATIONS.h
│   │   │   └── Types.h
│   │   ├── DIO Driver
│   │   │   └── BIT_OPERATIONS.h
│   │   │   └── DIO_Config.h
│   │   │   └── DIO_Interface.h
│   │   │   └── DIO_Private.h
│   │   │   └── DIO_Program.c
│   │   │   └── Types.h
│   │   ├── EEPROM Driver
│   │   │   └── EEPROM.c
│   │   │   └── EEPROM.h
│   │   ├── EX_INT Driver
│   │   │   └── EX_INTERRUPT_Config.h
│   │   │   └── EX_INTERRUPT_Interface.h
│   │   │   └── EX_INTERRUPT_Private.h
│   │   │   └── EX_INTERRUPT_Progrm.c
│   │   ├── PORT Driver
│   │   │   └── PORT_config.h
│   │   │   └── PORT_interface.h
│   │   │   └── PORT_private.h
│   │   │   └── PORT_program.c
│   │   │   └── Types.h
│   │   ├── Timers
│   │   │   └── Timers_Config.h
│   │   │   └── Timers_Interface.h
│   │   │   └── Timers_Private.h
│   │   │   └── Timers_Program.c
│   │   └── Timers.c
│   │   └── Timers.h
│   └── Fan Speed Controller.componentinfo.xml
│   └── Fan Speed Controller.cproj
│   └── main.c
└── Fan Speed Controller.atsln
└── LICENSE
└── README.md
```

---

## 📝 Key Features

- **🌡️ Temperature Sensing:** Uses the LM35 sensor to read ambient temperature.
- **🌀 Automatic Fan Control:** Adjusts fan speed based on temperature readings.
- **📟 LCD Display:** Real-time display of temperature and fan speed.
- **⚡ PWM Control:** Fan speed modulation via PWM signals from the ATmega32.
- **🔧 Modular Design:** Separate modules for ADC, PWM, and LCD for easier maintenance.

---

## 🛠️ Dependencies

- **Development IDE:** [Atmel Studio](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio) or [AVR-GCC](https://www.microchip.com/en-us/development-tools-tools-and-software/gcc-compilers) for compiling.
- **Programmer:** USBasp, AVRISP, or any compatible ISP programmer.
- **Components:**
  - LM35 Temperature Sensor
  - 16x2 LCD Display
  - DC Fan (12V)
  - Transistor for fan control (e.g., TIP122 or similar)

---

## 🚀 Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Abdelrhman-Ellithy/Auto-Fan-Speed-Temperature-Controller.git
   ```

2. **Compile the Project:**
   - If using AVR-GCC:
     ```bash
     make
     ```

3. **Flash the HEX File:**
   - Use `avrdude` with USBasp:
     ```bash
     avrdude -c usbasp -p m32 -U flash:w:AutoFanController.hex
     ```

4. **Connect the Circuit:**
   - Connect the LM35, fan, and LCD as per the schematics.

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

---

## 💬 Contact

- **Author:** Abdelrhman Ellithy  
