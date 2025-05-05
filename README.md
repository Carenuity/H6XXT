# Carenuity IoT Solutions Guide

Welcome to the Carenuity IoT Solutions Guide! This repository provides a step-by-step guide to building IoT projects using the Carenuity Solutions Builder platform (https://solutions.carenuity.com). With this guide, you’ll learn how to purchase supported boards, sensors, and actuators from https://www.chipglobe.shop, set up your hardware, and install pre-built firmware for various IoT applications in just a few minutes.

The Carenuity platform simplifies IoT development by offering free, installable solutions for applications like environmental monitoring, smart home automation, and more. We support a range of ecosystems, including CloudFree, IoT AppStory, Home Assistant, and Matter, with firmware tailored for each. This README is designed for beginners and experienced developers alike, assuming you’re starting with minimal hardware knowledge.

## Table of Contents
- [Carenuity IoT Solutions Guide](#carenuity-iot-solutions-guide)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Supported Boards](#supported-boards)
  - [Prerequisites](#prerequisites)
  - [Step-by-Step Guide](#step-by-step-guide)
    - [Step 1: Purchase Hardware](#step-1-purchase-hardware)
    - [Step 2: Assemble Your Hardware](#step-2-assemble-your-hardware)
    - [Step 3: Install Firmware](#step-3-install-firmware)
  - [Available Solutions](#available-solutions)
  - [Troubleshooting](#troubleshooting)
  - [Contributing](#contributing)
  - [License](#license)

## Overview

The Carenuity Solutions Builder platform enables you to create IoT solutions quickly by combining a supported microcontroller, sensor, and actuator on a Triple-Adapter. The platform supports a variety of applications, such as:

- **Environmental Monitoring**: Measure temperature, humidity, air quality, etc.
- **Smart Home Automation**: Control lights, thermostats, or other devices.
- **Health and Wellness**: Monitor conditions impacting health, like air quality.
- **Agricultural Sensing**: Track soil moisture or environmental conditions.

All solutions are listed on https://solutions.carenuity.com and can be installed for free using a web browser, with no additional software required. We provide firmware for multiple ecosystems, including:

- **CloudFree**: Standalone IoT applications without internet dependency.
- **IoT AppStory**: A platform for managing and updating IoT applications.
- **Home Assistant**: Integration with the popular open-source home automation system.
- **Matter**: Future-proof standard for smart home interoperability.

This guide focuses on using supported boards (C3-Mini, D1-Mini, ESP32, ESP32-CAM) available from Chipglobe.

## Supported Boards

The following microcontroller boards are officially supported by Carenuity’s Solutions Builder platform:

| Board       | Description                                              | Key Features                                      |
|-------------|----------------------------------------------------------|--------------------------------------------------|
| **C3-Mini** | Compact IoT board based on ESP32-C3, recommended for future-proofing (Matter standard). | Wi-Fi, Bluetooth LE, RISC-V CPU, 4MB flash.     |
| **D1-Mini** | Popular board based on ESP8266, widely used for IoT projects. | Wi-Fi, compact design, Arduino-compatible.      |
| **ESP32**   | Versatile board with dual-core processor, ideal for complex projects. | Wi-Fi, Bluetooth, dual-core, Arduino support.   |
| **ESP32-CAM** | ESP32-based board with camera module for vision-based IoT applications. | Wi-Fi, Bluetooth, OV2640 camera, SD card slot.  |

**Note**: The Raspberry Pi Pico is not supported by Carenuity’s platform. Ensure you purchase one of the above boards for compatibility.

## Prerequisites

Before you begin, ensure you have:

- A computer with a modern web browser (e.g., Chrome, Firefox, Edge).
- A USB cable compatible with your chosen board (e.g., USB-C for C3-Mini, Micro-USB for D1-Mini).
- A supported microcontroller board, sensor, and actuator (purchased from Chipglobe).
- A Carenuity Triple-Adapter (optional, for easy sensor/actuator connection).
- A stable internet connection for accessing https://solutions.carenuity.com.

No additional software installation is required, as firmware is flashed via the web-based Solutions Builder.

## Step-by-Step Guide

### Step 1: Purchase Hardware

1. **Visit Chipglobe WebShop**: Go to https://www.chipglobe.shop to purchase your hardware.
2. **Select a Supported Board**:
   - Choose from C3-Mini, D1-Mini, ESP32, or ESP32-CAM based on your project needs.
   - Example: For environmental monitoring, the C3-Mini is recommended for its compact size and future-proofing with the Matter standard.
3. **Choose Sensors and Actuators**:
   - Sensors: Select from supported sensors like BME680 (air quality), AHT20 (temperature/humidity), or BMP280 (pressure). Check compatibility on https://solutions.carenuity.com.
   - Actuators: Options include relays (for controlling devices), WS2812B RGB LEDs (for visual feedback), or small motors (for automation).
   - Example: For air quality monitoring, pair a BME680 sensor with a C3-Mini and an OLED display.
4. **Optional Accessories**:
   - Purchase a Carenuity Triple-Adapter for easy plug-and-play assembly.
   - Consider a 3D-printed enclosure for a professional finish.
5. **Checkout**: Ensure all parts are added to your cart. Chipglobe offers assortment boxes or individual spare parts for convenience.

**Tip**: If you’re unsure which components to buy, refer to the project examples on https://solutions.carenuity.com or contact Chipglobe support.

### Step 2: Assemble Your Hardware

1. **Unpack Components**:
   - For C3-Mini, snap off the metal frame as per the provided tutorial (included with purchase).
   - Verify you have your board, sensor, actuator, and Triple-Adapter (if purchased).
2. **Connect Components**:
   - **Using Triple-Adapter**: Attach the microcontroller, sensor, and actuator to the Triple-Adapter as shown in the illustrations on https://solutions.carenuity.com. No soldering is required.
   - **Manual Connection**: If not using a Triple-Adapter, connect the sensor and actuator to the board’s GPIO pins using jumper wires. Refer to the sensor/actuator datasheet for pin assignments.
   - Example: For a C3-Mini with AHT20 sensor and OLED display, connect via I2C pins (SDA, SCL).
3. **Power the Board**:
   - Connect the board to your computer via a USB cable for firmware flashing.
   - After flashing, you can power the device with a phone charger (5V USB) for standalone operation.

**Note**: Ensure proper connections to avoid damaging components. Double-check pin assignments if wiring manually.

### Step 3: Install Firmware

1. **Access Solutions Builder**:
   - Open a web browser and navigate to https://solutions.carenuity.com.
   - Browse the list of available solutions (e.g., WLED for LED control, GPIO-Viewer for testing, or ESPHome for Home Assistant).
2. **Select Your Solution**:
   - Choose the solution that matches your project and ecosystem (e.g., “Environmental Monitoring” with Home Assistant or Matter).
   - Each solution page includes a QR code or link for firmware installation.
3. **Flash the Firmware**:
   - Connect your board to your computer via USB.
   - For **C3-Mini**:
     - Hold the BOOT button.
     - Press and release the RST button while holding BOOT.
     - Start the web-based flashing process on https://solutions.carenuity.com.
     - Release the BOOT button once flashing begins.
   - For other boards (D1-Mini, ESP32, ESP32-CAM):
     - Follow the specific flashing instructions provided on the solution page (typically simpler, no button combination required).
   - The web-based flasher will automatically upload the firmware to your board.
4. **Verify Installation**:
   - Once flashing is complete, the board will restart and run the installed application.
   - Check the solution’s output (e.g., sensor data on an OLED display, LED activity, or cloud connectivity).

**Tip**: To change sensors or ecosystems, repeat the flashing process with the new sensor connected and select the corresponding solution.

## Available Solutions

All solutions are listed on https://solutions.carenuity.com and are free to install. Popular applications include:

- **WLED**: Control WS2812B RGB LEDs for vibrant lighting projects (CloudFree, IoT AppStory).
- **GPIO-Viewer**: Test and debug GPIO pins on your board (CloudFree).
- **ESPHome**: Integrate with Home Assistant for smart home automation (Home Assistant ecosystem).
- **CloudFree**: Run standalone IoT applications without internet dependency.
- **IoT AppStory**: Manage and update IoT applications seamlessly.
- **Matter/ESPZero**: Future-proof solutions compatible with the Matter standard.
- **Home Assistant**: Open-source home automation integration for advanced control.

Each solution supports one or more ecosystems (CloudFree, IoT AppStory, Home Assistant, Matter), ensuring flexibility for your project needs. Compatible ecosystems like Alexa and Google Home are also supported for select solutions.

## Troubleshooting

- **Board Not Detected**:
  - Ensure the USB cable is data-capable (not charge-only).
  - Verify the correct board is selected in the web flasher.
  - For C3-Mini, double-check the BOOT/RST button sequence.
- **Sensor/Actuator Not Working**:
  - Confirm connections match the Triple-Adapter or datasheet pinout.
  - Check if the selected solution supports your sensor/actuator.
- **Flashing Fails**:
  - Try a different USB port or cable.
  - Ensure no other software is accessing the board’s serial port.
- **Ecosystem Integration Issues**:
  - Verify the solution matches your chosen ecosystem (e.g., Home Assistant or Matter).
  - Check https://solutions.carenuity.com for ecosystem-specific setup guides.
- **Need Spare Parts**:
  - Purchase additional sensors, actuators, or boards from https://www.chipglobe.shop.
- **Further Assistance**:
  - Visit https://carenuity.com for tutorials and FAQs.
  - Contact Chipglobe support via https://www.chipglobe.shop for hardware issues.

## Contributing

We welcome contributions to improve this guide or add new solutions! To contribute:

1. Fork this repository.
2. Create a new branch (`git checkout -b feature/your-feature`).
3. Make changes and commit (`git commit -m "Add your feature"`).
4. Push to your branch (`git push origin feature/your-feature`).
5. Open a pull request with a detailed description.

Please ensure your contributions align with Carenuity’s supported boards and ecosystems.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

**Happy Building!**

With Carenuity and Chipglobe, you’re just minutes away from creating your own IoT solutions across CloudFree, IoT AppStory, Home Assistant, and Matter ecosystems. For more inspiration, explore the full range of solutions at https://solutions.carenuity.com.

---

For technical support, email us at **team@carenuity.com**.
