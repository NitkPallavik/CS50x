import cs50

while True:
        print ("Enter dollar amount:  ", end="")
        change = cs50.get_float()
        if change > 0:
            break
    change = round(change,2)
    change = change*100
    count=0
    while (change > 0):
        if change >= 25:
            change -= 25
            count += 1
        elif change >= 10:
            change -= 10
            count += 1
        elif change >= 5:
            change -= 5
            count += 1
        elif change >= 1:
            change -= 1
            count += 1

    print ("count:  ", count)  

    break



"""import cs50

print("O hai ! ",end="")
    while True:
       print("How much change is owed?")   
       change = cs50.get_float()
       if change > 0: 
         break
   
    count = 0

   # if change <= 0.009:
       change = round(change * 100)

    while (change > 0):
        if change >= 25:
            change -= 25
            count += 1
            
        elif change >= 10:
            change -= 10
            count += 1
        elif change >= 5:
            change -= 5
            count += 1
        elif change >= 1:
            change -= 1
            count += 1

    print ("count:  ", count)  

    break

"""