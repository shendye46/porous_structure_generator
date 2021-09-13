
from .point3D import Point3D



class atom(Point3D):
    id:int
    radius:float
    def __init__(self, x, y, z, radius,id):
        super().__init__(x, y, z)
        self.radius = radius
        self.id = id
    def __repr__(self) -> str:
        return "{},{},{},{},{}".format(self.id,self.x,self.y,self.z,self.radius)
    
from .utils import euclideanDistance
class Pores:
    p_atom:atom
    diameter:float
    def __init__(self,atom,diameter) -> None:
        self.p_atom = atom
        self.diameter = diameter
    
    def __repr__(self) -> str:
        return self.p_atom.__repr__()
    def contains(self,atom:atom)->bool:
        return euclideanDistance(self.p_atom,atom)<=((self.diameter/2)+atom.radius)
