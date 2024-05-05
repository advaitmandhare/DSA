size=3
clientList=[None]*size

def addClient():
    id=int(input("\nenter client id: "))
    name=input("enter name: ")
    tel=input("enter telephone number: ")
    clientDetails=[id,name,tel]

    index=id%size

    for i in range(size):
        if (clientList[index]==None):
            clientList[index]=clientDetails
            print("Client added successfully!!")
            break
        else:    
            index=(index+1)%size
    
def searchClient():
    id=int(input("enter client id: "))
    index=id%size

    for i in range(size):
        if clientList[index][0]==id:
            print("client ",clientList[index][1],"found at index ",index)
            break
        index=(index+1)%size
    else:
        print("client not found!!")

def deleteClient():
    id=int(input("enter client id: "))
    index=id%size

    for i in range(size):
        if clientList[index][0]==id:
            clientList[index]=None
            print("client deleted successfully!!")
            break
        index=(index+1)%size
    else:
        print("client not found!!")

print("\nAdd Clients:")
addClient()
addClient()
addClient()

print("\nSearch Client: ")
searchClient()

print("\nDelete Client: ")
deleteClient()

print("\nSearch Client: ")
searchClient()
