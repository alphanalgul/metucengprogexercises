-- Define a simple Person data type
data Person = Person { name :: String, age :: Int }

-- Make Person an instance of Eq to support equality checks
instance Eq Person where
    (Person name1 age1) == (Person name2 age2) = (name1 == name2) && (age1 == age2)
    (Person name1 age1) /= (Person name2 age2) = not ((name1 == name2) && (age1 == age2))

-- Make Person an instance of Ord to support ordering comparisons
instance Ord Person where
    -- Compare based on age first, if ages are the same, compare by name
    compare (Person name1 age1) (Person name2 age2)
        | age1 < age2  = LT  -- If the first person is younger
        | age1 > age2  = GT  -- If the first person is older
        | name1 < name2 = LT  -- If ages are the same, compare names lexicographically
        | name1 > name2 = GT
        | otherwise     = EQ  -- If both age and name are the same

-- Function to check if one person is older than another
isOlderThan :: Person -> Person -> Bool
isOlderThan p1 p2 = p1 > p2  -- Uses the '>' operator from Ord
