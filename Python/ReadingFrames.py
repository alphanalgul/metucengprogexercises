
sequence = "CGTCGGCCAGCCAGGCCTGGCTGAGGCGTGAGTGTCCTCATCGTAGAATC"

def complement(seq):
    seq = seq.upper()

    complement_sequence = ""

    for char in seq:
        if char == 'A':
            complement_sequence = complement_sequence + "T"
        elif char == 'T':
            complement_sequence = complement_sequence + "A"
        elif char == 'G':
            complement_sequence = complement_sequence + "C"
        elif char == 'C':
            complement_sequence = complement_sequence + "G"
        else:
            print("Invalid base! Skipping..")
            continue

    return complement_sequence

def find_reading_frames(seq):
    seq = seq.upper()

    total_frames = []#all 6 frames for a given sequence

    rna_seq = seq.replace("T","U")

    reverse_sequence = seq[::-1]#to reverse the string
    reverse_complement_sequence = complement(reverse_sequence)
    reverse_complement_sequence_rna = reverse_complement_sequence.replace("T","U")

    for j in range(3):
        frame_5_to_3 = []  # 3 frames from the first strand(5' to 3')
        frame_3_to_5 = []  # 3 frames from the second strand(3' to 5')

        # dividing 5' to 3' strand into codons
        for i in range (j,len(rna_seq),3):
            codon = rna_seq[i:i+3]
            if len(codon) == 3:
             frame_5_to_3.append(codon)

        #dividing 3' to 5' strand into codons
        for i in range (j,len(reverse_complement_sequence_rna),3):
          codon = reverse_complement_sequence_rna[i:i+3]
          if len(codon) == 3:
            frame_3_to_5.append(codon)

        total_frames.append(frame_5_to_3)
        total_frames.append(frame_3_to_5)

    total_frames = [total_frames[0] , total_frames[2] , total_frames[4] , total_frames[1] , total_frames[3]
                    , total_frames[5] ]
    print(total_frames)
find_reading_frames(sequence)
