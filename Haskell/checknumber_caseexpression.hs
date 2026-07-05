checknumber :: Int -> String
checknumber x = case x of
  x | x > 0 -> "Positive"
  x | x < 0 -> "Negative"
  _         -> "Zero"