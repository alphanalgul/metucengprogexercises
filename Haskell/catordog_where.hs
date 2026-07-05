catordog :: String -> String
catordog x = "I love " ++ identifyAnimal x
  where 
    identifyAnimal "cat" = "cats"
    identifyAnimal "dog" = "dogs"
    identifyAnimal _ = "all animals"
