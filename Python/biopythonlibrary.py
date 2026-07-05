from Bio.Seq import Seq #to use the biopython library

#defining a sequence
my_seq = Seq( "ATAGAGAAATCGCTGC" )
print(my_seq)

#finding the complement of a sequence
print(my_seq.complement())

#finding the reverse complement of a sequence
print(my_seq.reverse_complement())

#finding the reverse complement of a dna sequence, then converting it into rna
print(my_seq.complement_rna())

#converting a dna sequence to a rna sequence
print(my_seq.transcribe())

#converting rna sequence into corresponding amino acids
print(my_seq.translate())