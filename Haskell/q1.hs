data Cube = Cube { sidelength :: Int} deriving (Show,Eq,Ord)
data Cylinder = Cylinder { radius :: Int , height :: Int} deriving (Show,Eq,Ord)
data ThreeDShapes = CubeShape Cube | CylinderShape Cylinder deriving (Show,Eq,Ord)

area :: ThreeDShapes -> Int
area (CubeShape (Cube sidelength)) = 6 * sidelength^2
area (CylinderShape (Cylinder radius height)) = 2 * 3 * radius * height + 2 * 3 * radius

volume :: ThreeDShapes -> Int
volume (CubeShape (Cube sidelength)) = sidelength^3
volume (CylinderShape(Cylinder radius height)) = 3 * radius^2 * height