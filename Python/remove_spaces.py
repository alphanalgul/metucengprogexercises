
sequence = " A B C D  E F   G  Z"

def remove_spaces(sequence):
    no_space_sequence = ""
    for char in sequence:
        if char == " ":
            continue
        else:
            no_space_sequence = no_space_sequence + char


    return no_space_sequence

no_spaces = remove_spaces(sequence)
print(no_spaces)

#or more simply no_spaces = sequence.replace(" ", "")