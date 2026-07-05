salary :: String -> Int -> Int -> Double
salary empclass rt ot =
   if empclass == "Class 1" then 10* fromIntegral rt
   else if empclass == "Class 2" || empclass == "Class 3" then  7 * fromIntegral rt + 1.5 * fromIntegral ot
   else if empclass == "Class 4" then 5 * fromIntegral rt + 2 * fromIntegral ot
   else 0.0