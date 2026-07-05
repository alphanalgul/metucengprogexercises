sequence = "ataacgtggatgcta"
def complement_sequence(seq,comp_seq):
    sequence = sequence.upper()
    complement_sequence = ""
    for char in sequence:
        if char == 'A':  
            complement_sequence = complement_sequence + "T"
        elif char == 'T':  
            complement_sequence = complement_sequence + "A"
        elif char == 'G':  
            complement_sequence = complement_sequence + "C"
        elif char == 'C':  
            complement_sequence = complement_sequence + "G"
        elif char == " ": 
            continue
        else: 
            print("Invalid Base!")
            continue
    return complement_sequence

complemented_sequence = complement_sequence(sequence,complemented_sequence)

print(sequence)
print(complemented_sequence)