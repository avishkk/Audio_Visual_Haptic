import serial
# Open the serial port
port = serial.Serial('COM4', 9600)  # Replace with the appropriate port and baud rate
while True:
    # Read input from the keyboard
    data = input("Enter a value: ")

    # Send the data to the serial port
    port.write(data.encode())

    # Check if the input value is 0
    if data == '0':
        break

    # Wait for a response from the serial monitor
    response = port.readline().decode().strip()

    # Print the response
    print("Received:", response)

# Close the serial port
port.close()
