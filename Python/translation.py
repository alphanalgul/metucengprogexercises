sequence = "CGTCGGCCAGCAUGCAGGCCTGGCTGAGGCGTGAGTGTCCTCATTAACGTAGAA"

def translation(seq):
  seq = seq.upper()

  seq = seq.replace("T","U")

  amino_acids = ""
  start_index = seq.find("AUG")

  if start_index == -1:
      print("No start codon found!")
      return

  for i in range(start_index,len(seq),3):

    codon = seq[i:i+3]

    #Phenylalanine (Phe, F)
    if codon == "UUU" or codon == "UUC":
        amino_acids = amino_acids + " Phe"

    #Leucine (Leu, L)
    elif codon == "UUA" or codon == "UUG" or codon == "CUU" or codon == "CUC" or codon == "CUA"  or codon == "CUG":
        amino_acids = amino_acids + " Leu"

    #Isoleucine (Ile, I)
    elif codon == "AUU" or codon == "AUC" or codon == "AUA":
        amino_acids = amino_acids + " Ile"

    #Methionine (Met, M) — Start codon
    elif codon == "AUG":
        amino_acids = amino_acids + " Met"

    #Valine (Val, V)
    elif codon == "GUU" or codon == "GUC" or codon == "GUA" or codon == "GUG":
        amino_acids = amino_acids + " Val"

    #Serine (Ser, S)
    elif codon == "UCU" or codon == "UCC" or codon == "UCA" or codon == "UCG" or codon == "AGU" or codon == "AGC":
        amino_acids = amino_acids + " Ser"

    #Proline(Pro, P)
    elif codon == "CCU" or codon == "CCC" or codon == "CCA" or codon == "CCG":
        amino_acids = amino_acids + " Pro"

    #Threonine (Thr, T)
    elif codon == "ACU" or codon == "ACC" or codon == "ACA" or codon == "ACG":
        amino_acids = amino_acids + " Thr"

    #Alanine (Ala, A)
    elif codon == "GCU" or codon == "GCC" or codon == "GCA" or codon == "GCG":
        amino_acids = amino_acids + " Ala"

    #Tyrosine(Tyr, Y)
    elif codon == "UAU" or codon == "UAC":
        amino_acids = amino_acids + " Tyr"

    #Histidine (His, H)
    elif codon == "CAU" or codon == "CAC":
        amino_acids = amino_acids + " His"

    #Glutamine (Gln, Q)
    elif codon == "CAA" or  codon == "CAG":
        amino_acids = amino_acids + " Gln"

    #Asparagine (Asn, N)
    elif codon == "AAU" or codon == "AAC":
        amino_acids = amino_acids + " Asparagine"

    #Lysine (Lys, K)
    elif codon == "AAA" or codon == "AAG":
        amino_acids = amino_acids + " Lys"

    #Aspartic acid (Asp, D)
    elif codon == "GAU" or codon == "GAC":
        amino_acids = amino_acids + " Asp"

    #Glutamic acid (Glu, E)
    elif codon == "GAA" or codon == "GAG":
        amino_acids = amino_acids + " Glu"

    #Cysteine (Cys, C)
    elif codon == "UGU" or codon == "UGC":
        amino_acids = amino_acids + " Cys"

    #Tryptophan (Trp, W)
    elif codon == "UGG":
        amino_acids = amino_acids + " Trp"

    #Arginine (Arg, R)
    elif codon == "CGU" or codon ==  "CGC" or codon == "CGA" or codon == "CGG" or codon == "AGA" or codon == "AGG":
        amino_acids = amino_acids + " Arg"

    #Glycine (Gly, G)
    elif codon == "GGU" or codon == "GGC" or codon == "GGA" or codon == "GGG":
        amino_acids = amino_acids + " Gly"

    #Stop codons
    elif codon == "UAA" or codon == "UAG" or codon == "UGA":
        break

    elif len(codon) < 3:
        continue

    else:
        print("Invalid Sequence!No amino acid found!")
        continue

  print(amino_acids)

translation(sequence)
