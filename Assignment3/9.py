str = input("Enter a string: ")

abbr = "".join(word[0].upper() for word in str.split())
print("Abbreviation:", abbr)
