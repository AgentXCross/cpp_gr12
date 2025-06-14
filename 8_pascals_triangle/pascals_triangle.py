import time

def main():
    rows = int(input("Enter the number of Pascal Triangle rows--> "))

    start_time = time.time()
    #Initialize a 2000x2000 list with all 0s
    triangle = [[0 for _ in range(2000)] for _ in range(2000)]

    for i in range(rows + 1):
        triangle[i][0] = 1  #First element 1
        triangle[i][i] = 1  #Last element 1

        for j in range(1, i):
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]  #Add elements above to the left and directly above

    #Print Pascal's Triangle
    for k in range(rows):
        for n in range(rows):
            if triangle[k][n] != 0:
                print(triangle[k][n], end=" ")
        print()
    end_time = time.time()
    execution_time = end_time - start_time
    print(execution_time)

if __name__ == "__main__":
    main()