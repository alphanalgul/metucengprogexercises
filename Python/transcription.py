sequence = "ataacgtggatgcta"
sequence = sequence.upper()
transcription_sequence = ""
for char in sequence:
    if char == 'T':
        transcription_sequence = transcription_sequence + "U"
    else:
        transcription_sequence = transcription_sequence + char
   
print(sequence)
print(transcription_sequence)