import serial
import argparse

class Arduino:
    def __init__(self, port, boundrate = 9600):
        self.port = port
        self.boundrate = boundrate
        self.serial = serial.Serial(port, boundrate)

    def write(self, part_name, value):
        if value not in[0, 1]:
            raise ValueError("Value must be 0 or 1")
        if part_name not in ["b", "e", "n", "l", "r"]:
            raise ValueError("Part name must be led or buzzer")
        self.serial.write(f"{part_name}{value}\n".encode())

    def __del__(self):
        self.serial.close()

if __name__ == "__main__":
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("--port", type=str, required=True)
    args = arg_parser.parse_args()
    arduino = Arduino(args.port)
    while True:
        part_name = input("Enter part name: ")
        value = int(input("Enter value: "))
        arduino.write(part_name, value)
