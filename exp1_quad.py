size=3
clientList=[None]*size

def addClient():
    id=int(input("\nenter client id: "))
    name=input("enter name: ")
    tel=input("enter telephone number: ")
    clientDetails=[id,name,tel]

    index=id%size
    i=1
    while(clientList[index] is not None):
        index=(index+i**2)%size
        i+=1
    clientList[index]=clientDetails
    print("Client added successfully!!")
    
    
def searchClient():
    id=int(input("enter client id: "))
    index=id%size
    i=1
    while clientList[index] is not None:
        if clientList[index][0]==id:
            print("client ",clientList[index][1],"found at index ",index)
            return
        index=(index+i**2)%size
        i+=1
    print("client not found!!")

def deleteClient():
    id=int(input("enter client id: "))
    index=id%size

    i=1
    while clientList[index] is not None:
        if clientList[index][0]==id:
            clientList[index]=None
            print("client deleted successfully!!")
            return
        index=(index+i**2)%size
        i+=1
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
