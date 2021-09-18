import fire
from src.box import Box


def main(dimension=50, radius=2):
    b = Box(dimension,dimension,dimension)
    b.fillatoms(radius)
    
    b.fillPores()
    modified_atoms = b.removeAtomsFromPores();
    count_of_atoms = len(modified_atoms)
    
    header_atoms = r"""{}
xyz file written from pySIMM system module""".format(count_of_atoms,-dimension//2,dimension//2,-dimension//2,dimension//2,-dimension//2,dimension//2)
    print(header_atoms)
    for atom in modified_atoms:
        print(atom)
if __name__=="__main__":
    fire.Fire(main)