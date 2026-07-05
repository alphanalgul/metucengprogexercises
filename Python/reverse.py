sequence = "ataacgtggatgcta"
sequence = sequence.upper()
reversed_sequence = ""
def reverse_sequence(seq,reverse_seq):
    for char in seq:
        reverse_seq = char + reverse_seq
    return reverse_seq

reversed_sequence = reverse_sequence(sequence,reversed_sequence)

print(sequence)
print(reversed_sequence)

