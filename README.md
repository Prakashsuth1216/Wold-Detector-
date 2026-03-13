# Human Detector & Global Trace System (Simulation)

> **⚠️ DISCLAIMER: THIS PROJECT IS A SIMULATION ONLY.**
>
> This software is created strictly for **educational purposes** and to demonstrate basic C programming concepts (structures, loops, randomization).
>
> *   **It does NOT connect to any real satellites.**
> *   **It does NOT scan real IP addresses.**
> *   **It does NOT access any global databases or telecom networks.**
> *   **All data displayed (names, locations, IPs, carriers) is randomly generated.**
>
> Use this tool responsibly. It is a "train" project designed for learning and entertainment.

## Overview

This is a console-based C program that simulates advanced surveillance and tracking tools often seen in movies or cybersecurity demonstrations. It mimics the behavior of tools like **Nmap** and **Truecaller** to provide a fun, interactive experience.

## Features

### 1. Global Identity Scan (Nmap Style)
*   Simulates scanning a "Global Neural Network" for a specific person's name.
*   Displays a progress bar and "discovers" matches in various countries.
*   Generates fake IP addresses, match percentages, and location data.

### 2. MSISDN Number Trace (Truecaller Style)
*   Accepts a mobile number input (e.g., +919876543210).
*   Simulates "pinging gateways" across different continents (North America, Asia, Europe, etc.).
*   **Result**: Either finds a "Registered Owner" with fake details (Name, Carrier, Profession) or reports the number as "UNALLOCATED/VOID" if not found in the simulated database.

## How to Run

1.  Compile the C code:
    ```bash
    gcc humanDetector.c -o humanDetector
    ```
2.  Run the executable:
    ```bash
    ./humanDetector
    ```
3.  Follow the on-screen prompts to select a mode and enter data.

## License

This project is open-source and intended for learning. Feel free to modify and experiment with the code!
