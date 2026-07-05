-- Define Cube and Cylinder types with polymorphic fields
data Cube a = Cube { sidelength :: a } deriving (Show, Eq, Ord)
data Cylinder a = Cylinder { radius :: a, height :: a } deriving (Show, Eq, Ord)

-- ThreeDShapes will just use the Cube and Cylinder types as constructors
data ThreeDShapes a = CubeShape (Cube a) | CylinderShape (Cylinder a) deriving (Show, Eq, Ord)

-- Volume function for Cube and Cylinder with polymorphic type a
volume :: (Num a) => ThreeDShapes a -> a --(Num a):type constraint that accepts both int and float, 
volume (CubeShape (Cube sidelength)) = sidelength^3  -- Volume of the cube
volume (CylinderShape (Cylinder radius height)) = 3 * (radius^2) * height  -- Volume of the cylinder

-- Area function for Cube and Cylinder with polymorphic type a
area :: (Num a) => ThreeDShapes a -> a
area (CubeShape (Cube sidelength)) = 6 * sidelength^2  -- Surface area of the cube
area (CylinderShape (Cylinder radius height)) = 2 * 3 * radius * height + 2 * 3 * radius^2  -- Surface area of the cylinder
