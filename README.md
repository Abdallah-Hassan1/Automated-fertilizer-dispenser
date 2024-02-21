## Automated Fertilizer Dispenser Converted to Watering System

### Understanding the Code:

1. **Initialization:**

   - The code commences by setting up required libraries and components.
   - It establishes communication with the temperature sensor and the serial monitor.
   - Additionally, it attaches and positions the servo motor to its initial state.

2. **Execution Process:**

   - The code operates in a continuous loop, executing the following actions:
     - Requesting temperature readings from the temperature sensor.
     - Reading moisture levels from the soil moisture sensor.
     - Acquiring water levels from the water level sensor.
     - Based on the sensor data and predefined conditions, it adjusts the servo motor's position to regulate water dispensing.
     - Finally, it outputs sensor readings and servo motor positions to the serial monitor for monitoring and debugging purposes.

3. **Sensor Data Interpretation:**

   - The code interprets sensor data according to predefined thresholds and conditions:

     - pH sensor readings determine the acidity(14-7) or alkalinity(7-0) of water, with values ranging from 0 to 14.
       When the pH value dips below seven, the water starts to become more acidic. Any number above seven equates to more alkaline.
     - Water level sensors discern liquid levels in a fixed container that is too high or too low. According to the method of measuring the liquid level, categorized as either contact or non-contact types.
     - Soil moisture sensors ascertain soil moisture levels, classifying them as disconnected or not in the soil(above 1000), dry(1000-600), humid(600-370), or submerged(less than 370).

4. **Servo Motor Control:**

   - The MoveServo function governs the servo motor's rotation, controlled by the desired degree provided as an argument.
   - It gradually rotates the servo motor to the specified degree using a for loop, regulating the speed of rotation with delays.

### Utilizing the Project:

1. **Hardware Setup:**

   - Connect the temperature sensor, soil moisture sensor, water level sensor, and servo motor to the Arduino board based on the specified pin configurations.

   ![image](https://github.com/Abdallah-Hassan1/Automated-fertilizer-dispenser/assets/64805908/1757bf3f-62c5-4ab6-894d-1cb5ccef5fc3)


2. **Software Setup:**

   - To upload the provided Arduino code to the Arduino board, follow these steps:

   1. Download the project code from the provided [GitHub repository](https://github.com/Abdallah-Hassan1/Automated-fertilizer-dispenser).

   2. Launch Arduino IDE:

   - If you haven't installed the Arduino IDE yet, you can download it from the official Arduino website and follow the installation instructions. Alternatively, if you're using Windows OS, you can also find it in the Microsoft Store.

   3. Connect Arduino Board:

   - Plug your Arduino board into your computer using a USB cable. Ensure that the connection is secure and that your computer recognizes the board.

   4. Select Board and Port:

   - Within the Arduino IDE, navigate to the _Tools_ menu.
   - Under the _Board_ submenu, choose the appropriate Arduino board model you're working with (e.g., Arduino Uno, Arduino Mega).
   - Next, under the _Port_ submenu, select the serial port to which your Arduino board is connected. On Windows, it's typically listed as COMx, while on macOS, it's usually displayed as /dev/cu.usbmodemXXXX.

   5. Open Code File:

   - Open the provided Arduino code file (.ino file) in the Arduino IDE. You can do this by locating the file on your computer and double-clicking it, or simply drag and drop the file into the Arduino IDE window.

   6. Upload Code:

   - Once you've verified that the code doesn't contain any errors, you can proceed to upload it to the Arduino board.
   - Click on the "Upload" button within the Arduino IDE. During the upload process, you may see status messages in the console indicating the progress of the upload.

   7. Verify Operation:

   - Check the serial monitor within the Arduino IDE to ensure that the sensor values are changing as expected. This step helps confirm that the code is functioning correctly and interacting with the connected sensors appropriately.

3. **Setting Up Local Database:**

   - To enhance visual representation of sensor data and gain immediate insights into soil conditions, utilize an Excel database sheet with the following steps:

   1. Begin by creating a new Excel sheet file locally on the desktop where you're connecting the Arduino.
   2. If the Data Streamer feature isn't visible, follow these steps:

      1. Navigate to _File_ > _Options_ > _Add-ins_.
      2. Under the _Manage_ selector, choose _COM Add-ins_, then click _Apply_.
      3. Ensure the _Microsoft Data Streamer For Excel_ option is selected in the COM Add-ins pop-up, then click _OK_.
      4. You may need to refresh the file, close, and reopen it to activate the Data Streamer tab.
      5. Once activated, the Data Streamer tab should be accessible.

   3. Connect your Arduino device to the laptop.
   4. Within the Data Streamer tab, click on the _Advanced_ button, then select _Settings_.
   5. Confirm that the COM Port and Baud Rate match those of the connected Arduino.
   6. To begin receiving data, click on _Connect a Device_, choose the correct port, and click on _Start Data_ to initiate data transmission from the connected Arduino.
   7. Now, sensor data will be visible in Excel, allowing you to represent it graphically by following these steps:

      1. Select the desired data for graphical representation, including columns and rows.
      2. Click on _Insert_, then choose the desired graph type for visualization purposes.

4. **Operation:**

   - Power on the Arduino board and monitor sensor readings via the serial monitor or the excel sheet .
   - Place the system in the desired location for plant monitoring and watering.
   - Observe temperature, moisture, and water level readings on the serial monitor.
   - Adjust the servo motor's rotation based on sensor readings to control watering.

5. **Maintenance:**

   - Regularly inspect sensor connections and ensure their functionality.
   - Calibrate sensors if necessary for accuracy.
   - Monitor system performance and adjust watering parameters as required based on plant growth and environmental changes.

6. **Troubleshooting:**

   - Refer to the serial monitor for error messages or unexpected readings.
   - Ensure hardware connections are secure.
   - Consult the code for troubleshooting specific functionalities or conditions.
