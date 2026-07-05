-- A simple data type for demonstration
data Person = Person { name :: String, age :: Int }

-- Make Person an instance of Eq so we can compare two Person values
instance Eq Person where
    (Person name1 age1) == (Person name2 age2) = (name1 == name2) && (age1 == age2)
    (Person name1 age1) /= (Person name2 age2) = not ((name1 == name2) && (age1 == age2))

-- Function to check if two people are the same
areEqual :: Person -> Person -> Bool
areEqual p1 p2 = p1 == p2
