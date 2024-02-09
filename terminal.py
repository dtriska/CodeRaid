import sys
import time

def type_text(text, delay=0.05):
    for char in text:
        sys.stdout.write(char)
        sys.stdout.flush()
        time.sleep(delay)

def main():
    message = "Hello! This is a simulated real-time typing."
    type_text(message)
    print("\n")

if __name__ == "__main__":
    main()
