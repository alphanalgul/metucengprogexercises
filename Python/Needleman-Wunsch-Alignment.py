import numpy as np # to create an initial matrix of 0s
from Bio.Align import substitution_matrices # to import BLOSUM62 table

def needleman_wunsch(seq1,seq2,gap_score):
    #Defining the number of rows and columns needed for Needleman-Wunsch
    columns = len(seq1) + 1
    rows = len(seq2) + 1
    print("Number of Columns: ",columns, "Number of Rows: ",rows)

    #loading BLOSUM62 table
    blosum2 = substitution_matrices.load('BLOSUM62')

    #creating the initial matrix of 0s
    m = np.zeros((rows, columns), dtype=int)

    print(m)

    #initialize the first column
    for i in range(rows):
        m[i][0] = gap_score * i

    #initialize the first row
    for i in range(columns):
        m[0][i] = gap_score * i

    print(m)


    #nested loop to go through every index of the matrix
    for i in range(1,rows):
        for j in range(1,columns):
           #Base Needleman-Wunsch Formula:
           #m[i,j] = max( m[i-1,j-1] + blosum[seq2[i-1],seq1[j-1]],
           #m[i-1,j] + g , m[i,j-1] + g)
           eq1 = m[i-1,j-1] + blosum2[seq2[i-1],seq1[j-1]]
           eq2 = m[i-1,j] + gap_score
           eq3 = m[i,j-1] + gap_score
           m[i,j] = max(0,eq1,eq2,eq3)

    print(m)

    #Finding the alignments and the alignment scores
    aligned_seq1 = ""
    aligned_seq2 = ""
    i = rows - 1
    j = columns - 1

    #repeat until both sequences are fully traced
    while i > 0 or j > 0:
        current = m[i,j]

        #Diagonal case no gaps
        if i > 0 and j > 0 and current == m[i-1,j-1] + blosum2[seq2[i-1], seq1[j-1]]:
            aligned_seq1 = seq1[j-1] + aligned_seq1
            aligned_seq2 = seq2[i-1] + aligned_seq2
            i -= 1; j -= 1

        #Up case gap in seq1
        elif i > 0 and current == m[i-1,j] + gap_score:
            aligned_seq1 = '-' + aligned_seq1
            aligned_seq2 = seq2[i-1] + aligned_seq2
            i -= 1

        #Left case gap in seq2
        else:
            aligned_seq1 = seq1[j-1] + aligned_seq1
            aligned_seq2 = '-' + aligned_seq2
            j -= 1

    #printing the results
    print("Alignment 1:", aligned_seq1)
    print("Alignment 2:", aligned_seq2)
    print("Alignment Score:",m[-1,-1])#alignment score is the last element in the matrix
needleman_wunsch('AATCGTTCGAC','AACGTTTTCGGCA', -8)

