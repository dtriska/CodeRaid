import sys
import time

def type_text(text, delay=0.05):
    for char in text:
        sys.stdout.write(char)
        sys.stdout.flush()
        time.sleep(delay)

def main():
    message = "Dr. Alexander Grey, stumbled upon a groundbreaking discovery that could potentially save humanity from an unprecedented crisis. However, before he could unveil his findings to the world, he mysteriously vanished, leaving behind a series of encrypted messages and intricate puzzles."
    message += "Unknown to the rest of the world, Dr. Grey had developed a potent virus capable of eradicating entire populations within days. Fearing the misuse of his creation, he devised a plan to safeguard humanity: The Antidote Formula."
    message += "Now, it's up to you and your partner, elite agents of the Global Defense Initiative, to unravel Dr. Grey's enigmatic clues, navigate through his elaborate puzzles, and ultimately synthesize the antidote chemistry hidden within his laboratory. Time is of the essence as the virus spreads rapidly, threatening to plunge the world into chaos.\n"

    message += "Agents, I am Omega, your trusted companion on this mission. Crafted by Dr. Alexander Grey, I'll guide you through his lab's challenges. Together, we'll decipher clues, evade traps, and uncover the antidote. With me by your side, victory is within reach. Let's save humanity."
    type_text(message)
    print("\n")

if __name__ == "__main__":
    main()
