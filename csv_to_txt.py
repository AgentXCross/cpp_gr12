with open("merged_gdp_data.csv", "r") as csv_file, open("merged_gdp_data.txt", "w") as txt_file:
    for line in csv_file:
        txt_file.write(line.replace(",", " "))