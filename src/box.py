import copy
from .atom import Pores, atom
import matplotlib.pyplot as plt
import numpy as np
import time

from .utils import areColliding, euclideanDistance, truncate

class Box:
    min_x:float
    max_x:float
    min_y:float
    max_y:float
    min_z:float
    max_z:float
    atomlist:list=[]
    porelist:list=[]
    def __init__(self,x,y,z) -> None:
        self.min_x = int(-x/2)
        self.max_x = int(x/2)
        self.min_y = int(-y/2)
        self.max_y = int(y/2)
        self.min_z = int(-z/2)
        self.max_z = int(z/2)
    
    def fillatoms(self,radius):
       local_id = 0
       for x in range(self.min_x,self.max_x,radius):
           for y in range(self.min_y,self.max_y,radius):
               for z in range(self.min_z,self.max_z,radius):
                   local_id+=1
                   self.atomlist.append(atom(x,y,z,radius=radius,id=local_id))
    

    def fillPores(self,number_of_distinct_radii=3,sigma=3,mean=15):
        poredict = self.createPoresMapping(number_of_distinct_radii=3,sigma=3,mean=15)
        id=0
        prev_radii = None
        max_time_allowed = 100
        for diameter in poredict.keys():
            for i in range(poredict[diameter]):
                itr = 0
                itr_now = 0
                radius = truncate(diameter/2,2)
                while (itr_now - itr < max_time_allowed):
                    itr_now+=1
                    x_min, x_max = self.min_x+radius, self.max_x-radius
                    y_min, y_max = self.min_y+radius, self.max_y-radius
                    z_min, z_max = self.min_z+radius, self.max_z-radius
                    x,y,z = truncate(np.random.uniform(x_min,x_max),2), truncate(np.random.uniform(y_min,y_max),2), truncate(np.random.uniform(z_min,z_max),2)
                    
                    temp_atom = atom(x,y,z,radius,None)
                    if(len(self.porelist)==0 or all([areColliding(temp_atom,i.p_atom) for i in self.porelist])):
                        id+=1
                        temp_atom.id = id
                        p = Pores(temp_atom,diameter)
                        # print(p)
                        self.porelist.append(p)
                        break
            
    
    def removeAtomsFromPores(self):
        copy_atoms = copy.deepcopy(self.atomlist)
        atoms_to_be_removed = []
        for i in range(len(self.porelist)):
            for j in range(len(self.atomlist)):
                if self.porelist[i].contains(self.atomlist[j]):
                    if self.atomlist[j] not in atoms_to_be_removed:
                        atoms_to_be_removed.append(self.atomlist[j])
        
        for atom in atoms_to_be_removed:
            copy_atoms.remove(atom)

        return copy_atoms
        
        
    
    def createPoresMapping(self,number_of_distinct_radii=6,sigma=3,mean=15):
        if (mean<self.max_x/5):
            mean = self.max_x/5
        pore_mapping ={}
        s = np.random.normal(mean,sigma,100)
        count,bins, _ = plt.hist(s,10,density=True)
        if number_of_distinct_radii>10:
            number_of_distinct_radii=10
        else:
            starting_index = int(np.argmax(count) - np.floor(number_of_distinct_radii/2))
            ending_index =  int(np.argmax(count) + np.floor(number_of_distinct_radii/2)) + 1

        for i in range(starting_index,ending_index,1):
            pore_mapping[truncate(bins[i],2)] = int(np.floor(count[i]*100))
        return pore_mapping





        
        
        


    