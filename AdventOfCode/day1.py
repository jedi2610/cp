def calcFuel(mass):
    
    fuelofModule = 0 
    while True: 
        mass = (mass//3) - 2
        if (mass > 0):
            fuelofModule += mass 
        else:
            return fuelofModule

def main():

    file = open("input.txt", "r")
    masses  = file.readlines()
    fuel = 0
    for mass in masses:
        fuel += calcFuel(int(mass))
    print(fuel)

if __name__ == "__main__":
    main()
