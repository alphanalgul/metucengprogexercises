gradeletter :: Int -> String
gradeletter x 
  | x >= 90 = "You passed the course with AA, Congrats!"
  | x >= 85 = "You passed the course with BA, Congrats!"
  | x >= 80 = "You passed the course with BB, Congrats!"
  | x >= 75 = "You passed the course with CB"
  | x >= 70 = "You passed the course with CC"
  | x >= 65 = "You passed the course with DC"
  | x >= 60 = "You passed the course with DD"
  | x >= 50 = "You failed the course with FD, Damn you!"
  | otherwise = "You failed the course with FF, You suck!"