## Bluetooth ALDL Adapter <img alt="" align="right" src="https://img.shields.io/badge/IDE-Visual%20Studio-informational?style=flat&logo=Visual%20Studio&logoColor=white&color=5C2D91" /> <img alt="" align="right" src="https://img.shields.io/badge/Platform-ESP32-informational?style=flat&logo=Arduino&logoColor=white&color=00979D" />

### **Project**: ALDL to Bluetooth Adapter using a Mini Computing Board <img alt="" align="right" src="https://img.shields.io/badge/Status-Proof%20of%20Concept-informational?style=flat&logoColor=white&color=00ADD8" />


<!-- Repo Cover Image -->
<p align="center">
<img alt="" align="center" src="https://github.com/CrashOverrideProductions/GMUart-Bluetooth/blob/main/Images/DLC.jpg?raw=true" />
</p>

<!-- Repo Stats -->
<img align="center" src="https://img.shields.io/github/commit-activity/m/CrashOverrideProductions/GMUart-Bluetooth"> <img align="center" src="https://img.shields.io/github/last-commit/CrashOverrideProductions/GMUart-Bluetooth"> <img align="center" src="https://img.shields.io/github/languages/code-size/CrashOverrideProductions/GMUart-Bluetooth"> <img align="center" src="https://img.shields.io/github/directory-file-count/CrashOverrideProductions/GMUart-Bluetooth">

<!-- Other Intro -->
### What is a ALDL
Assembly Line Diagnostic Link or ALDL is a proprietary on-board diagnostics system developed by General Motors before the standardization of OBD-2. It was previously called Assembly Line Communications Link or ALCL. The two terms are used interchangeably.

This system was only vaguely standardized and suffered from the fact that specifications for the communications link varied from one model to the next. ALDL was largely used by manufacturers for diagnostics at their dealerships and official maintenance facilities. The connector is usually located under the dash on the driver's side of left-hand drive (LHD) vehicles, though this location was not standardized.

The earliest implementations of ALDL were unidirectional and transmitted serial data at 160 baud using PWM. Some 160 baud models constantly transmitted sensor data on startup, while others started transmitting data when placed in diagnostic mode with a resistor connected to the ALDL port.

Later versions were bidirectional and operated at a much faster (but incredibly slow compared to today's standards) rate of 8192 baud. Implementations using the 8192 baud rate were primarily request-driven, meaning that the main diagnostic data was not transmitted until a request was made. Some idle data transmission of trivial parameters, however, existed in many vehicles. Bidirectional communication also allowed many other functions to be performed via ALDL, such as actuator tests, parameter overrides, and in some cases even reprogramming of the ECU itself. Multiple devices could be placed on the ALDL data line for primitive networking and communication. Many later 8192 baud vehicles, for example, had airbag control, ABS, and even climate control units sending data on the same serial bus.

In both versions, ALDL data is sent in a format unique to the model of ECU in the vehicle with little standardization between models, so a proper definition of the data is required to interpret it. Most professional scan tools require a large database of vehicle definitions.

The signaling of ALDL is similar to the RS-232 serial data standard; differing in the voltages used to denote logical one (usually 0 V DC) and logical zero (either +5 V DC or +12 V DC), and that unlike RS-232, both transmit and receive functions are on the same conductor. Schematics are available on the internet for devices that can be used to convert the ALDL voltages to those of the RS-232 standard, allowing the raw data to be read with a computer having a serial port and the proper software.
<!-- Repo Intro -->
### Details
The goal of this project is to establish reliable and consistant ALDL Communication via Bluetooth using a "Mico Computing Board" such as an ESP32

<!-- To Do List -->
### Project To Do List
- [ ] More to add as I think of it
- [ ] List Items Here

### Repo To Do List
- [ ] More to add as i think of it


<!-- Licencing Always at the Bottom -->
### Licencing <img alt="" align="right" src="https://img.shields.io/badge/Licence-CC--BY--NC--SA--4.0-informational?style=flat&logo=Creative%20Commons&logoColor=white&color=EF9421" />

**Creative Commons: Attribution - NonCommercial - ShareAlike 4.0 International (CC BY-NC-SA 4.0)**

**You are free to:**
**Share** — copy and redistribute the material in any medium or format
**Adapt** — remix, transform, and build upon the material

**Under the following terms:**
**Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.

**NonCommercial** — You may not use the material for commercial purposes.

**ShareAlike** — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.

No additional restrictions — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.
