import random
import datetime

# List of all 88 constellations recognized by the IAU
constellations = [
    "Andromeda", "Antlia", "Apus", "Aquarius", "Aquila", "Ara", "Aries", "Auriga", 
    "Boötes", "Caelum", "Camelopardalis", "Cancer", "Canes Venatici", "Canis Major", 
    "Canis Minor", "Capricornus", "Carina", "Cassiopeia", "Centaurus", "Cepheus", 
    "Cetus", "Chamaeleon", "Circinus", "Columba", "Coma Berenices", "Corona Australis", 
    "Corona Borealis", "Corvus", "Crater", "Crux", "Cygnus", "Delphinus", "Dorado", 
    "Draco", "Equuleus", "Eridanus", "Fornax", "Gemini", "Grus", "Hercules", 
    "Horologium", "Hydra", "Hydrus", "Indus", "Lacerta", "Leo", "Leo Minor", 
    "Lepus", "Libra", "Lupus", "Lynx", "Lyra", "Mensa", "Microscopium", 
    "Monoceros", "Musca", "Norma", "Octans", "Ophiuchus", "Orion", "Pavo", 
    "Pegasus", "Perseus", "Phoenix", "Pictor", "Pisces", "Piscis Austrinus", 
    "Puppis", "Pyxis", "Reticulum", "Sagitta", "Sagittarius", "Scorpius", "Sculptor", 
    "Scutum", "Serpens", "Sextans", "Taurus", "Telescopium", "Triangulum", 
    "Triangulum Australe", "Tucana", "Ursa Major", "Ursa Minor", "Vela", "Virgo", 
    "Volans", "Vulpecula"
]

# Function to generate random date between 2010 and 2013
def generate_random_date():
    start_date = datetime.datetime(2010, 11, 1)
    end_date = datetime.datetime(2010, 11, 30)
    delta = end_date - start_date
    random_days = random.randint(0, delta.days)
    random_date = start_date + datetime.timedelta(days=random_days)
    return random_date.strftime("%Y-%m-%d")

# Function to generate random password
def generate_random_password(length=8):
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+"
    password = ''.join(random.choice(characters) for i in range(length))
    return password

# Generate logs
with open("logs.txt", "w") as f:
    for _ in range(921):
        date = generate_random_date()
        constellation = random.choice(constellations)
        password = generate_random_password()
        log = f"{date}, {constellation}, {password}\n"
        f.write(log)
