sequence = "ataacgtggatgcta"
def reverse_complement(seq):

    sequence = sequence.upper()
    reverse_complement_sequence = ""
    for char in sequence:
        if char == 'A':  
            reverse_complement_sequence = "T" + reverse_complement_sequence
        elif char == 'T':  
            reverse_complement_sequence = "A" + reverse_complement_sequence
        elif char == 'G':  
            reverse_complement_sequence = "C" + reverse_complement_sequence
        elif char == 'C':  
            reverse_complement_sequence = "G" + reverse_complement_sequence 
        elif char == " ": 
            continue
        else: 
            print("Invalid Base!")
            continue
    return reverse_complement_sequence

complemented_reversed_sequence = reverse_complement(sequence)

print(sequence)
print(complemented_reversed_sequence)