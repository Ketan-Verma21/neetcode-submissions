class Pet:
    def __init__(self, name: str):
        self.name = name
        self.hunger = 5

    def feed(self):
        # TODO: Implement this method
        # It should decrease the pet's hunger by 1
        # and print a message about feeding the pet
        self.hunger-=1
        print(self.name+" has been fed.")
        print(self.name+"'s hunger level: "+str(self.hunger))
        pass

# Create a pet
my_pet = Pet("Fluffy")
my_pet.feed()
my_pet.feed()
my_pet.feed()
# TODO: Feed the pet three times
