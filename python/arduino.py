import serial
import time
import argparse

class Arduino:
    def __init__(self, port, boundrate = 9600):
        self.port = port
        self.boundrate = boundrate
        self.serial = serial.Serial(port, boundrate)

    def write(self, part_name, value):
        if value not in[0, 1]:
            print("Value must be 0 or 1")
        if part_name not in ["b", "e", "n", "l", "r"]:
            print("Part name must be led or buzzer")
        self.serial.write(f"{part_name}{value}\n".encode())

    def __del__(self):
        self.serial.close()

if __name__ == "__main__":
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("--port", type=str, required=True)
    args = arg_parser.parse_args()
    arduino = Arduino(args.port)
    input("start moving")
    time.sleep(1)
    arduino.write("b", 1)
    time.sleep(1)
    arduino.write("e", 1)
    time.sleep(1)
    arduino.write("n", 1)
    time.sleep(1)
    arduino.write("l", 1)
    time.sleep(1)
    input("press enter to stop eye blow")
    arduino.write("b", 0)
    input("press enter to stop eye")
    arduino.write("e", 0)
    input("press enter to stop nose")
    arduino.write("n", 0)
    input("press enter to stop mouth")
    arduino.write("l", 0)
    # while True:
    #     part_name = input("Enter part name: ")
    #     value = int(input("Enter value: "))
    #     arduino.write(part_name, value)
