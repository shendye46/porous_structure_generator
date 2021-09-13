import math
import copy
from .atom import atom

def truncate(number, digits) -> float:
    stepper = 10.0 ** digits    
    return math.trunc(stepper * number) / stepper

def euclideanDistance(atomA:atom, atomB:atom)->float:
    return math.sqrt(math.pow((atomA.x - atomB.x),2)+math.pow((atomA.y - atomB.y),2)+math.pow((atomA.z - atomB.z),2))

def areColliding(atomA:atom, atomB:atom)->bool:
    return euclideanDistance(atomA,atomB)<(atomA.radius+atomB.radius)